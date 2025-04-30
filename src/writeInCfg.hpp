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
SHA512 sha512;

static void defaultCfg(std::ofstream &cfg) {
	cfg << "pc=\"pc\"" << std::endl <<
	"repo=\"https://raw.githubusercontent.com/nachosteam/ncrepo/refs/heads/main\"" << std::endl << std::endl <<
	"[root]" << std::endl <<
	"pass_hash=\"\"" << std::endl;
}

static void addUser() {
	auto data = toml::parse("nc-bin/cfg.toml");
	if (mainInfo.currentUsr == "root") {
		std::string username;
		std::cout << "|Enter username: ";
		getline(std::cin, username);
		if (!data.contains(username)) {
			std::string password;
			std::cout << "|Enter password: ";
			getline(std::cin, password);
        		data[username]["pass_hash"] = sha512.hash(password);
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
static void rmUser() {
        auto data = toml::parse("nc-bin/cfg.toml");
        if (mainInfo.currentUsr == "root") {
                std::string username;
                std::cout << "|Enter username: ";
                getline(std::cin, username);
                if (data.contains(username)) {
			data.as_table().erase(username);
                        std::ofstream cfg("nc-bin/cfg.toml");
                        cfg << data;
			cfg.close();
                }
                else
                        std::cout << "This user does not exists." << std::endl;
        }
        else {
                std::cout << "You are not rooted." << std::endl;
        }
}
static void passwd() {
	auto data = toml::parse("nc-bin/cfg.toml");
	std::string newpass;
	std::cout << "\tEnter new password: ";
	getline(std::cin, newpass);
	data[mainInfo.currentUsr]["pass_hash"] = sha512.hash(newpass);
	std::ofstream cfg("nc-bin/cfg.toml");
	cfg << data;
	cfg.close();
}
