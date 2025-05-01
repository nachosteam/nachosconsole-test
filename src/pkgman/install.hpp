#pragma once
#include <iostream>
#include "getArch.hpp"
#include "../toml.hpp"

static void install(std::string package) {
	auto pkgs = toml::parse("nc-bin/packages.toml");
	auto cfg = toml::parse("nc-bin/cfg.toml");
	if (pkgs.contains(package) && isContainYourArch(package)) {
		std::string archive = package + "-" + pkgs[package]["version"].as_string() + "-" + downloadableArch(package) + ".tar.gz";
		std::string downloadComm = "curl " + cfg["repo"].as_string() + "/" + archive + " -o nc-bin/" + archive;
		std::cout << downloadComm << std::endl;
		system(downloadComm.c_str());

		std::string unzip = "tar -xvzf nc-bin/" + archive + " -C nc-bin";
		system(unzip.c_str());

		std::string remove = "rm nc-bin/" + archive;
		system(remove.c_str());
	}
}
