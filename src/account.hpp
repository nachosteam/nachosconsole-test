/*
	MIT License

	Copyright (c) 2025 Nachos Team

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#pragma once
#include <iostream>
#include "writeInCfg.hpp"
#include "getFromCfg.hpp"
#include "toml.hpp"

static void checkExistsCFG() {
	if (!std::filesystem::exists("nc-bin/cfg.toml")) {
		if (!std::filesystem::exists("nc-bin"))
			std::filesystem::create_directory("nc-bin");
		std::ofstream cfg;
		cfg.open("nc-bin/cfg.toml");
		if (cfg.is_open()) {
			defaultCfg(cfg);
			cfg.close();
		}
		else {
			std::cout << "Can't open the file!" << std::endl;
			exit(42); // 42 БРАТУХА КЕМЕРОВСКАЯ ОБЛАСТЬ 42 42 42 42 42 42 42 42
		}
	}
}
static void login() {
	// потом сделаю логин, а пока для мейна вставлю проверку кфг
	checkExistsCFG();
}
