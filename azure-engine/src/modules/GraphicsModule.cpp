#include "GraphicsModule.h"

int azr::GraphicsModule::startup() {

	/* Initialize the library */
	int glfwInitResult = glfwInit();
	assert(glfwInitResult != 0);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(_configuration.getResolution().getWidth(), _configuration.getResolution().getHeight(), _configuration.getTitle().c_str(), NULL, NULL);
	assert(window != NULL);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	GLenum glewInitResult = glewInit();
	assert(glewInitResult == 0);

	azr::Color clearColor(_configuration.getClearColor());

	glClearColor(clearColor.getColor(0xFF), clearColor.getColor(0xFF00), clearColor.getColor(0xFF0000), clearColor.getColor(0xFF000000));

	return 0;
}

void azr::GraphicsModule::shutdown() {
	_exit = true;
}

void azr::GraphicsModule::run() {

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window) && !_exit) {

		if (!_pause) {
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);
		}

		/* Poll for and process events */
		glfwPollEvents();

	}

	glfwTerminate();

}
