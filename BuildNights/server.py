# import serial
# import asyncio
# import socketio
# from aiohttp import web

# # Set your serial port (check Arduino IDE Tools → Port)
# ser = serial.Serial('/dev/ttyACM0', 115200)

# sio = socketio.AsyncServer(cors_allowed_origins="*")
# app = web.Application()
# sio.attach(app)

# @sio.on('connect')
# def connect(sid, environ):
#     print(f'Client connected: {sid}')

# async def read_serial():
#     while True:
#         try:
#             line = ser.readline().decode().strip()
#             yaw, pitch, roll = map(float, line.split(","))
#             print(f"Yaw: {yaw}, Pitch: {pitch}, Roll: {roll}")
#             await sio.emit('orientation', {'yaw': yaw, 'pitch': pitch, 'roll': roll})
#         except Exception as e:
#             print("Error:", e)
#         await asyncio.sleep(0.01)

# if __name__ == '__main__':
#     loop = asyncio.new_event_loop()
#     asyncio.set_event_loop(loop)
#     loop.create_task(read_serial())
#     web.run_app(app, port=5000)

import serial
import asyncio
import socketio
from aiohttp import web

# 1) non-blocking readline(): use a short timeout
ser = serial.Serial('/dev/ttyACM0', 115200, timeout=0.1)

# 2) Set up Async Socket.IO + aiohttp app
sio = socketio.AsyncServer(cors_allowed_origins="*",
                           async_mode='aiohttp')
app = web.Application()
sio.attach(app)

@sio.event
async def connect(sid, environ):
    print(f"Client connected: {sid}")

@sio.event
async def disconnect(sid):
    print(f"Client disconnected: {sid}")

# 3) Move your serial reader into a coro that yields quickly
async def read_serial():
    print("\033[32mSerial reader started\033[0m")
    while True:
        line = ser.readline().decode(errors='ignore').strip()
        if not line:
            # no data → yield control immediately
            await asyncio.sleep(0.01)
            continue

        try:
            yaw, pitch, roll = map(float, line.split(','))
        except ValueError:
            print("\033[31m[WARN] Could not parse:", repr(line), "\033[0m")
        else:
            print(f"→ YPR = {yaw:.2f},{pitch:.2f},{roll:.2f}")
            # broadcast to all clients
            await sio.emit('orientation',
                           {'yaw': yaw,
                            'pitch': pitch,
                            'roll': roll})
        # small sleep so we don’t spin too hot
        await asyncio.sleep(0.0025)

# 4) Kick off read_serial() on server startup
async def start_background(app):
    # uses the same loop run_app is about to start
    app.loop.create_task(read_serial())

app.on_startup.append(start_background)

# # 5) (Optional) serve a basic index.html
# async def index(request):
#     return web.FileResponse('index.html')

# app.router.add_get('/', index)

if __name__ == '__main__':
    web.run_app(app, port=5000)
