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
#include "toml.hpp"
#include "SHA512.h"

static void login () {
	std::string usr;
	std::cout << "\tLogin: ";
	getline(std::cin, usr);
	auto data = toml::parse("nc-bin/cfg.toml");
	if (data.contains(usr)) {
		std::string pass;
		std::cout << "\tPassword: ";
		getline(std::cin, pass);
		SHA512 sha512;
		if (toml::find<std::string>(data, usr, "pass_hash") == sha512.hash(pass))
			std::cout << "Welcome, " << usr << "!" << std::endl;
		else
			std::cout << "Incorrect password" << std::endl;
			exit(1);
	}
}
static void reg () {
	std::cout << "Register:" << std::endl;
	std::string usr;
	std::cout << "\tLogin: ";
	getline(std::cin, usr);
	auto data = toml::parse("nc-bin/cfg.toml");
	if (!data.contains(usr)) {
		std::string pass;
		std::cout << "\tPassword: ";
		getline(std::cin, pass);
		SHA512 sha512;
		pass = sha512.hash(pass);
		data[usr]["pass_hash"] = pass;
		std::ofstream cfg;
		cfg.open("nc-bin/cfg.toml");
		cfg << data;
		cfg.close();
	}
	else {
		std::cout << "This user already exests!" <<std::endl;
		exit(1);
	}
}
