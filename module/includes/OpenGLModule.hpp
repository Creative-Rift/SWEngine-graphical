/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: OpenGLModule.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_GRAPHICAL_OPENGLMODULE_HPP
#define SWENGINE_GRAPHICAL_OPENGLMODULE_HPP

#include "dependencies/glad/glad.h"
#include "GLFW/glfw3.h"
#include "openal/al.h"
#include "openal/alc.h"

#include "OpenGLModule_Config.hpp"
#include "utils/Buffer.hpp"
#include "utils/Inputs.hpp"
#include "scenes_manager/SceneManager.hpp"
#include "utils/Chrono.hpp"
#include "event/EventManager.hpp"

#include <memory>
#include <array>
#include <map>

#define WINDOW_FULLSCREEN_WINDOWED 0
#define WINDOW_FULLSCREEN 0

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT OpenGLModule
    {
        private:
            static bool m_isLoad;
            static sw::Chrono m_chronoWindow;
            static GLFWwindow *m_window;
            static ALCdevice *m_audioDevice;
            static ALCcontext *m_audioContext;
            static double m_frameRate;

            static std::vector<std::string> m_devices;

            static void resizeCallBack(GLFWwindow* window, int width, int height);
            static void input_callback(GLFWwindow* window, int key, int scancode, int action, [[maybe_unused]] int mods);
            static void mouse_button_callback(GLFWwindow* window, int button, int action,[[maybe_unused]] int mods);
            static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
            static void position_callback(GLFWwindow* window, double xpos, double ypos);
            static void setUpCallBack();
            static void loadResourcesFile(const std::string &path);
            static void displayAudioDevice();
        
        public:
            static sw::Chrono m_chrono;
            static SceneManager m_sceneManager;
            static EventManager m_eventManager;
            explicit OpenGLModule();
            ~OpenGLModule() = default;

            /// @brief Return the statut of the @b Module.
            ///
            /// @return True if the @b Module is load. False if not.
            [[nodiscard]] bool isLoad() const;

            static void load();
            static void update();
            static void unload();
            static bool isOk();
            static SceneManager sceneManager();
            static EventManager eventManager();
            [[nodiscard]] std::string type() const;

            std::shared_ptr<sw::AResources> createResourceInstance();

            static void setFrameRateLimit(unsigned int frameRate);
    }; // class OpenGLModule

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
    /// @brief Return true if given scroll direction is correct
    ///
    /// @param std::pair<double,double>&
    /// 
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT bool mouseScrolled(const std::pair<double,double>&);

    ////////////////////////////////////////////////////////////
    /// @brief Return True if mouse moved
    ///
    /// @param void
    /// 
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    SW_GRAPH_MODULE_EXPORT bool mouseMoved();
} // namespace sw

#endif //SWENGINE_GRAPHICAL_OPENGLMODULE_HPP
