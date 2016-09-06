#include <iostream>

#include "Engine.h"

int main() {
	azr::EngineConfiguration configuration;
	configuration.setFps(60);
	configuration.setTitle("AZURE ENGINE TEST");
	configuration.setResolution(azr::EngineResolution(1280, 720));
	configuration.setClearColor(azr::Color(0x00, 0xFF, 0x00, 0xFF));

	azr::Engine& engine(azr::Engine::getInstance());

	engine.setConfiguration(std::move(configuration));
	engine.start();

	return 0;
}
