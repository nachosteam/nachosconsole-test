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
#include "term/termControl.hpp"
#include "term/input.hpp"
#include "getFromCfg.hpp"
#include "writeInCfg.hpp"
#include "account.hpp"
#include "helpCommand.hpp"
#include "about.hpp"
#include "pkgman/getArch.hpp"
#include "pkgman/update.hpp"
#include "pkgman/install.hpp"
#include "pkgman/remove.hpp"
#include "pkgman/startPkg.hpp"
extern "C" {

}

int main(int argc, char *argv[]) {
	signIn();
	enableRawMode();

	std::vector<std::string> history;
	int historyIndex = 0;

	while (true) {
		std::string prompt = getUsername() + "@" + getPc() + "$ ";
		std::string input = readInputWithHistory(prompt, history, historyIndex);
		std::istringstream iss(input);
		std::string command;
		iss >> command;
		if (command == "help")
			help("default");
		else if (command == "about")
			about();
		else if (command == "adduser")
			addUser();
		else if (command == "rmuser")
			rmUser();
		else if (command == "passwd")
			passwd();
		else if (command == "arch")
			std::cout << getArch() << std::endl;
		else if (command == "pkg") {
			std::string parameter;
			iss >> parameter;
			if (parameter == "-i") {
				std::string package;
				iss >> package;
				install(package);
			}
			else if (parameter == "-r") {
				std::string package;
				iss >> package;
				remove(package);
			}
			else if (parameter == "-u")
				update();
			else
				help("pkg");
		}
		else if (command == "clear")
			system("clear");
		else if (command == "exit") {
			disableRawMode();
                        exit(0);
		}
		else {
			if (!command.empty()) {
				if (std::filesystem::exists("nc-bin/"+command)) {
					startPkg(command, input);
				}
				else {
					std::cout << "Unknown command: " << input << std::endl;
				}
			}
		}
	}
}
