# AmateurHour

A one-stop-shop platform that helps newcomers break into hobbies by providing equipment guides, local resources, and community connections.

## Problem

Breaking into a new hobby can be overwhelming. Beginners struggle to find the right equipment, locate nearby groups, understand licensing requirements, and get trustworthy information. Without a clear entry point, many abandon hobbies before they’ve truly begun.

## Target Users

1. Newcomers exploring a hobby for the first time  
2. Intermediate enthusiasts seeking community and skill development  
3. Any hobbyist looking to discover better gear, training, or local meetups  

## Description

AmateurHour is a web and mobile application that streamlines the “getting started” process for any hobby. Users create or update a profile listing their interests and experience level, then immediately access:

- **Gear recommendations** tailored to beginners, intermediates, or experts  
- **Local group listings** and events, automatically discovered via our crawler  
- **In-app training modules** and checklists to guide skill development  
- **Community chat rooms** seeded with AI-driven conversation prompts  

By aggregating equipment, social connections, and learning resources in one place, AmateurHour removes the friction of “where do I start?”

## Core Ideas

1. **App Interface**  
   - Onboarding captures interests and experience levels (optional to edit later)  
   - Gear section categorizes equipment by skill tier and shows local retailers  
   - Groups section highlights nearby clubs, meetups, and classes  
   - “Interests” feed for news, events, and suggested challenges  

2. **Backend Services**  
   - User management, preferences, and secure data storage  
   - Chat server for real-time community discussions  
   - API layer to surface crawler results and gear metadata  

3. **Web Crawler**  
   - Periodically scrapes the web for hobby-specific groups, forums, and retailers  
   - Classifies gear (beginner vs. recommended) using heuristic rules and user feedback  
   - Feeds fresh data into the app without manual curation  

4. **Chat AI**  
   - LLM assistant (e.g., via ChatGPT API) to guide newcomers through features  
   - Automated ice-breakers in new chat rooms to spur conversation  
   - Contextual help: “Which canoe should I start with?”, “How do I get my first fishing license?”  

## Key Benefits

- **Lower barrier to entry** for any hobby by centralizing all starter needs  
- **Faster skill progression** through curated gear lists and training checklists  
- **Community support** to motivate and guide users at every level  
- **Reduced decision fatigue** by recommending vetted equipment and trusted groups  

## Challenges

- **Reliable crawling & parsing**: extracting structured group and gear info from heterogeneous websites  
- **Data privacy & security**: handling personal information and chat data responsibly (recommend leveraging mature frameworks rather than building from scratch)  
- **Scalability of chat**: ensuring real-time messaging remains performant as the user base grows  
- **Content quality control**: preventing outdated or incorrect listings from persisting  

## Useful Technologies

- **LLM APIs** (e.g., OpenAI’s ChatGPT) for conversational guidance  
- **React Native** or **Flutter** for cross-platform mobile development  
- **Node.js** / **Django** backend with a real-time chat service (e.g., Socket.IO, Firebase)  
- **Web crawling** with **Selenium**, **Playwright**, or lightweight **Scrapy** spiders  
- **OAuth** / **Auth0** for secure user authentication and PII protection  

## Future Extensions

- **Hobby-specific modules** (e.g., in-depth tutorials for photography, woodworking, climbing)  
- **Partnership integrations** with gear brands and local retailers for discounts  
- **Gamification**: badges, challenges, and leaderboards to boost engagement  
- **AR feature**: visualize gear in your environment before you buy  

## Test Audience

- Friends who have recently taken up a new hobby (e.g., first-time archers, home cooks)  
- Local community organizers and instructors  
- Online hobby forums willing to pilot community features  

## Competition (Optional)

- Meetup.com (group discovery)  
- Reddit and Discord hobby servers (community)  
- Gear review sites (equipment guidance)  
