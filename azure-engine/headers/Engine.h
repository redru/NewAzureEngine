#pragma once
#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace azr {
	
	class __declspec(dllexport) Engine {

	public:
		// Singleton
		static azr::Engine& getInstance() {
			static Engine instance;
			return instance;
		}

		void saySomething();
		int initialize();

	private:
		azr::Engine() {};

	};

}
