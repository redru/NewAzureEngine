#include <iostream>

#include "Engine.h"

int main() {
	azr::EngineConfiguration configuration;
	configuration.setFps(60);
	configuration.setTitle("AZURE ENGINE TEST");
	configuration.setResolution(azr::EngineResolution(720, 720));

	azr::Engine& engine(azr::Engine::getInstance());

	engine.setConfiguration(configuration);
	engine.start();

	return 0;
}
