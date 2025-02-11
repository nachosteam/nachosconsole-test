#include <iostream>
#include "toml.hpp"
#include "SHA512.h"

static void login () {
	std::string usr;
	std::cout << "\tLogin: ";
	getline(std::cin, usr);
	auto data = toml::parse("nc-bin/ctg.toml");
	if (data.contains(usr)) {
		std::cout << "da" << std::endl;
	}
}
static void reg () {
	
}
