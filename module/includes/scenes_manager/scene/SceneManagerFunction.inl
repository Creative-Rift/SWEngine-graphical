/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * SceneManagerFunction.inl
 *
 * Description:
 */

template<ConcreteManager Manager, typename... Args>
inline Manager& sw::Scene::createManager(const std::string& managerName, Args... args)
{
    if (m_managers.contains(managerName))
        sw::Speech::Warning(sw::Log::warning324(FUNCTION, name, managerName));

    auto it = m_managers.try_emplace(managerName, std::make_unique<Manager>(managerName, *this, args...));
    if (it.second)
        m_managersLayers.emplace_front(std::make_pair(0, managerName));
    return (static_cast<Manager&>(*(it.first->second)));
}

inline bool sw::Scene::hasManager(const std::string& managerName)
{
    return (m_managers.contains(managerName));
}

template<ConcreteManager Manager>
inline Manager& sw::Scene::getManager(const std::string& managerName)
try
{
    return (static_cast<Manager&>(*m_managers.at(managerName)));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error314(FUNCTION, name, managerName));
}