/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Engine.cpp
 *
 * Description:
 * Engine functions implementation
 */

#include "../Config.hpp"
#include "engine/Engine.hpp"
#include "EventManager.hpp"

SW_CORE_API_EXPORT std::unordered_map<std::string, std::unique_ptr<sw::AScene>> sw::Engine::m_scenes = {};
SW_CORE_API_EXPORT std::string sw::Engine::m_activeScene = {};
SW_CORE_API_EXPORT std::unique_ptr<sw::AModule> sw::Engine::m_module = nullptr;
SW_CORE_API_EXPORT std::unordered_set<std::string> sw::Engine::m_scenesToDelete = {};
SW_CORE_API_EXPORT std::string sw::Engine::m_nextActiveScene = {};
SW_CORE_API_EXPORT bool sw::Engine::m_moduleToDelete = false;
SW_CORE_API_EXPORT sw::EventManager sw::Engine::m_eventManager = {};
SW_CORE_API_EXPORT bool sw::Engine::m_isLoad = false;

void sw::Engine::initialize()
try
{
    if (m_isLoad) {
        sw::Speech::Warning(sw::Log::warning150(FUNCTION));
        return;
    }

    if (sw::Speech::clearOnPlay)
        sw::Speech::clearConsole();
    sw::Speech::Info(sw::Log::info150(FUNCTION));

    GRAPHICAL_MODULE;
    getModule().initialize();
    m_isLoad = true;

    sw::Speech::Info(sw::Log::info150_Success(FUNCTION));
}
catch (sw::Error& error) {
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw (sw::Error(sw::Log::error150(FUNCTION)));
}

void sw::Engine::update()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning(sw::Log::warning160(FUNCTION));
        return;
    }
    sw::Speech::Info(sw::Log::info160(FUNCTION));

    getModule().update();

    if (!m_nextActiveScene.empty())
        setRequestedActiveScene();

    if (!m_scenesToDelete.empty())
        deleteRequestedScenes();

    if (m_moduleToDelete)
        executeDeleteModule();

    sw::Speech::Info(sw::Log::info160_Success(FUNCTION));
    sw::Speech::flush();
}
catch (sw::Error& error) {
    sw::Speech::Warning(error.getMessage(), error.getCode());
    sw::Speech::flush();
}

void sw::Engine::terminate()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning(sw::Log::warning170(FUNCTION));
        return;
    }
    sw::Speech::Info(sw::Log::info170(FUNCTION));

    for (auto& [_, scene] : m_scenes)
        scene->unload();

    getModule().terminate();
    executeDeleteModule();

    m_scenes.clear();
    m_activeScene.clear();
    m_isLoad = false;

    sw::Speech::Info(sw::Log::info170_Success(FUNCTION));
}
catch (sw::Error& error) {
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw (sw::Error(sw::Log::error170(FUNCTION)));
}

void sw::Engine::display(std::ostream& os, bool dispContent)
{
    os  << "Engine :\n"
        << "\tIs Load :" << std::boolalpha << m_isLoad << "\n"
        << "\tModule type : '" << m_module->type() << "'\n"
        << "\tScene count : " << m_scenes.size() << "\n"
        << "\tActive Scene : '" << m_activeScene << "'\n";
    if (dispContent) {
        os << "Scene list :\n";
        for (auto& [name, scene] : m_scenes)
            os << "\t\t'" << name << "' of type '" << scene->type() << "'\n";
    }
}

void sw::Engine::setModule(std::unique_ptr<AModule> &&module)
{
    m_module = std::move(module);
}

bool sw::Engine::isLoad()
{
    return (m_isLoad);
}

sw::EventManager& sw::Engine::eventManager()
{
    return (m_eventManager);
}

std::string sw::Engine::activeSceneName()
{
    return (m_activeScene);
}

void sw::Engine::setActiveSceneName(const std::string& newSceneName)
{
    m_activeScene = std::string(newSceneName);
}

std::unordered_map<std::string, std::unique_ptr<sw::AScene>> &sw::Engine::getScenes()
{
    return (m_scenes);
}

bool sw::Engine::hasModule()
{
    return (m_module != nullptr);
}

bool sw::Engine::hasScene(const std::string sceneName)
{
    return (getScenes().contains(sceneName));
}