#pragma once
#include <iostream>
#include <filesystem>
#include "getArch.hpp"
#include "update.hpp"
#include "../toml.hpp"

static void install(std::string package) {
	if (!std::filesystem::exists("nc-bin/packages.toml")) {
		update();
	}
	auto pkgs = toml::parse("nc-bin/packages.toml");
	auto cfg = toml::parse("nc-bin/cfg.toml");
	if (pkgs.contains(package) && isContainYourArch(package)) {
		try {
			std::string archive = package + "-" + pkgs[package]["version"].as_string() + "-" + downloadableArch(package) + ".tar.gz";
			std::string downloadComm = "curl " + cfg["repo"].as_string() + "/" + archive + " -o nc-bin/" + archive;
			std::cout << downloadComm << std::endl;
			system(downloadComm.c_str());

			std::string unzip = "tar -xvzf nc-bin/" + archive + " -C nc-bin";
			system(unzip.c_str());

			auto pkg_info = toml::parse("nc-bin/"+package+"/pkg-info.toml");
			std::string makeExecutable = "chmod +x nc-bin/" + package + "/" + pkg_info["execute"].as_string();
			system(makeExecutable.c_str());

			std::string remove = "rm nc-bin/" + archive;
			system(remove.c_str());
		}
		catch (std::string error_message) {
			std::cout << "Error: " << error_message << std::endl;
		}
	}
	else {
		std::cout << "Package(" <<  package << ") not found!" << std::endl;
	}
}
