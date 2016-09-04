#include "GraphicsModule.h"

int azr::GraphicsModule::initialize() {
	/* Initialize the library */
	if (!glfwInit()) {
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(_configuration.getResolution().getWidth(), _configuration.getResolution().getHeight(), _configuration.getTitle().c_str(), NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit()) {
		return -1;
	}

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window) && !exit) {
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void azr::GraphicsModule::close() {
	exit = true;
}
