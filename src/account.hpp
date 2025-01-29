#pragma once
#include <iostream>

static void checkCFG() {
	if (!std::filesystem::exists("nc-bin/cfg.toml")) {
		std::ofstream cfg;
		cfg.open("nc-bin/cfg.toml");
		if (cfg.is_open()) {
			//cfg << "" // <-- в "" пометисть данные пользователя
			cfg.close();
		}
		else {
			std::cout << "Can't open the file!" << std::endl;
			return 1;
		}
	}
}