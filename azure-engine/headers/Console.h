#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class Console {

public:
	static void print(std::string message, int color = 15) {
		static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
		std::cout << "ENGINE>" << message;
		SetConsoleTextAttribute(hConsole, 15);
	}

	static void println(std::string message, int color = 15) {
		static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
		std::cout << "ENGINE>" << message << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
	}

};
