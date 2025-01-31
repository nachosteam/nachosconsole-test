#pragma once
#include <iostream>
#include "toml.hpp"

static std::wstring getData(std::string dataName) {
	auto data = toml::parse("nc-bin/cfg.toml");
	std::string str = toml::find<std::string>(data, dataName);
	return std::wstring(str.begin(), str.end());
}

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

static std::wstring getPc() {
	return getData("pc");
}
static std::wstring getUsername() {
	return getData("username");
}
static std::wstring getPassHash() {
	return getData("pass_hash");
}