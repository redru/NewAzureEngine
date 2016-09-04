#pragma once
#include <iostream>
#include <string>

namespace azr {

	class __declspec(dllexport) EngineResolution {

	public:
		azr::EngineResolution() : _width(640), _height(480) { };
		azr::EngineResolution(int width, int height) : _width(width), _height(height) { };

		inline void setWidth(int width) { _width = width; };
		inline int getWidth() { return _width; };

		inline void setHeight(int height) { _height = height; };
		inline int getHeight() { return _height; };

	private:
		int _width, _height;

	};

	class __declspec(dllexport) EngineConfiguration {

	public:
		azr::EngineConfiguration() { };

		inline void setFps(int fps) { _fps = fps; };
		inline int getFps() { return _fps; };

		inline void setTitle(std::string title) { _title = title; };
		inline std::string getTitle() { return _title; };

		inline void setResolution(azr::EngineResolution resolution) { _resolution = resolution; };
		inline azr::EngineResolution getResolution() { return _resolution; };

	private:
		int _fps;
		std::string _title;
		azr::EngineResolution _resolution;

	};

}
