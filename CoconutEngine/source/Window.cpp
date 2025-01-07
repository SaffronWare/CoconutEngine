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

        glViewport(0, 0, 500, 500);

        glfwSwapInterval(1);

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
	}

    void Window::Finish()
    {
        glFinish();
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    bool Window::IsOpen()
    {
        return !glfwWindowShouldClose(window);
    }

    double Window::Update()
    {
        glfwSwapBuffers(window);

        double dt = glfwGetTime() - prev_upd_time;
        prev_upd_time += dt;
        return dt;
    }

    void Window::UpdateEvents()
    {
        glfwPollEvents();

        key_events.clear();
        window_events.clear();
        mouse_events.clear();
        

        bool state;
        for (int key = GLFW_KEY_SPACE; key <= GLFW_KEY_LAST; key++)
        {
            state = (bool)glfwGetKey(window, key);
            new_states[key - GLFW_KEY_SPACE] = state;

            if (state)
            {
                key_events.push_back(KeyEvent(key, KeyEvent::KeyEventAction::KEY_HELD));
            }

            if (state != states[key - GLFW_KEY_SPACE])
            {
                if (state)
                {
                    key_events.push_back(KeyEvent(key, KeyEvent::KeyEventAction::KEY_PRESS));
                }
                else
                {
                    key_events.push_back(KeyEvent(key, KeyEvent::KeyEventAction::KEY_RELEASE));
                }
            }
            states[key - GLFW_KEY_SPACE] = state;
        }

    

        int n_width; int n_height;
        glfwGetWindowSize(window, &n_width, &n_height);

        if (n_width != width || n_height != height)
        {

            glViewport(0, 0, n_width, n_height);

            window_events.push_back(WindowEvent(
                n_width, 
                n_height, 
                width, 
                height, 
                WindowEvent::WindowEventAction::WINDOW_RESIZE
            ));
            width = n_width;
            height = n_height;
        }

        bool n_maximization = (bool)glfwGetWindowAttrib(window, GLFW_MAXIMIZED);

        if (n_maximization != maximized)
        {
            if (n_maximization)
            {
                window_events.push_back(WindowEvent(
                    width, 
                    height, 
                    width, 
                    height, 
                    WindowEvent::WindowEventAction::WINDOW_RESTORATION
                ));
            }
            else
            {
                window_events.push_back(WindowEvent(
                    width, 
                    height, 
                    width, 
                    height, 
                    WindowEvent::WindowEventAction::WINDOW_MINIMIZED
                    ));
            }
            maximized = n_maximization;
        }


        int n_x; int n_y;
        glfwGetWindowPos(window, &n_x, &n_y);

        if (n_x != x || n_y != y)
        {

            window_events.push_back(WindowEvent(
                width, 
                height, 
                width, 
                height, 
                WindowEvent::WindowEventAction::WINDOW_MOVED
            ));
            x = n_x; y = n_y;
        }

        double n_mp_x; double n_mp_y;
        glfwGetCursorPos(window, &n_mp_x, &n_mp_y);

        if (n_mp_x != mouse_pos_x || n_mp_y != mouse_pos_y)
        {
            mouse_events.push_back(MouseEvent(
                n_mp_x, 
                n_mp_y, 
                mouse_pos_x,
                mouse_pos_y, 
                MouseEvent::MouseEventAction::CURSOR_MOVED
            ));
            mouse_pos_x = n_mp_x;  mouse_pos_y = n_mp_y;
        }

        
        bool N_LEFT_PRESSED = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        if (N_LEFT_PRESSED)
        {
            mouse_events.push_back(MouseEvent(
                mouse_pos_x,
                mouse_pos_y,
                mouse_pos_x,
                mouse_pos_y,
                MouseEvent::MouseEventAction::LEFT_HELD
            ));
        }
        if (N_LEFT_PRESSED != LEFT_PRESSED)
        {
            if (LEFT_PRESSED)
            {
                mouse_events.push_back(MouseEvent(
                    mouse_pos_x,
                    mouse_pos_y,
                    mouse_pos_x,
                    mouse_pos_y,
                    MouseEvent::MouseEventAction::LEFT_PRESS
                ));
            }
            LEFT_PRESSED = !LEFT_PRESSED;
        }
    }

    std::vector<KeyEvent> Window::GetKeyEvents()
    {
        return key_events;
    }

    std::vector<WindowEvent> Window::GetWindowEvents()
    {
        return window_events;
    }

    std::vector<MouseEvent> Window::GetMouseEvents()
    {
        return mouse_events;
    }
}