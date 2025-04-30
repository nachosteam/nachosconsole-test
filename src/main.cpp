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
#include "toml.hpp"
#include "getFromCfg.hpp"
#include "writeInCfg.hpp"
#include "account.hpp"
#include "commHelp.hpp"
#include "about.hpp"
extern "C" {

}

int main(int argc, char *argv[]) {
	signIn();
	while (true) {
		std::cout << getUsername() << "@" << getPc() << "$ ";
		std::string input;
		std::string input_full;
		getline(std::cin, input);
		input_full = input;
		std::istringstream iss(input);
		iss >> input;
		if (input == "help")
			help("default");
		else if (input == "about")
			about();
		else if (input == "adduser")
			addUser();
		else if (input == "rmuser")
			rmUser();
		else if (input == "passwd")
			passwd();
		else if (input == "clear")
			system("clear");
		else if (input == "exit")
                        exit(1);
		else {
			if (!input.empty()) {
				if (std::filesystem::exists("nc-bin/"+input)) {
					std::cout << "Test: Exists" << std::endl;
				}
				else {
					std::cout << "Unknown command: " << input << std::endl;
				}
			}
		}
	}
}
