#include "Engine.h"

int azr::Engine::start() {
	bool exit = false;
	bool _mustCreateWindow = true;

	std::thread GRAPHICS_THREAD([&]() {

		while (!exit) {
			if (_mustCreateWindow) {
				_graphics.startup(_configuration);
				_graphics.openWindow();
				_graphics.run();

				_mustCreateWindow = false;
			}
		}

		_graphics.shutdown();
		
	});

	std::thread GAMEPLAY_THREAD([&]() {
		auto start = std::chrono::high_resolution_clock::now();
		auto end = std::chrono::high_resolution_clock::now();

		while (!exit) {
			start = std::chrono::high_resolution_clock::now();

			while (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000 <= 50) {
				end = std::chrono::high_resolution_clock::now();
			}
		}
	});

	std::thread COMMAND_THREAD([&]() {
		while (!exit) {
			Console::print("");

			std::string command;
			vector<string> arguments;

			std::getline(std::cin, command);
			arguments = azr::StringUtils::split(command, ' ');

			try {

				if (arguments.at(0).compare("shutdown") == 0) {
					exit = true;
				} else if (arguments.at(0).compare("engine") == 0) {
					if (arguments.size() == 2 && arguments.at(1).compare("conf") == 0) {
						Console::println("[FPS] " + std::to_string(_configuration.getFps()), 3, false);
						Console::println("[Title] " + _configuration.getTitle(), 3, false);
						Console::println("[Resolution] " + std::to_string(_configuration.getResolution().getWidth()) + "x" + std::to_string(_configuration.getResolution().getHeight()), 3, false);
					} else {
						throw "";
					}
				} else if (arguments.at(0).compare("rgba") == 0) {
					std::vector<int> color = { std::stoi(arguments.at(1), nullptr, 10), std::stoi(arguments.at(2), nullptr, 10), std::stoi(arguments.at(3), nullptr, 10), std::stoi(arguments.at(4), nullptr, 10) };
					_graphics.changeBackgroundColor(color.at(0), color.at(1), color.at(2), color.at(3));
					_graphics.mustRefresh();
					Console::println("[GRAPHICS] Changed to R: " + std::to_string(color.at(0)) + " G: " + std::to_string(color.at(1)) + " B: " + std::to_string(color.at(2)) + " A: " + std::to_string(color.at(3)), 3, false);
				} else if (arguments.at(0).compare("window") == 0) {
					if (arguments.size() == 2 && arguments.at(1).compare("open") == 0) {
						_mustCreateWindow = true;
					} else {
						throw "";
					}
				} else {
					throw "";
				}

			} catch (char* error) {
				Console::println(error == "" ? "'" + command + "' not recognized as a command" : error, 5);
			} catch (...) {
				Console::println("'" + command + "' not recognized as a command", 5);
			}
		}
	});

	GRAPHICS_THREAD.join();
	GAMEPLAY_THREAD.join();
	COMMAND_THREAD.join();

	return 0;
}
