#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

#include "Console.h"
#include "GraphicsModule.h"

namespace azr {

	class __declspec(dllexport) EngineConfiguration {

	public:
		azr::EngineConfiguration(int fps = 30, std::string title = "NO_TITLE") : fps(fps), title(title) {};

		inline void setFps(int fps) { this->fps = fps; };
		inline int getFps() { return fps; };

		inline void setTitle(std::string title) { this->title = title; };
		inline std::string getTitle() { return title; };

	private:
		int fps;
		std::string title;

	};
	
	class __declspec(dllexport) Engine {

	public:
		// Singleton
		static azr::Engine& getInstance() {
			static Engine instance;
			return instance;
		};

		int start();

	private:
		// Private constructor for singleton
		azr::Engine() {};

		// Engine configuration object
		azr::EngineConfiguration configuration;

		// TMP
		GraphicsModule graphics;

	public:
		inline void setConfiguration(const azr::EngineConfiguration& configuration) { this->configuration = configuration; };
		inline const azr::EngineConfiguration& getConfiguration() { return configuration; };

	};

}
