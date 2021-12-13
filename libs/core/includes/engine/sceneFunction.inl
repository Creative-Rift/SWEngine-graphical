/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** sceneFunction.inl
*/

template <sw::ConcreteScene Scene>
inline Scene& sw::Engine::createScene(const std::string& sceneName)
{
    auto it = m_scenes.find(sceneName);

    if (it == m_scenes.end()) {
        it = m_scenes.emplace(sceneName, std::make_unique<Scene>(sceneName)).first;
        if (m_activeScene.empty())
            m_activeScene = sceneName;
    }
    return (static_cast<Scene&>(*it->second.get()));
}

template <sw::ConcreteScene Scene>
inline Scene& sw::Engine::getScene(const std::string& sceneName)
{
    auto it = m_scenes.find(sceneName);

    if (it == m_scenes.end())
        throw sw::Error("sw::Engine::getScene - Can't find scene <" + sceneName + ">", "4113");
    return (static_cast<Scene&>(*it->second.get()));
}

template <sw::ConcreteScene Scene>
Scene& sw::Engine::activeScene()
{
    auto it = m_scenes.find(m_activeScene);

    if (it == m_scenes.end())
        throw sw::Error("sw::Engine::activeScene - Can't find active scene <" + m_activeScene + ">", "4113");
    return (static_cast<Scene&>(*it->second.get()));
}