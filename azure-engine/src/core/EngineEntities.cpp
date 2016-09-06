#include "EngineEntities.h"

/* const int azr::Color::RED = 0x000000FF;
const int azr::Color::GREEN = 0x0000FF00;
const int azr::Color::BLUE = 0x00FF0000;
const int azr::Color::ALPHA = 0xFF000000; */

void azr::Color::setColor(int red, int green, int blue, int alpha) {
	assert(red <= 255), assert(green <= 255), assert(blue <= 255), assert(alpha <= 255);
	_rgba = red | (green << 8) | (blue << 16) | (alpha << 24);
}

unsigned int azr::Color::getColor(int color) {
	return _rgba & color;
}
