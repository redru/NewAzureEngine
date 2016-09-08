#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "StringUtils.h"
#include "EngineEntities.h"
#include "Console.h"
#include "GraphicsModule.h"

namespace azr {
	
	class __declspec(dllexport) Engine {

	public:
		// Singleton
		static azr::Engine& getInstance() {
			static Engine _instance;
			return _instance;
		};

		int start();

	private:
		// Private constructor for singleton
		azr::Engine() : _configuration(), v_graphics(10), _exit(false) { };

		std::vector<azr::GraphicsModule>::iterator _currentWindow;
		bool _exit;

		std::thread startWindow();
		std::thread startGameplay();
		std::thread startCommand();

		// Engine configuration object
		azr::EngineConfiguration _configuration;

		// TMP
		std::vector<azr::GraphicsModule> v_graphics;

	public:
		inline void setConfiguration(azr::EngineConfiguration&& configuration) { _configuration = configuration; };
		inline azr::EngineConfiguration& getConfiguration() { return _configuration; };

	};

}
