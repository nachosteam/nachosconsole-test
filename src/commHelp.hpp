#pragma once
#include <iostream>
#include "toml.hpp"

void help() {
	auto data = toml::parse("nc-bin/cfg.toml");
        std::string language = toml::find<std::string>(data, "lang");
	if (language == "ru")
		std::cout << "adduser\tдобавляет нового пользователя (из под root аккаунта)" << std::endl <<
                "rmuser\tудаляет пользователя (из под root аккаунта)" << std::endl <<
                "passwd\tизменяет пароль текущего пользователя" << std::endl <<
                "clear\tочищает окно терминала" << std::endl <<
                "exit\tостанавливает выполнение NachosConsole" << std::endl;
	else
		std::cout << "adduser\tadds a new user (root access required)" << std::endl <<
                "rmuser\tdeletes user (root access required)" << std::endl <<
                "passwd\tchanges the password of the current user" << std::endl <<
                "clear\tclears the terminal window" << std::endl <<
                "exit\tstops running NachosConsole" << std::endl;
}
