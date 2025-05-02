#pragma once
#include <iostream>
#include "../toml.hpp"

std::string getArch() {
	#if defined(__x86_64__) || defined(_M_X64)
        return "x86_64";
        #elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
        return "x86_32";
        #elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
        return "arm7";
        #elif defined(__aarch64__) || defined(_M_ARM64)
        return "arm64";
        #else
        return "UNSUPPORTED";
        #endif
}

bool isContainYourArch(std::string package) {
	auto data = toml::parse("nc-bin/packages.toml");
	auto archList = toml::find<std::vector<std::string>>(data, package, "arch");

	for (const auto& arch : archList) {
		if (arch == getArch() || arch == "any") {
			return true;
		}
	}
	return false;
}

std::string downloadableArch(std::string package) {
        auto data = toml::parse("nc-bin/packages.toml");
        auto archList = toml::find<std::vector<std::string>>(data, package, "arch");

        for (const auto& arch : archList) {
                if (arch == getArch()) {
                        return getArch();
                }
		else if (arch == "any")
			return "any";
        }
}
