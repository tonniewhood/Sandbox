
# FireForm

A data-driven, user first product designed to provide shooters with reliable information to improve their shooting skills.

## Problem

Many shooters (myself included) struggle to gain useful feedback when training with their firearms. With expensive coaching prices and limited experts available, improving shooting form can be difficult. Additionally, even with shooting partners and coaches, getting useful data can be difficult and expensive with rising ammo prices.

## Target Users

1. Recreational Shooters
2. Concealed Weapon Carriers
3. LEO and military (SOF?)
4. Competition Shooters

## Description

The FireForm is a training aid designed to provide the user with data on their firing form and characteristics. By providing data about the motion of the barrel, the FireForm is able to inform the user of motion in all 3 directions and how that relates to shooting characteristics such as muzzle rise and trigger jerk. The data can then be used in training exercises (both builtin and user defined) to help the user improve their firing form in both dry and live fire scenarios.

## Core Ideas

The system is designed with 3 core sections in mind.

1. Barrel Attachment
    - This portion houses the accelerometer, microcontroller (ideally will become commercial chip on PCB), battery, and wireless communication system (likely Bluetooth for ease of mobile development).
    - There should be very minimal onboard calculation done. A simple ADC should measure battery voltage, and otherwise, each packet should really just be the accelerometer data. Potentially consider buffered inputs (50 maybe?) to avoid missing inputs and allow for 2-way communication.
    - There should be a way for updates to go to the chip if necessary. I don't suspect they will be often, but to ensure any patches CAN be sent out, two way communication will be important. This helps ensure any bugs can be fixed as they're encounted instead of having users turn in the system altogether. It also helps use update things as flaws are found in any libraries we use to avoid "trusted endpoint" attacks against the user. THE ATTACHMENT SHOULD NOT BE ABLE TO TAKE ANY ACTIONS ON THE APP. To avoid any potential security risks, the attachment should only be able to talk on an open port. No reverse shells here.
    - The housing itself should be simple and lightweight. Anything over 0.1 kg is probably too heavy. It shouldn't significantly affect the user's shooting experience, as that would skew the data. Either a plastic or alumnium housing is best. There is potential for 3D printed housings, though issues of durabiliy and profitability come into question. Regardless, intial models would likely use a 3D printed component.

2. App/UI
    - This is a **VERY** general description of this part of the system. This will contain the ability to run training, view data, and configure the system. It will handle receiving data from the system, and then providing the user with information based on that data. This portion will not actually process the data (that will be the next portion).
    - There should be a section that the user can train from. This will have any saved training drills, the builtin training, and just general zero/calibration info. Training sessions can either be interactive and help the user improve their skills, or just there to record info for later analysis. Interactive training will generally be more stationary, though there could be an option to "network" with other users nearby and have a "coach" run through the process. This would likely be for newer shooters, as more experienced coaches would probably only want the data, not the drill itself.
    - There should be a section where the user can just view recorded data. This could be pushed to the cloud, or saved locally. I like the idea of allowing the user to use the app without making an account, but any sort of long term storage on the cloud for sharing or backups would need an account.
    - There could also be another section that allows the user to plan their training. Instead of launching into a training session, just record and plan what they want to do in a week or some other period.
    - An additional thing that could be useful is both ammo and range finders. So if you're looking for different or cheaper ammo, you could have the app locate that. This may be more useful in an extended version.
    - The app should also provide a "tutorial" that allows the user to find their way around the app. I'd prefer anyone using the app be able to know what the app offers. Maybe also have a virtual assistant (think Siri) that has knowledge about the app and can direct the user around. That way they can ask if the app has a feature, and the assistant can tell them where it is.

3. AI Model
    - The data may prove difficult to classify, especially if the user has several issues to solve. Having an AI (CNN?) process that data and determine what errors the user is making could prove quite useful.
    - This model would be ideally put on device to help speed up calculation. I'd prefer to not have to make a request every time the user wants info. Maybe a reduced model could be onboard, and then a more complex one be hosted allowing for more thorough analysis?
    - This model would also allow for analysis of a training drill and give the user insight into their performance.

## Key Benefits

This system has several benefits over simple, individual training. These include

1. "Outside" feedback to user performance
2. Reduced time to improve performance
3. Reduced likelihood of "training scars"
4. Reduced ammo cost
5. Additional data to assist in training

## Challenges

There will be several challenges associated with making a product of this nature. There include:

1. Reliable data gathering
    - The data needs to be reliable to provide any useful feedback. Making sure to get good hardware is important, but may be expensive too. The data will also need to be gathered at a fast enough rate to be useful, but not so fast as to be overwhelming.
2. Reliable transmission
    - The connection between the attachment and app needs to not drop packets. Making sure that all the data goes through is important. This means that a protocol similar to TCP must be used to ensure that data isn't dropped. This ALSO means that the attachment must have enough storage to handle potentially long (maybe 5 seconds) periods without connection. The connection should also be reliable at distance (though shouldn't need to be more than 30 meters) to ensure good training.
3. Low power consumption
    - Changing batteries often would be INCREDIBLY annoying to an end user. The power consumption needs to remain low so that the user doesn't have to deal with managing the batteries all the time.
4. Weight
    - If the attachment is too heavy, it will provide inaccurate results AND cause users to be unlikely to use it. To keep the product viable, the weight must stay low. It is likely that most of the weight goes into the mounting, which counters the next issue
5. Robust housing
    - If the housing is too fragile, it's possible that any sort of prolonged, or even just higher impact, training will break the system. If it can't withstand at least 100 solid sessions, the housing should be considered "too fragile."
6. Intuitive interface
    - If the data is good but the app makes no sense, no one will want to use it. It's important that even if the app isn't super sexy, it does make sense.
7. Asset not a hinderance
    - If the app gets in the way too much, users will probably be unlikely to use it. It needs to be able to be used by beginners and experienced users alike, meaning there needs to be ways to configure the app to not do too much hand-holding if the user doesn't want it.
8. Security
    - With an outward facing "port," the app needs to be secure enough to not comprimise the user's device. Any information coming in needs to be scrubbed and not allow for any commands (think read only).
9. Cost and Logistics
    - The manufacture and distribution of the system needs to be simple and cheap enough to be viable. I'm not saying that hardware makes things invalid, but it should be considered with an initial startup
10. Don't be annoying
    - I generally despise the tone that modern apps have, so I'd prefer to not do that. Treat the user like an adult and be up front with them. We have a good product, so let's show them not tell them. We should be honest not shady, and treat our customers well. (Not a technical challenge, but still important to me)

## Useful Technologies

- Embedded Development
- AI (DNN more than likely)
- Bluetooth Module (XBee for testing)
- IOS/Andrio Development
- Useful pacakges (Update as necessary)
  - N/A

## Future Extensions

- Laser integration (POA/POI)
  - Camera to view laser POA and then bullet POI
  - Laser Adjustment to show predicted POI

## Test Audience

- Ryan Bones
- Cody Brklasich
- Travis Potter

## Competition [Optional]

