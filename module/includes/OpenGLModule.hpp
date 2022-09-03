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
#include "utils/Reference.hpp"
#include "event/EventManager.hpp"

#include <memory>
#include <array>
#include <map>

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT OpenGLModule
    {
        private:
            static bool m_isLoad;
            static sw::Chrono m_chronoWindow;
            static ALCdevice *m_audioDevice;
            static ALCcontext *m_audioContext;
            static double m_frameRate;

            static std::vector<std::string> m_devices;

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
            static bool isRunning();
            static SceneManager& sceneManager();
            static EventManager& eventManager();
            static void CheckOpenOperation();
            [[nodiscard]] std::string type() const;

            std::shared_ptr<sw::AResources> createResourceInstance();

            static void setFrameRateLimit(unsigned int frameRate);
    }; // class OpenGLModule
} // namespace sw

#endif //SWENGINE_GRAPHICAL_OPENGLMODULE_HPP
