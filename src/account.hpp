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
#include "toml.hpp"

static void checkExistsCFG() {
	if (!std::filesystem::exists("nc-bin/cfg.toml")) {
		if (!std::filesystem::exists("nc-bin"))
			std::filesystem::create_directory("nc-bin");
		std::ofstream cfg;
		cfg.open("nc-bin/cfg.toml");
		if (cfg.is_open()) {
			cfg << "pc=\"pc\"" << std::endl <<
			       "username=\"user\"" << std::endl <<
			       "pass_hash=\"3c9909afec25354d551dae21590bb26e38d53f2173b8d3dc3eee4c047e7ab1c1eb8b85103e3be7ba613b31bb5c9c36214dc9f14a42fd7a2fdb84856bca5c44c2\"" << std::endl <<
				   "repos=[\"https://raw.githubusercontent.com/nachosteam/ncrepo\"]";
			cfg.close();
		}
		else {
			std::cout << "Can't open the file!" << std::endl;
			exit(42);
		}
	}
}
