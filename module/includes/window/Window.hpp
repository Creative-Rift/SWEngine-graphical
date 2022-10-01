/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Window.hpp
** Description: [CHANGE]
*/

#ifndef SHIPWRECK_ENGINE_WINDOW_HPP
#define SHIPWRECK_ENGINE_WINDOW_HPP

#include "dependencies/glad/glad.h"
#include "GLFW/glfw3.h"

#include "OpenGLModule_Config.hpp"
#include "exception/Error.hpp"
#include "utils/Vector2.hpp"

namespace sw
{
    enum WindowFlags {
        FULLSCREEN_MODE = 0x00000002,
        RESIZABLE       = 0x00000004,
        UNDECORATED     = 0x00000008,
        HIDDEN          = 0x00000010,
        MINIMIZED       = 0x00000020,
        MAXIMIZED       = 0x00000040,
        UNFOCUSED       = 0x00000080,
        TRANSPARENT     = 0x00000100,
    };

    class SW_GRAPH_MODULE_EXPORT Window
    {
    private:
        static bool m_ready;
        static GLFWwindow *m_window;
        static bool m_fullScreen;
        static Vector2i m_size;
        static Vector2i m_maxSize;
        static Vector2i m_position;
        static std::string m_title;
        static unsigned int m_flags;
        static bool m_cursorHidden;

        static void resizeCallBack(GLFWwindow* window, int width, int height);
        static void input_callback(GLFWwindow* window, int key, int scancode, int action, [[maybe_unused]] int mods);
        static void mouse_button_callback(GLFWwindow* window, int button, int action,[[maybe_unused]] int mods);
        static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
        static void position_callback(GLFWwindow* window, double xpos, double ypos);

        static void setUpCallBack();

    public:
        Window();
        ~Window();

        static GLFWwindow *CreateWindow();
        static GLFWwindow *GetWindow();
        static GLFWwindow *UpdateWindow();

        static void ToggleFullScreen();
        static void Maximize();
        static void Minimize();
        static void Restore();
        static void SetTitle(std::string title);
        static void SetFlag(WindowFlags flags);
        static void ClearFlag(WindowFlags flags);
        static void SetWindowPos(int x, int y);
        static void SetWindowPos(sw::Vector2i pos);
        static void SetMinSize(int with, int height);
        static void SetMinSize(sw::Vector2i size);
        static void SetMaxSize(int with, int height);
        static void SetMaxSize(sw::Vector2i size);
        static void SetSize(sw::Vector2i size);
        static void SetSize(int with, int height);
        static void SetVisibleCursor(bool visible);
        static void SetMonitor(int index);
        static void SetClipboardText(std::string text);

        static bool IsFullScreen();
        static bool IsReady();
        static bool IsOpen();
        static bool IsCursorVisible();

        static Vector2i GetSize();
        static std::string GetTitle();
        static Vector2i GetPosition();
        static std::string GetClipBoardText();
        static bool HasFlag(WindowFlags flags);
    };

    ////////////////////////////////////////////////////////////
    /// @brief Return True if given key was pressed once
    ///
    /// @param key Selected key from sw::Keyboard enum
    ///
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT bool isKeyPressed(const int&);//TODO template mouse/keyboard

    ////////////////////////////////////////////////////////////
    /// @brief Return True if give key was released
    ///
    /// @param key Selected key from sw::Keyboard enum
    ///
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT bool isKeyReleased(const int&);//same

    ////////////////////////////////////////////////////////////
    /// @brief Return True if given key is held down
    ///
    /// @param key Selected key from sw::Keyboard enum
    ///
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT bool isKeyDown(const int&);//same
    //bool isKeyUp(sw::Type&, const int&);

    ////////////////////////////////////////////////////////////
    /// @brief Return True if given key is not being pressed
    ///
    /// @param key Selected button from sw::Keyboard enum
    ///
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT bool isKeyUp(const int &kys);

    ////////////////////////////////////////////////////////////
    /// @brief Return True if given button is being pressed once
    ///
    /// @param button Selected button from sw::Mousebtn enum
    ///
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT bool isMouseButtonPressed(const int &btn);

    ////////////////////////////////////////////////////////////
    /// @brief Return True if given button is being pressed
    ///
    /// @param button Selected button from sw::Mousebtn enum
    ///
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT bool isMouseButtonDown(const int &btn);

    ////////////////////////////////////////////////////////////
    /// @brief Return True if given button has been released
    ///
    /// @param button Selected button from sw::Mousebtn enum
    ///
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT bool isMouseButtonReleased(const int &btn);

    ////////////////////////////////////////////////////////////
    /// @brief Return True if given button is not being pressed
    ///
    /// @param button Selected button from sw::Mousebtn enum
    ///
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT bool isMouseButtonUp(const int &btn);

    ////////////////////////////////////////////////////////////
    /// @brief Return current x and y position of mouse cursor
    ///
    /// @param none
    ///
    /// @return Vector2f
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT sw::Vector2f getMousePosition();

    ////////////////////////////////////////////////////////////
    /// @brief Return current scroll of x and y axis
    ///
    /// @param none
    ///
    /// @return Vector2f
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT sw::Vector2f getMouseScroll();
}

#endif //SHIPWRECK_ENGINE_WINDOW_HPP
