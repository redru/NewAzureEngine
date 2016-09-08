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
		azr::GraphicsModule() : _exit(false), _pause(false), _refresh(false), _running(false), _start(false), _opened(false) { };

		/* Startup function */
		int startup();
		int startup(azr::EngineConfiguration& configuration);

		int openWindow();

		/* Shutdown function */
		void shutdown();

		/* Graphics loop */
		void run();

		/* Function that changes background color */
		void changeBackgroundColor(int red, int green, int blue, int alpha);

	private:
		bool _exit, _pause, _refresh, _running, _start, _opened;

		GLFWwindow* _window;
		azr::EngineConfiguration _configuration;

		void _refreshModule();

	public:
		inline void setConfiguration(azr::EngineConfiguration configuration) { _configuration = configuration; };
		inline azr::EngineConfiguration& getConfiguration() { return _configuration; };

		inline void setPause(bool& pause) { _pause = pause; };
		inline bool& isPaused() { return _pause; };

		inline void mustRefresh() { _refresh = true; };

		inline bool isRunning() { return _running; };

	};

}
