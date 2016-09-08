#include "Engine.h"

int azr::Engine::start() {
	_currentWindow = v_graphics.begin();
	/* std::string file;
	azr::StringUtils::readFile("C:\\Users\\admin\\Desktop\\code.txt", file); */

	std::thread& GRAPHICS_THREAD(startWindow());
	std::thread& COMMAND_THREAD(startCommand());
	std::thread& GAMEPLAY_THREAD(startGameplay());	

	COMMAND_THREAD.detach();
	GRAPHICS_THREAD.detach();
	GAMEPLAY_THREAD.join();

	return 0;
}

std::thread azr::Engine::startWindow() {
	std::thread thread([&]() {
		azr::GraphicsModule& _graphics(*_currentWindow);
		_graphics.startup(_configuration);
		_graphics.openWindow();
		_graphics.run();
	});

	if (_currentWindow++ == v_graphics.end())
		_currentWindow = v_graphics.begin();

	return thread;
}

std::thread azr::Engine::startGameplay() {
	std::thread thread([&]() {
		auto start = std::chrono::high_resolution_clock::now();
		auto end = std::chrono::high_resolution_clock::now();

		while (!_exit) {
			start = std::chrono::high_resolution_clock::now();

			while (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000 <= 50) {
				end = std::chrono::high_resolution_clock::now();
			}
		}
	});

	return thread;
}

std::thread azr::Engine::startCommand() {
	std::thread thread([&]() {
		while (!_exit) {
			Console::print("");

			std::string command;
			vector<string> arguments;

			std::getline(std::cin, command);
			arguments = azr::StringUtils::split(command, ' ');

			try {

				if (arguments.at(0).compare("shutdown") == 0) {
					_exit = true;
					for (std::vector<azr::GraphicsModule>::iterator it = v_graphics.begin(); it != v_graphics.end(); it++) {
						azr::GraphicsModule& tmp(*it);
						tmp.shutdown();
					}
				}
				else if (arguments.at(0).compare("engine") == 0) {
					if (arguments.size() == 2 && arguments.at(1).compare("conf") == 0) {
						Console::println("[FPS] " + std::to_string(_configuration.getFps()), 3, false);
						Console::println("[Title] " + _configuration.getTitle(), 3, false);
						Console::println("[Resolution] " + std::to_string(_configuration.getResolution().getWidth()) + "x" + std::to_string(_configuration.getResolution().getHeight()), 3, false);
					}
					else {
						throw "";
					}
				}
				else if (arguments.at(0).compare("rgba") == 0) {
					std::vector<int> color = { std::stoi(arguments.at(1), nullptr, 10), std::stoi(arguments.at(2), nullptr, 10), std::stoi(arguments.at(3), nullptr, 10), std::stoi(arguments.at(4), nullptr, 10) };

					for (std::vector<azr::GraphicsModule>::iterator it = v_graphics.begin(); it != v_graphics.end(); it++) {
						azr::GraphicsModule& tmp(*it);
						tmp.changeBackgroundColor(color.at(0), color.at(1), color.at(2), color.at(3));
						tmp.mustRefresh();
					}

					Console::println("[GRAPHICS] Changed to R: " + std::to_string(color.at(0)) + " G: " + std::to_string(color.at(1)) + " B: " + std::to_string(color.at(2)) + " A: " + std::to_string(color.at(3)), 3, false);
				}
				else if (arguments.at(0).compare("window") == 0) {
					if (arguments.size() == 2 && arguments.at(1).compare("open") == 0) {
						std::thread& GRAPHICS_THREAD(startWindow());
						GRAPHICS_THREAD.detach();
					}
					else {
						throw "";
					}
				}
				else {
					throw "";
				}

			}
			catch (char* error) {
				Console::println(error == "" ? "'" + command + "' not recognized as a command" : error, 5);
			}
			catch (...) {
				Console::println("'" + command + "' not recognized as a command", 5);
			}
		}
	});

	return thread;
}
