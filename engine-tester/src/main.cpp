#include <iostream>

#include "Engine.h"

int main() {
	azr::Engine& engine(azr::Engine::getInstance());
	engine.saySomething();
	engine.initialize();

	return 0;
}
