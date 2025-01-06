#include "Window.h"


namespace Coco
{
	void Window::Create(const char* title)
	{
        if (!glfwInit())
        {
            std::cerr << "GLFW INITIALIZATION FAILED" << std::endl;
            exit(EXIT_FAILURE);
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(500, 500, title, NULL, NULL);
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "FAILED TO INTIALIZE GLAD" << std::endl;
            exit(EXIT_FAILURE);
        }
	}

    bool Window::IsOpen()
    {
        return !glfwWindowShouldClose(window);
    }
}