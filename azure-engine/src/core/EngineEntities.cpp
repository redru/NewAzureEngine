#include "EngineEntities.h"

const unsigned int azr::Color::RED = 0x000000FF;
const unsigned int azr::Color::GREEN = 0x0000FF00;
const unsigned int azr::Color::BLUE = 0x00FF0000;
const unsigned int azr::Color::ALPHA = 0xFF000000;

void azr::Color::setColor(int red, int green, int blue, int alpha) {
	assert(red <= 255), assert(green <= 255), assert(blue <= 255), assert(alpha <= 255);
	_rgba = red | (green << 8) | (blue << 16) | (alpha << 24);
}

unsigned int azr::Color::getColor(int color) {
	switch (color) {
	case azr::Color::RED:
		return _rgba & color;
		break;

	case azr::Color::GREEN:
		return (_rgba & color) >> 8;
		break;

	case azr::Color::BLUE:
		return (_rgba & color) >> 16;
		break;

	case azr::Color::ALPHA:
		return (_rgba & color) >> 24;
		break;

	default:
		return 0;
		break;
	}
}

float azr::Color::getColorUnit(int color) {
	switch (color) {
	case azr::Color::RED:
		return (float)(_rgba & color) / 255.0f;
		break;

	case azr::Color::GREEN:
		return (float)((_rgba & color) >> 8) / 255.0f;
		break;

	case azr::Color::BLUE:
		return (float)((_rgba & color) >> 16) / 255.0f;
		break;

	case azr::Color::ALPHA:
		return (float)((_rgba & color) >> 24) / 255.0f;
		break;

	default:
		return 0.0f;
		break;
	}
}
