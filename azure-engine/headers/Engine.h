#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

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
		azr::Engine() : _configuration(azr::EngineConfiguration()), _graphics(azr::GraphicsModule()) { };

		// Engine configuration object
		azr::EngineConfiguration _configuration;

		// TMP
		azr::GraphicsModule _graphics;

	public:
		inline void setConfiguration(azr::EngineConfiguration configuration) { _configuration = configuration; };
		inline const azr::EngineConfiguration& getConfiguration() { return _configuration; };

	};

}
