/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * GameObject.inl
 *
 * Description:
 */

inline sw::GameObject::GameObject(const std::string& GameObjectName, sw::Scene& sceneRef)
        :   m_isActive(true),
            m_name(GameObjectName),
            m_scene(sceneRef)
{}

inline sw::GameObject::GameObject(const std::string& gameObjectName, sw::Scene& sceneRef, bool isActive)
        :   m_isActive(isActive),
            m_name(gameObjectName),
            m_scene(sceneRef)
{}

inline sw::Scene& sw::GameObject::scene()
{
    return (m_scene);
}

inline bool sw::GameObject::isActive() const
{
    return (m_isActive);
}

inline void sw::GameObject::setActive(bool value)
{
    m_isActive = value;
}

template<sw::ConcreteComponent Cpt, typename... Args>
inline Cpt& sw::GameObject::createComponent(const std::string& managerName, Args... values)
{
    sw::AManager<Cpt>& manager = m_scene.getManager<sw::AManager<Cpt>>(managerName);

    if (manager.hasComponent(m_name))
        sw::Speech::Warning(sw::Log::warning516(FUNCTION, m_name, managerName));
    return (m_scene.getManager<sw::AManager<Cpt>>(managerName).createComponent(m_name, values...));
}

inline bool sw::GameObject::hasComponent(const std::string& managerName) const
{
    return (m_scene.getManager(managerName).hasComponent(m_name));
}

template <sw::ConcreteComponent Cpt>
inline Cpt& sw::GameObject::getComponent(const std::string& managerName)
try
{
    return (m_scene.getManager<sw::AManager<Cpt>>(managerName)[m_name]);
}
catch (sw::Error& err) {
    throw sw::Error(sw::Log::error516(FUNCTION, m_name, managerName));
}