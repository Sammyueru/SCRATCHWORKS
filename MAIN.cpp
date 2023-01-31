/*
THIS PROJECT IS LICENSED UNDER THE MIT LICENSE
FOUND IN THE LICENSE FILE (LICENSE.TXT)
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <steam_api.h>
#include <fstream>
#include <json.hpp>
#include <time.h>
#include <stdio.h>
#include <sstream>
#include <filesystem>

//CHANGE THESE VARIABLES - START
//480 IS THE STEAM ID FOR "SpaceWar"
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
	#include <shlobj.h>
	
#else
	#include <dos.h>
	#include <windows.h>
#endif

using json = nlohmann::json;

/*
std::string remove_hex_zeros_str(std::string str) {
	int i = 0;
	int i1 = 0;
	char *char_str = (char*)str.c_str();
	std::string final_char_str = "";
	while (i < strlen(char_str)) {
		if (char_str[i] != '\0') {
			final_char_str[i1] = char_str[i];
			i1++;
		}
		i++;
	}
	return final_char_str;
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
	if (from.empty()) {
		return;
	}
	std::string wsRet;
	wsRet.reserve(str.length());
	size_t start_pos = 0, pos;
	while ((pos = str.find(from, start_pos)) != std::string::npos) {
		wsRet += str.substr(start_pos, pos - start_pos);
		wsRet += to;
		pos += from.length();
		start_pos = pos;
	}
	wsRet += str.substr(start_pos);
	str.swap(wsRet); // faster than str = wsRet;
}
*/

/*
std::string* split_multistr(std::string str, std::string* token, std::string delims)
{
	int i = 0;
	size_t beg;
	size_t pos = 0;

	while (((beg = str.find_first_not_of(delims, pos)) != std::string::npos) && (i < token->length()))
	{
		pos = str.find_first_of(delims, beg + 1);
		if (beg == 0) {
			token[i] = str.substr(beg, pos - beg);
		}
		else {
			token[i] = str.substr(beg - 1, pos - beg + 1);
		}
		i++;
	}
	*/
	/*
	while ((beg = str.find_first_not_of(delims, pos)) != std::string::npos) {
		pos = str.find_first_of(delims, beg + 1);
		token[i] = str.substr(beg, pos - beg);
		i++;
	}
	*/
/*
	return token;
}
*/

int main() {
	if (SteamAPI_RestartAppIfNecessary(steamAppID)) {
		return 1;
	}
	
	if (!SteamAPI_Init()) {
		printf("[Error]: Steam must be running to play this game (SteamAPI_Init() failed).\n");
		return 1;
	}


	//std::cout << std::filesystem::current_path().c_str() << '\n';
	//std::string scratchworks_api_txt_path = (std::string)(char*)std::filesystem::current_path().c_str() + (char*)"/scratchworks_api.txt";
	//std::cout << scratchworks_api_txt_path;
	std::ofstream steamapi_txt("scratchworks_api.txt", std::ios::out | std::ios::trunc);
	//steamapi_txt.open("scratchworks_api.txt", std::ios::out | std::ios::trunc);

	if (!steamapi_txt.is_open()) {
		return 1;
	}

#if PLATFORM 1
	std::string cloud_vars_path = getenv("APPDATA") + (std::string)"\\" + scratchExe + "\\Local Storage\\leveldb\\000003.LOG";
	//std::cout << cloud_vars_path;
	std::string appExt = ".exe";

	//system(scratchExe.append(appExt).c_str());
#else
	std::string cloud_vars_path = getenv("APPDATA") + (std::string)"\\" + scratchExe + "\\Local Storage\\leveldb\\000003.LOG";
	std::string appExt = ".exe";
	system(scratchExe.append(appExt).c_str());
#endif

	//CSteamID userSteamID = SteamUser()->GetSteamID();

	int running = 1;
	while (running == 1) {
		//std::string *appDataPathStr = (std::string*)"";

#if PLATFORM 1
		Sleep(10); //0.01 Seconds
		//printf("WAITED\n");
		//std::ifstream cloud_vars("resources/app/assets.json"); //CHANGE LOCATION
		std::ifstream cloud_vars(cloud_vars_path, std::ios::binary);
#else
		Sleep(10); //0.01 Seconds
		//std::ifstream cloud_vars("resources/app/assets.json"); //CHANGE LOCATION
		std::ifstream cloud_vars(cloud_vars_path, std::ios::binary);
#endif

		if (cloud_vars.is_open()) {
			//json parse_full = json::parse(cloud_vars);
			//std::string parse_steam_api = parse_full["☁ STEAM_API"];
			
			std::stringstream parseStream;
			parseStream << cloud_vars.rdbuf();
			//std::string parse_full = parseStream.str();

#if PLATFORM 1
			//std::u16string parse_full_16 = (char16_t*)parseStream.str().c_str();
			//parse_full_16.erase(std::remove(parse_full_16.begin(), parse_full_16.end(), '\00'), parse_full_16.end());
			std::string parse_full = parseStream.str();
			parse_full.erase(std::remove(parse_full.begin(), parse_full.end(), '\00'), parse_full.end());
			//std::string parse_full = parseStream.str();
#else

#endif
			
			/*
			cloud_vars.seekg(0, std::ios::end);
			size_t size = (size_t)cloud_vars.tellg();

			//skip BOM
			cloud_vars.seekg(2, std::ios::beg);
			size -= 2;

			std::u16string u16((size / 2) + 1, '\0');
			cloud_vars.read((char*)&u16[0], size);
			*/

			//std::string parse_full = cloud_vars.rdbuf();
			//std::string parse_full{ std::istreambuf_iterator<char>(*cloud_vars), std::istreambuf_iterator<char>() };

			//parse_full.erase(std::remove_if(parse_full.begin(), parse_full.end(), ::isspace), parse_full.end());
			//parse_full.erase(std::remove_if(parse_full.begin(), parse_full.end(), (std::string)"\00"), parse_full.end());
			
			//replaceAll(parse_full, "\00", "");
			//parse_full = remove_hex_zeros_str(parse_full);

			//std::cout << parse_full << '\n';
			//std::cout << parse_full.find("STEAM_API") / sizeof(std::string);
			
			size_t parse_one = parse_full.find("STEAM_API\":\"");
			//size_t parse_one = parse_full.find("STEAM_API");
			//std::cout << parse_one << '\n';
			//std::string parse_one_str = parse_full.substr(parse_one);
			size_t parse_two = parse_full.find("\"}", parse_one);
			//std::cout << (parse_two - (parse_one + 12)) << '\n';
			//std::cout << parse_one_str << '\n';
			std::string parse_steam_api = parse_full.substr(parse_one+12, (parse_two - (parse_one + 12)));
			
			//std::string parse_steam_api = strtok((char*)parse_full.c_str(), "☁& STEAM_API\":\"");
			//std::string parse_steam_api = strtok((char*)parse_full.c_str(), "STEAM_API\":\"");
			//std::stringstream parse_full_stream(parse_full)
			//std::getline(parseStream, parse_steam_api, "STEAM_API\":\"")
			//std::string token_count[2];
			//std::string parse_steam_api = split_multistr(split_multistr(parse_full, token_count, "STEAM_API\":\"")[1], token_count, "\"}")[0];
			//std::istringstream parse_steam_api_stream(parse_steam_api_first);
			//std::string parse_steam_api;
			//std::getline(parse_steam_api_stream, parse_steam_api, '"'); //strtok((char*)parse_steam_api_first.c_str(), "\"}");
			
			//std::cout << parse_steam_api << '\n';
			///*
			int steamapi_txt_change = 0;
			if (parse_steam_api != "0" && parse_steam_api != "") {
				if (parse_steam_api == "INIT")
				{
					steamapi_txt << "0";
					//steamapi_txt.write("0", sizeof("0"));
					//std::cout << "0";
					steamapi_txt_change = 1;
				}
				else if (parse_steam_api == "2") {
					steamapi_txt << "3";
					steamapi_txt_change = 1;
				}
				else if (parse_steam_api == "3") {
					//RETURN STEAM ID
					//steamapi_txt << std::to_string(userSteamID.ConvertToUint64());
					steamapi_txt_change = 1;
				}
				else if (parse_steam_api[0] == '4' && parse_steam_api[1] == '-') {
					//STEAM MATCHMAKING
					if (parse_steam_api[2] == '0') {
						if (parse_steam_api[3] == '0') {
							if (parse_steam_api[4] == '0') {
								if (parse_steam_api[5] == '1') {
									ELobbyType eSteamLobbyType = k_ELobbyTypePrivate;
									int cMaxMembers = 15;

									if (parse_steam_api[6] == '-') {
										if (parse_steam_api[7] == '1') {
											ELobbyType eSteamLobbyType = k_ELobbyTypeFriendsOnly;
										}
										else if (parse_steam_api[7] == '2') {
											ELobbyType eSteamLobbyType = k_ELobbyTypePublic;
										}
										else if (parse_steam_api[7] == '3') {
											ELobbyType eSteamLobbyType = k_ELobbyTypeInvisible;
										}
									}

									if (parse_steam_api.find(' ') != std::string::npos) {
										cMaxMembers = int(strtok((char*)parse_steam_api.c_str(), " "));
									}

									if (SteamMatchmaking()->CreateLobby(eSteamLobbyType, cMaxMembers)) {
										steamapi_txt << "1";
										steamapi_txt_change = 1;
									}
									else {
										steamapi_txt << "0";
										steamapi_txt_change = 1;
									}
								}
							}
						}
					}
				}
				else if (parse_steam_api == "5") {
					//Check to make sure that Scratchworks launcher is still running
					steamapi_txt << "-Z";
					steamapi_txt_change = 1;
				}
			}
			//*/
			if (steamapi_txt_change != 0) {
				steamapi_txt.seekp(0);
				steamapi_txt.flush();
			}
			cloud_vars.close();
		}
	}

	steamapi_txt.close();
	return 0;
}