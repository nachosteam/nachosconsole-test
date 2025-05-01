#include <iostream>
#include "../toml.hpp"

static void startPkg(std::string enteredFirst, std::string input) {
	auto data = toml::parse("nc-bin/" + enteredFirst + "/pkg-info.toml");
	std::string run = "./nc-bin/" + enteredFirst + "/" + data["execute"].as_string() + input.erase(0, enteredFirst.length());
	system(run.c_str());
}
