#pragma once
#include <iostream>
#include "toml.hpp"

void help(std::string place) {
	if (place == "default")
		std::cout <<
		"about\tinfo about NachosConsole" << std::endl <<
		"adduser\tadds a new user (root access required)" << std::endl <<
                "rmuser\tdeletes user (root access required)" << std::endl <<
                "passwd\tchanges the password of the current user" << std::endl <<
                "clear\tclears the terminal window" << std::endl <<
                "exit\tstops running NachosConsole" << std::endl;
	else if (place == "pkg")
		std::cout <<
		"-i <package>\tinstall package" << std::endl <<
		"-u\tupdate avalible packages list" << std::endl <<
		"-r <package>\tremove package" << std::endl;
}
