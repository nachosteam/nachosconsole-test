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
#include "sessionData.hpp"
MainInfo mainInfo;

static std::string getPc() {
	auto data = toml::parse("nc-bin/cfg.toml");
	std::string pc = toml::find<std::string>(data, "pc");
        return std::string(pc.begin(), pc.end());
}
static std::string getUsername() {
	std::string cUsr = mainInfo.currentUsr;
	return std::string(cUsr.begin(), cUsr.end());
}
