/*
   Copyright 2025 NachosTeam

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#ifdef __WIN32
	#include <windows.h>
#elif __linux__
	
#endif
#include "toml.hpp"
#include "getFromCfg.hpp"
#include "writeInCfg.hpp"
#include "account.hpp"
extern "C" {

}

int main(int argc, char *argv[]) {
	signIn();
	while (true) {
		std::wcout << getUsername() << L"@" << getPc() << L"$ ";
		std::wstring input;
		std::wstring input_full;
		getline(std::wcin, input);
		input_full = input;
		std::string input_str(input.begin(), input.end());
		std::wistringstream iss(input);
		iss >> input;
		if (input == L"adduser")
			addUser();
		else if (input == L"exit")
			exit(1);
		else if (input == L"passwd")
			passwd();
		else {
			if (!input.empty()) {
				if (std::filesystem::exists(L"nc-bin/"+input)) {
					std::cout << "Test: Exists" << std::endl;
				}
				else {
					std::wcout << "Unknown command: " << input << std::endl;
				}
			}
		}
	}
	
	/* auto data = toml::parse("test.toml");
	int title = toml::find<int>(data, "main", "owners");
	std::cout << "Enter: ";
	std::string pizda;
	getline(std::cin, pizda);
	
	data["testing"]["pizdaV1"] = pizda;
	std::ofstream file("test.toml");
	file << data;
	file.close(); */
}
