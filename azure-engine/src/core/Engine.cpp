#include "Engine.h"

int azr::Engine::initialize() {

	std::thread GRAPHICS_THREAD([&]() {
		graphics.initialize(configuration.getFps(), configuration.getTitle());
	});

	std::thread GAMEPLAY_THREAD([&]() {
		bool exit = false;
		std::string command;

		while (!exit) {
			std::cout << "system> ";
			std::cin >> command;

			if (command.compare("exit") == 0) {
				graphics.close();
				exit = true;
			} else if (command.compare("conf") == 0) {
				std::cout << "FPS: " + std::to_string(configuration.getFps()) << "\nTitle: " + configuration.getTitle() << std::endl;
			}
		}
	});

	GRAPHICS_THREAD.join();
	GAMEPLAY_THREAD.join();

	return 0;
}
