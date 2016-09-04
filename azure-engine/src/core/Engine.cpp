#include "Engine.h"

int azr::Engine::start() {
	bool exit = false;

	std::thread GRAPHICS_THREAD([&]() {
		_graphics.setConfiguration(_configuration);
		_graphics.initialize();
	});

	std::thread GAMEPLAY_THREAD([&]() {
		auto start = std::chrono::high_resolution_clock::now();
		auto end = std::chrono::high_resolution_clock::now();

		while (!exit) {
			start = std::chrono::high_resolution_clock::now();

			//TODO Gameplay loop

			while (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000 <= 50) {
				end = std::chrono::high_resolution_clock::now();
			}
		}
	});

	std::thread COMMAND_THREAD([&]() {

		while (!exit) {
			Console::print("");

			std::string command;
			std::getline(std::cin, command);

			if (command.compare("shutdown") == 0) {
				_graphics.close();
				exit = true;
			} else if (command.compare("engine conf") == 0) {
				Console::println("[FPS] " + std::to_string(_configuration.getFps()), 3, false);
				Console::println("[Title] " + _configuration.getTitle(), 3, false);
				Console::println("[Resolution] " + std::to_string(_configuration.getResolution().getWidth()) + "x" + std::to_string(_configuration.getResolution().getHeight()), 3, false);
			} else {
				Console::println("'" + command + "' not recognized as a command", 5);
			}
		}
	});

	GRAPHICS_THREAD.join();
	GAMEPLAY_THREAD.join();
	COMMAND_THREAD.join();

	return 0;
}
