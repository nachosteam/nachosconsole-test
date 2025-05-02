#include <iostream>
#include <filesystem>
#include "../toml.hpp"

static void remove(std::string package) {
	if (std::filesystem::exists("nc-bin/"+package)) {
		try {
			std::filesystem::remove_all("nc-bin/"+package);
		}
		catch (std::string error_message) {
			std::cout << "Error: " << error_message << std::endl;
		}
	}
	else {
		std::cout << "This package is not installed!" << std::endl;
	}
}
