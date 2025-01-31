/*
	MIT License

	Copyright (c) 2025 Nachos Team

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#ifdef __WIN32
	#include <windows.h>
#elif __linux__
	
#endif
#include "toml.hpp"
extern "C" {

}

int main(int argc, char *argv[]) {
	while (true) {
		std::wcout << "Enter: ";
		std::wstring input;
		getline(std::wcin, input);
		std::string input_str(input.begin(), input.end());
		if (input == L"pizda") {
			std::wcout << "pizdec" << std::endl;
		}
		else {
			if (!input.empty()) {
				// сделать проверку на пробелы в вводе (ес пробелы, то пуста)
				if (std::filesystem::exists(L"nc-bin/"+input)) {
					std::cout << "Test: Exists" << std::endl;
					//добавить запуск прог
				}
				else {
					std::wcout << "Unknown command: " << input << std::endl;
				}
			}
		}
	}
	
	/* auto data = toml::parse("test.toml");
	int title = toml::find<int>(data, "main", "owners");
	std::cout << "Enter: ";
	std::string pizda;
	getline(std::cin, pizda);
	
	data["testing"]["pizdaV1"] = pizda;
	std::ofstream file("test.toml");
	file << data;
	file.close(); */
}