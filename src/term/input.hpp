#pragma once
#include <iostream>
#include <unistd.h>

std::string readInputWithHistory(const std::string& prompt, std::vector<std::string>& history, int& historyIndex) {
	std::string buffer;
	char c;
	std::cout << prompt << std::flush;

	while (read(STDIN_FILENO, &c, 1) == 1) {
		if (c == '\n') {
			std::cout << "\n";
			if (!buffer.empty()) {
				history.push_back(buffer);
				historyIndex = history.size();
			}
			return buffer;
		} else if (c == 127 || c == '\b') {
			if (!buffer.empty()) {
				buffer.pop_back();
				std::cout << "\b \b" << std::flush;
			}
		} else if (c == '\033') {
			char seq[2];
			if (read(STDIN_FILENO, &seq[0], 1) != 1) break;
			if (read(STDIN_FILENO, &seq[1], 1) != 1) break;

			if (seq[0] == '[') {
				if (seq[1] == 'A') {
					if (historyIndex > 0) {
						historyIndex--;
						buffer = history[historyIndex];
						std::cout << "\r\033[K" << prompt << buffer << std::flush;
					}
				} else if (seq[1] == 'B') {
					if (historyIndex + 1 < (int)history.size()) {
						historyIndex++;
						buffer = history[historyIndex];
					} else {
						historyIndex = history.size();
						buffer.clear();
					}
					std::cout << "\r\033[K" << prompt << buffer << std::flush;
				}
			}
		} else {
			buffer += c;
			std::cout << c << std::flush;
		}
	}
	return buffer;
}

