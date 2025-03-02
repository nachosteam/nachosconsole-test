#pragma once
#include <iostream>
#include "toml.hpp"

void help(std::string place) {
	if (place == "default")
		std::cout << "adduser\tadds a new user (root access required)" << std::endl <<
                "rmuser\tdeletes user (root access required)" << std::endl <<
                "passwd\tchanges the password of the current user" << std::endl <<
                "clear\tclears the terminal window" << std::endl <<
                "exit\tstops running NachosConsole" << std::endl;
}
