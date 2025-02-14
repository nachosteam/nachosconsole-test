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
#include "writeInCfg.hpp"
#include "getFromCfg.hpp"
#include "login.hpp"
#include "toml.hpp"

static void checkExistsCFG() {
	if (!std::filesystem::exists("nc-bin/cfg.toml")) {
		if (!std::filesystem::exists("nc-bin"))
			std::filesystem::create_directory("nc-bin");
		std::ofstream cfg;
		cfg.open("nc-bin/cfg.toml");
		if (cfg.is_open()) {
			defaultCfg(cfg); // для предотвращения ошибок с случае выхода из программы во время первоначальной настройки
			cfg.close();
			reg();
		}
		else {
			std::cout << "Can't open the file!" << std::endl;
			exit(42); // 42 БРАТУХА КЕМЕРОВСКАЯ ОБЛАСТЬ 42 42 42 42 42 42 42 42
		}
	}
}
static void signIn() {
	checkExistsCFG();
}
