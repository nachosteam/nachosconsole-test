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
#include "toml.hpp"
#include "SHA512.h"

static void login () {
	std::string usr;
	std::cout << "\tLogin: ";
	getline(std::cin, usr);
	auto data = toml::parse("nc-bin/cfg.toml");
	if (data.contains(usr)) {
		std::cout << "da" << std::endl;
	}
}
static void reg () {
	
}
