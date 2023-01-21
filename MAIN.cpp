/*
THIS PROJECT IS LICENSED UNDER THE MIT LICENSE
FOUND IN THE LICENSE FILE
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <steam_api.h>
#include <fstream>
#include <json.hpp>
#include <time.h>

//CHANGE THESE VARIABLES - START
int steamAppID = 480; //Change to your Steam App ID
std::string scratchExe = "SpaceWar"; //Change to your Scratch Executable Name (WITHOUT FILE EXTENSION)

//Platforms:
//1. Windows
//2. Linux (Coming Soon)
//3. Mac (Coming Soon)
#define PLATFORM 1
//CHANGE THESE VARIABLES - END

#if PLATFORM 1
	#include <dos.h>
	#include <windows.h>
	//#include <shlobj.h>
#else
	#include <dos.h>
	#include <windows.h>
#endif

using json = nlohmann::json;

int main() {
	/*
	if (SteamAPI_RestartAppIfNecessary(steamAppID)) {
		return 1;
	}
	
	if (!SteamAPI_Init()) {
		printf("[Error]: Steam must be running to play this game (SteamAPI_Init() failed).\n");
		return 1;
	}
	*/

#if PLATFORM 1
	std::string appExt = ".exe";
	system(scratchExe.append(appExt).c_str());
	std::ifstream cloud_vars("./resources/app/assets.json");
#else
	std::string appExt = ".exe";
	system(scratchExe.append(appExt).c_str());
	std::ifstream cloud_vars("./resources/app/assets.json");
#endif

	std::ofstream steamapi_txt;
	steamapi_txt.open("steamapi.txt", std::ios::out | std::ios::trunc);

	if (!steamapi_txt.is_open()) {
		return 1;
	}

	int running = 1;
	while (running == 1) {
		//std::string *appDataPathStr = (std::string*)"";

#if PLATFORM 1
		Sleep(10); //0.01 Seconds
		//printf("WAITED\n");
	#endif

		json parse_full = json::parse(cloud_vars);
		std::string parse_steam_api = parse_full["☁ STEAM_API"];

		if (parse_steam_api != "0") {
			if (parse_steam_api == "INIT")
			{
				steamapi_txt << "0";
			}
			else if (parse_steam_api == "2") {
				steamapi_txt << "3";
			}
			else if (parse_steam_api == "3") {

			}
		}
	}

	steamapi_txt.close();
	return 0;
}