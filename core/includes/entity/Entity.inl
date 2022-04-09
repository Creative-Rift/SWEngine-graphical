/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Entity.inl
 *
 * Description:
 * Implementation of Entity functions
 */

inline sw::Entity::Entity(const std::string& entityName, AScene& sceneRef)
    :   m_isActive(true),
        m_name(entityName),
        m_scene(sceneRef)
{}

inline sw::Entity::Entity(const std::string& entityName, AScene& sceneRef, bool isActive)
    :   m_isActive(isActive),
        m_name(entityName),
        m_scene(sceneRef)
{}

inline std::string sw::Entity::name() const
{
    return (m_name);
}

inline sw::AScene& sw::Entity::scene()
{
    return (m_scene);
}

inline bool sw::Entity::isActive() const
{
    return (m_isActive);
}

inline void sw::Entity::setActive(bool value)
{
    m_isActive = value;
}

template<ConcreteComponent Cpt, typename... Args>
inline Cpt& sw::Entity::createComponent(const std::string& managerName, Args... values)
{
    sw::AManager<Cpt>& manager = m_scene.getManager<sw::AManager<Cpt>>(managerName);

    if (manager.hasComponent(m_name))
        sw::Speech::Warning(sw::Log::warning516(FUNCTION, m_name, managerName));
    return (m_scene.getManager<sw::AManager<Cpt>>(managerName).createComponent(m_name, values...));
}

inline bool sw::Entity::hasComponent(const std::string& managerName) const
{
    return (m_scene.getManager(managerName).hasComponent(m_name));
}

template <ConcreteComponent Cpt>
inline Cpt& sw::Entity::getComponent(const std::string& managerName)
try
{
    return (m_scene.getManager<sw::AManager<Cpt>>(managerName)[m_name]);
}
catch (sw::Error& err) {
    throw sw::Error(sw::Log::error516(FUNCTION, m_name, managerName));
}

inline std::ostream& operator<<(std::ostream& os, const sw::Entity& entity)
{
    os  << "Entity '" << entity.name() << "'\n"
        << "\tIs Active : " << std::boolalpha << entity.isActive() << "\n";
    return (os);
}