/*
** EPITECH PROJECT, 2022
** WindowCallBack.cpp
** File description:
** WindowCallBack.cpp
*/

#include "Window.hpp"
#include "Buffer.hpp"
#include "Inputs.hpp"

#include <iostream>

//sw::Input_buffer event_buffer;

SW_GRAPH_MODULE_EXPORT char current_key_flags[sw::Keyboard::LAST];
SW_GRAPH_MODULE_EXPORT char previous_key_flags[sw::Keyboard::LAST];

SW_GRAPH_MODULE_EXPORT char current_mouse_flags[sw::MouseBtn::Button_last];
SW_GRAPH_MODULE_EXPORT char previous_mouse_flags[sw::MouseBtn::Button_last];

SW_GRAPH_MODULE_EXPORT sw::Vector2f current_mouse_position;
SW_GRAPH_MODULE_EXPORT sw::Vector2f previous_mouse_position;

SW_GRAPH_MODULE_EXPORT sw::Vector2f current_mouse_scroll;
SW_GRAPH_MODULE_EXPORT sw::Vector2f previous_mouse_scroll;

GLFWwindow *sw::Window::UpdateWindow()
{
    for (int i = 0; i < sw::Keyboard::LAST; ++i)
        previous_key_flags[i] = current_key_flags[i];
    for (int i = 0; i < sw::MouseBtn::Button_last; ++i)
        previous_mouse_flags[i] = current_mouse_flags[i];
    
    previous_mouse_position = current_mouse_position;
    previous_mouse_scroll = current_mouse_scroll;
    
    std::cout << "mouse x: " << previous_mouse_position.x << ", mouse y: " previous_mouse_position.y << std::endl;
    std::cout << "mouse scroll x axis: " << previous_mouse_scroll.x << ", mouse scroll y axis: " previous_mouse_scroll.y << std::endl;
    
    //event_buffer.clear();
    glfwSwapBuffers(m_window);
    return (m_window);
}

void sw::Window::setUpCallBack()
{
    glfwSetFramebufferSizeCallback(m_window, resizeCallBack);
    glfwSetKeyCallback(m_window, input_callback);
    glfwSetMouseButtonCallback(m_window, mouse_button_callback);
    glfwSetScrollCallback(m_window, scroll_callback);
    glfwSetCursorPosCallback(m_window, position_callback);
}

void sw::Window::input_callback(GLFWwindow*, int key, int, int action, int)
{
    if (key == -1)
        return;
    if (action == GLFW_RELEASE)
        current_key_flags[key] = 0;
    else
        current_key_flags[key] = 1;
}

void sw::Window::mouse_button_callback(GLFWwindow*, int button, int action, int)
{
    current_mouse_flags[button] = action;
}

void sw::Window::position_callback(GLFWwindow*, double xpos, double ypos)
{
    /*
    std::pair<int,int> kys{};
    std::pair<double,double> ipt{xpos,ypos};
    sw::Type tpe = sw::Position;

    event_buffer.push(tpe, kys, ipt);
    */

   current_mouse_position = {xpos, ypos};
}

void sw::Window::scroll_callback(GLFWwindow*, double x, double y)
{
    /*
    std::pair<int,int> kys{};
    std::pair<double,double> ipt{x,y};
    sw::Type tpe = sw::Scroll;

    event_buffer.push(tpe, kys, ipt);
    */
   current_mouse_scroll = {x, y};
}

void sw::Window::resizeCallBack(GLFWwindow *window, int width, int height)
{
    if (width > m_maxSize.x || height > m_maxSize.y)
    {
        SetSize((width > m_maxSize.x) ? m_maxSize.x : width, (height > m_maxSize.y) ? m_maxSize.y : height);
        return;
    }
    glViewport(0, 0, width, height);
}

bool sw::isKeyPressed(const int& kys)
{
    if ((previous_key_flags[kys] == 0) && (current_key_flags[kys] == 1))
        return true;
    return false;
}

bool sw::isKeyDown(const int &kys)
{
    if (current_key_flags[kys] == 1)
        return true;
    return false;
}

bool sw::isKeyReleased(const int &kys)
{
    if ((previous_key_flags[kys] == 1) && (current_key_flags[kys] == 0))
        return true;
    return false;
}

bool sw::isKeyUp(const int &kys)
{
    if (current_key_flags[kys] == 0)
        return true;
    return false;
}

bool sw::isMouseButtonPressed(const int &btn)
{
    if ((previous_mouse_flags[btn] == 0) && (current_mouse_flags[btn] == 1))
        return true;
    return false;
}

bool sw::isMouseButtonDown(const int &btn)
{
    if (current_mouse_flags[btn] == 1)
        return true;
    return false;
}

bool sw::isMouseButtonReleased(const int &btn)
{
    if ((previous_mouse_flags[btn] == 1) && (current_mouse_flags[btn] == 0))
        return true;
    return false;
}

bool sw::isMouseButtonUp(const int &btn)
{
    return !sw::isMouseButtonDown(btn);
}

//DEPRECATED DO NOT USE
bool sw::mouseMoved()
{
    /*
    const auto &tmp = event_buffer.get();

    for (size_t i = 0; i < event_buffer.getIdx(); ++i)
    {
        if (tmp[i].m_t == sw::Position)
            return true;
    }*/
    return false;
}

sw::Vector2f sw::getMouseScroll(void)
{
    /*
    const auto& tmp = event_buffer.get();

    for (size_t i = 0; i < event_buffer.getIdx(); ++i)
    {
        if (tmp[i].m_t == sw::Scroll && tmp[i].m_os == evt)
            return true;
    }
    */
    return current_mouse_scroll;
}

sw::Vector2f sw::getMousePosition(void)
{
    /*
    const auto& tmp = event_buffer.get();

    for (size_t i = 0; i < event_buffer.getIdx(); ++i)
    {
        if (tmp[i].m_t == sw::Scroll && tmp[i].m_os == evt)
            return true;
    }
    */
    return current_mouse_position;
}