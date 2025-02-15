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

#pragma once
#include <iostream>
#include "toml.hpp"
#include "SHA512.h"
#include "sessionData.hpp"

static void defaultCfg(std::ofstream &cfg) {
	cfg << "pc=\"pc\"" << std::endl <<
	"repos=[\"https://raw.githubusercontent.com/nachosteam/ncrepo\"]" << std::endl << std::endl <<
	"[root]" << std::endl <<
	"pass_hash=\"\"" << std::endl;
}

static void addUser() {
	auto data = toml::parse("nc-bin/cfg.toml");
	if (mainInfo.currentUsr == "root") {
		std::wstring username;
		std::wcout << "|Enter username: ";
		getline(std::wcin, username);
		std::string usr_str(username.begin(), username.end());
		if (!data.contains(usr_str)) {
			std::wstring password;
			std::wcout << "|Enter password: ";
			getline(std::wcin, password);
			SHA512 sha512;
        		data[usr_str]["pass_hash"] = sha512.hash(std::string(password.begin(), password.end()));
			std::ofstream cfg("nc-bin/cfg.toml");
			cfg << data;
		}
		else
			std::cout << "This user already exists." << std::endl;
	}
	else {
		std::cout << "You are not rooted." << std::endl;
	}
}
