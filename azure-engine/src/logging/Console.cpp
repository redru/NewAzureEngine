#include "Console.h"

void Console::print(std::string message, int color, bool marker) {
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	std::cout << (marker ? "ENGINE>" : "") << message;
	SetConsoleTextAttribute(hConsole, 15);
}

void Console::println(std::string message, int color, bool marker) {
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	std::cout << (marker ? "ENGINE>" : "") << message << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
}
