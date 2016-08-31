#include <iostream>

#include "Engine.h"

int main() {
	azr::EngineConfiguration configuration(60, "New Azure Engine...");

	azr::Engine& engine(azr::Engine::getInstance());

	engine.setConfiguration(configuration);
	engine.initialize();

	return 0;
}
