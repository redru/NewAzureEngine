#pragma once
#include <stdio.h>
#include <assert.h>
#include <string>
#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "EngineEntities.h"

namespace azr {

	class GraphicsModule {

	public:
		azr::GraphicsModule() : _exit(false), _pause(false) { };

		/* Startup function */
		int startup();

		/* Shutdown function */
		void shutdown();

		void run();

	private:
		bool _exit, _pause;

		GLFWwindow* window;
		azr::EngineConfiguration _configuration;

	public:
		inline void setConfiguration(azr::EngineConfiguration& configuration) { _configuration = configuration; };
		inline azr::EngineConfiguration& getConfiguration() { return _configuration; };

		inline void setPause(bool& pause) { _pause = pause; };
		inline bool& isPaused() { return _pause; };

	};

}
