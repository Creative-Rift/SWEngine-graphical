/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Module.cpp
** Description: [CHANGE]
*/

#include "SW/utils/Speech.hpp"

#include "OpenGLModule.hpp"
#include "resources/OpenResources.hpp"

sw::OpenGLModule::OpenGLModule() :
sw::AModule(),
m_window(nullptr)
{}

void sw::OpenGLModule::initialize()
{
    if (!glfwInit())
        throw sw::Error("Cannot initialize GLFW", "");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(800, 600, "Title", nullptr, nullptr);
    if (!m_window)
        throw sw::Error("Failed to create window", "");
    glfwMakeContextCurrent(m_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw sw::Error("Failed to initialize GLAD", "");

    glViewport(0, 0, 800, 600);
    setUpCallBack();
}

void sw::OpenGLModule::update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void sw::OpenGLModule::terminate()
{
    glfwTerminate();
}

bool sw::OpenGLModule::isOk()
{
    return (!glfwWindowShouldClose(m_window));
}

std::unique_ptr<sw::AResources> sw::OpenGLModule::createResourceInstance()
{
    return (std::make_unique<sw::OpenResources>());
}

void sw::OpenGLModule::setUpCallBack()
{
    glfwSetFramebufferSizeCallback(m_window, resizeCallBack);
}

void sw::OpenGLModule::resizeCallBack(GLFWwindow *window, int width, int height)
{
    width = (width > 1920 ? 1920 : width);
    height = (height > 1080 ? 1080 : height);
    glViewport(0, 0, width, height);
}

std::string sw::OpenGLModule::type() const
{
    return (std::string{"OpenGLModule"});
}