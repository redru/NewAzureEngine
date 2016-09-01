#include "Engine.h"

int azr::Engine::start() {
	bool exit = false;

	std::thread GRAPHICS_THREAD([&]() {
		graphics.initialize(configuration.getFps(), configuration.getTitle());
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
				graphics.close();
				exit = true;
			} else if (command.compare("engine conf") == 0) {
				Console::println("FPS: " + std::to_string(configuration.getFps()), 3);
				Console::println("Title: " + configuration.getTitle(), 3);
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
