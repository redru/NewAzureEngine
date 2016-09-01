#include <iostream>

#include "Engine.h"

int main() {
	azr::EngineConfiguration configuration(60, "AZURE ENGINE TEST");

	azr::Engine& engine(azr::Engine::getInstance());

	engine.setConfiguration(configuration);
	engine.start();

	return 0;
}
