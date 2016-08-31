#include <iostream>

#include "Engine.h"

int main() {
	azr::Engine& engine(azr::Engine::getInstance());
	engine.saySomething();

	return 0;
}
