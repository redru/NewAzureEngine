#include "GraphicsModule.h"

int azr::GraphicsModule::startup() {
	if (_start)
		return 1;

	/* Initialize the library */
	int glfwInitResult = glfwInit();
	assert(glfwInitResult != 0);
	_start = true;

	return 0;
}

int azr::GraphicsModule::startup(azr::EngineConfiguration& configuration) {
	if (_start)
		return 1;

	_configuration = configuration;

	/* Initialize the library */
	int glfwInitResult = glfwInit();
	assert(glfwInitResult != 0);
	_start = true;
		
	return 0;	
}

int azr::GraphicsModule::openWindow() {
	if (_opened)
		return 1;

	/* Create a windowed mode window and its OpenGL context */
	_window = glfwCreateWindow(_configuration.getResolution().getWidth(), _configuration.getResolution().getHeight(), _configuration.getTitle().c_str(), NULL, NULL);
	assert(_window != NULL);

	/* Make the window's context current */
	glfwMakeContextCurrent(_window);

	GLenum glewInitResult = glewInit();
	assert(glewInitResult == 0);

	azr::Color clearColor(_configuration.getClearColor());
	glClearColor(clearColor.getColorUnit(azr::Color::RED), clearColor.getColorUnit(azr::Color::GREEN), clearColor.getColorUnit(azr::Color::BLUE), clearColor.getColorUnit(azr::Color::ALPHA));
	_opened = true;

	return 0;
}

void azr::GraphicsModule::shutdown() {
	_exit = true;
}

int azr::GraphicsModule::run() {
	if (_running)
		return 1;

	_running = true;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(_window) && !_exit) {

		if (_refresh) {
			_refreshModule();
		}

		if (!_pause) {
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(_window);
		}

		/* Poll for and process events */
		glfwPollEvents();

	}

	_opened = false;
	_running = false;
	glfwTerminate();

	return 0;
}

void azr::GraphicsModule::changeBackgroundColor(int red, int green, int blue, int alpha) {
	_configuration.setClearColor(azr::Color(red, green, blue, alpha));
}

void azr::GraphicsModule::_refreshModule() {
	azr::Color clearColor(_configuration.getClearColor());
	glClearColor(clearColor.getColorUnit(azr::Color::RED), clearColor.getColorUnit(azr::Color::GREEN), clearColor.getColorUnit(azr::Color::BLUE), clearColor.getColorUnit(azr::Color::ALPHA));

	_refresh = false;
}
