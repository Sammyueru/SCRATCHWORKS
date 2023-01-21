/*
THIS PROJECT IS LICENSED UNDER THE MIT LICENSE
FOUND IN THE LICENSE FILE
*/
#include <iostream>
#include <string>
#include <steam_api.h>
#include <fstream>
#include <json.hpp>

int steamAppID = 480; //Change to your Steam App ID
std::string scratchExe = "SpaceWar"; //Change to your Scratch Executable Name (WITHOUT FILE EXTENSION)

//Platforms:
//1. Windows
//2. Linux (Coming Soon)
//3. Mac (Coming Soon)
#define PLATFORM 1

#if PLATFORM 1
	//#include <shlobj.h>
#endif

using json = nlohmann::json;

int main() {
	if (SteamAPI_RestartAppIfNecessary(steamAppID)) {
		return 1;
	}

	if (!SteamAPI_Init()) {
		printf("[Error]: Steam must be running to play this game (SteamAPI_Init() failed).\n");
		return 1;
	}

	int running = 1;

#if PLATFORM 1
	std::string appExt = ".exe";
	system(scratchExe.append(appExt).c_str());
	std::ifstream cloud_vars("./resources/app/assets.json");
#else
	std::string appExt = ".exe";
	system(scratchExe.append(appExt).c_str());
	std::ifstream cloud_vars("./resources/app/assets.json");
#endif

	while (running == 1) {
		//std::string *appDataPathStr = (std::string*)"";

/*
#if PLATFORM 1
		
#endif
*/
		
		json data = json::parse(cloud_vars);
	}

	return 0;
}