/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * managerFunction.inl
 *
 * Description:
 * Implementation of Scene Managers functions
 */

template<ConcreteManager Manager, typename... Args>
inline Manager& sw::AScene::createManager(const std::string& managerName, Args... args)
{
    if (m_managers.contains(managerName))
        sw::Speech::Warning(sw::Log::warning324(FUNCTION, m_name, managerName));

    auto it = m_managers.try_emplace(managerName, std::make_unique<Manager>(managerName, *this, args...));
    if (it.second)
        m_managersLayers.emplace_front(std::make_pair(0, managerName));
    return (static_cast<Manager&>(*(it.first->second)));
}

inline bool sw::AScene::hasManager(const std::string& managerName)
{
    return (m_managers.contains(managerName));
}

template<ConcreteManager Manager>
inline Manager& sw::AScene::getManager(const std::string& managerName)
try
{
    return (static_cast<Manager&>(*m_managers.at(managerName)));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error314(FUNCTION, m_name, managerName));
}

inline std::size_t sw::AScene::managersCount() const
{
    return (m_managers.size());
}