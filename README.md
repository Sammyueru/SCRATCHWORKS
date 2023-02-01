# SCRATCHWORKS
Steamworks for Scratch

# Prerequisites:
- [TurboWarp](https://github.com/TurboWarp/desktop) (Scratch Mod)
- [Visual Studio 2022](https://visualstudio.microsoft.com/vs/)
- [Fetch Extension](https://extensions.turbowarp.org/fetch.js)

# Setup
1. Open the 'SRC.sln' file with Visual Studio 2022
2. Open the 'MAIN.cpp' file inside Visual Studio 2022
3. Change the 480 in 'int steamAppID = 480; //Change to your Steam App ID' to your Steam App ID
4. Change the SpaceWar in 'std::string scratchExe = "SpaceWar"; //Change to your Scratch Executable Name (WITHOUT FILE EXTENSION)' to your TurboWarp executable name WITHOUT THE '.EXE'
5. Click 'Build->Build SRC'
6. Copy 'Release/steam_api.dll' and 'Release/ScratchworksLauncher.exe' into your root packaged TurboWarp folder and open ScratchworksLauncher.exe

# Initialize:
![alt text](README_STUFF/init.png)
