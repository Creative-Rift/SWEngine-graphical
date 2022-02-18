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

#include "SW/Engine.hpp"

#include "OpenGLModule_Config.hpp"
#include "utils/Buffer.hpp"
#include "utils/Inputs.hpp"

#include <memory>
#include <array>
#include <map>

#define WINDOW_FULLSCREEN_WINDOWED 0
#define WINDOW_FULLSCREEN 0

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT OpenGLModule : public sw::AModule
    {
        private:
            GLFWwindow *m_window{};

            static void resizeCallBack(GLFWwindow* window, int width, int height);
            static void input_callback(GLFWwindow* window, int key, int scancode, int action, [[maybe_unused]] int mods);
            static void mouse_button_callback(GLFWwindow* window, int button, int action,[[maybe_unused]] int mods);
            static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
            static void position_callback(GLFWwindow* window, double xpos, double ypos);
            void setUpCallBack();
        public:
            explicit OpenGLModule();
            ~OpenGLModule() override = default;

            void initialize() override;
            void update() override;
            void terminate() override;
            bool isOk() override;
            [[nodiscard]] std::string type() const override;

            std::unique_ptr<sw::AResources> createResourceInstance() override;
    }; // class OpenGLModule

    ////////////////////////////////////////////////////////////
    /// @brief Return True if given key was pressed
    ///
    /// @param sw::Type& const int&
    /// 
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    bool isKeyPressed(sw::Type&, const int&);//TODO template mouse/keyboard
    
    ////////////////////////////////////////////////////////////
    /// @brief Return True if give key was released
    ///
    /// @param sw::Type& const int&
    /// 
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    bool isKeyReleased(sw::Type&, const int&);//same
    
    ////////////////////////////////////////////////////////////
    /// @brief Return True if given key is held down
    ///
    /// @param sw::Type& const int&
    /// 
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    bool isKeyDown(sw::Type&, const int&);//same
    //bool isKeyUp(sw::Type&, const int&);
    
    ////////////////////////////////////////////////////////////
    /// @brief Return true if given scroll direction is correct
    ///
    /// @param std::pair<double,double>&
    /// 
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    bool mouseScrolled(const std::pair<double,double>&);

    ////////////////////////////////////////////////////////////
    /// @brief Return True if mouse moved
    ///
    /// @param void
    /// 
    /// @return bool
    ///
    /// @throw none
    ////////////////////////////////////////////////////////////
    bool mouseMoved(void);

    #ifdef GRAPHICAL_MODULE
        #undef GRAPHICAL_MODULE
    #endif
    #define GRAPHICAL_MODULE sw::Engine::createModule<OpenGLModule>("OpenGL");
} // namespace sw

#endif //SWENGINE_GRAPHICAL_OPENGLMODULE_HPP
