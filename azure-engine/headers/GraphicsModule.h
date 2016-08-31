#pragma once
#include <string>
#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

class GraphicsModule {

public:
	int initialize(int fps, std::string title);
	void close();

private:
	int fps = 30;
	std::string title = "NO_TITLE";

	bool exit = false;

};
