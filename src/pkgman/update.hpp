#pragma once
#include <iostream>
#include <string>
#include "../toml.hpp"

static void update() {
	try {
		auto data = toml::parse("nc-bin/cfg.toml");
		std::string downloadPkgList = "curl " + data["repo"].as_string() + "/packages.toml -o nc-bin/packages.toml";
		system(downloadPkgList.c_str());
	}
	catch (std::string error_message) {
		std::cout << "Error: " << error_message << std::endl;
	}
}
