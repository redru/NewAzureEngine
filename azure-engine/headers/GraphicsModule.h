#pragma once
#include <string>
#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "EngineEntities.h"

namespace azr {

	class GraphicsModule {

	public:
		azr::GraphicsModule() { };

		int initialize();
		void close();

	private:
		GLFWwindow* window;

		azr::EngineConfiguration _configuration;

		bool exit = false;

	public:
		inline void setConfiguration(const azr::EngineConfiguration& configuration) { _configuration = configuration; };
		inline const azr::EngineConfiguration& getConfiguration() { return _configuration; };

	};

}
