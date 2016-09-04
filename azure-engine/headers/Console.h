#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class Console {

public:
	static void print(std::string message, int color = 15, bool marker = true);
	static void println(std::string message, int color = 15, bool marker = true);

};
