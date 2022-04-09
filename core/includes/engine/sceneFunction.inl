/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * sceneFunction.inl
 *
 * Description:
 * Implementation of Engine functions for Scene
 */

template <ConcreteScene Scene, typename... Args>
inline Scene& sw::Engine::createScene(const std::string& sceneName, Args... args)
{
    if (hasScene(sceneName))
        sw::Speech::Warning(sw::Log::warning123(FUNCTION, sceneName));

    auto it = getScenes().try_emplace(sceneName, std::make_unique<Scene>(sceneName, args...));
    if (it.second && activeSceneName().empty())
        setActiveSceneName(sceneName);
    return (static_cast<Scene&>(*(it.first->second)));
}

template <ConcreteScene Scene>
inline Scene& sw::Engine::getScene(const std::string sceneName)
try
{
    return (static_cast<Scene&>(*getScenes().at(sceneName)));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error113(FUNCTION, sceneName));
}

template <ConcreteScene Scene>
Scene& sw::Engine::activeScene()
try
{
    return (static_cast<Scene&>(*getScenes().at(activeSceneName())));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error113(FUNCTION, activeSceneName()));
}