#include "Core.h"

namespace Coco
{
    Window window = Window();
    Layer* layer = nullptr;
    Renderer renderer = Renderer();

    void Attach(Layer* p_layer)
    {
        layer = p_layer;
    }

    void Start(const char* title)
    {
        printf("Welcome to CoconutEngine!\n");
        std::cout << "Starting program!\n" << std::endl;

        window.Create(title);
        renderer.Init();
        layer->Init();
        renderer.camera = &layer->coco_GameCamera;

        double dt = 0.0;

        while (window.IsOpen())
        {


            window.UpdateEvents();

            for (KeyEvent& event : window.GetKeyEvents())
            {
                if (event.action == KeyEvent::KeyEventAction::KEY_PRESS)
                {
                    if (event.key == COCO_KEY_C)
                    {
                        renderer.camera->attached = !renderer.camera->attached;
                        if (renderer.camera->attached)
                        {
                            glfwSetInputMode(window.GetWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
                        }
                        else
                        {
                            glfwSetInputMode(window.GetWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                        }
                    }
                }
                layer->OnKeyEvent(event);
            }
            for (WindowEvent& event : window.GetWindowEvents())
            {
                if (event.action == WindowEvent::WindowEventAction::WINDOW_RESIZE)
                {
                    renderer.camera->aspect = (float)event.new_width / (float)event.new_height;
                }
                layer->OnWindowEvent(event);
            }
            for (MouseEvent& event : window.GetMouseEvents())
            {
                layer->OnMouseEvent(event);
            }

            renderer.NewFrame();

            layer->Update();
            layer->dt = dt;

            dt = window.Update();
        }
    }
    
    void Finish()
    {   
        layer->Finish();
        renderer.Finish();
        layer = nullptr;
        window.Finish();
    }
}