#include "Core.h"

namespace Coco
{
    Window window = Window();
    Layer* layer = nullptr;

    void Attach(Layer* p_layer)
    {
        layer = p_layer;
    }

    void Start(const char* title)
    {
        printf("Welcome to CoconutEngine!\n");

        window.Create(title);

        while (window.IsOpen())
        {
            glfwPollEvents();
        }
    }

    void Finish()
    {
        glFinish();
        glfwTerminate();
    }
}