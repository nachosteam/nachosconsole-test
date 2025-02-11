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

static void defaultCfg(std::ofstream &cfg) {
	cfg << "pc=\"pc\"" << std::endl <<
	"repos=[\"https://raw.githubusercontent.com/nachosteam/ncrepo\"]" << std::endl << std::endl <<
	"[root]" << std::endl <<
	"pass_hash=\"\"" << std::endl;
}

static void addUser(std::ofstream &cfg, std::string username, std::string password) {
	SHA512 sha512;
	cfg << "[" << username << "]" << std::endl <<
	"pass_hash=\"" << sha512.hash(password) << "\"" << std::endl;
}
