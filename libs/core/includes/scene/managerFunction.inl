/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** managerFunction.inl
*/

template<sw::ConcreteManager Manager, typename... Args>
inline Manager& sw::AScene::createManager(const std::string& managerName, Args... args)
{
    auto it = m_managerMap.find(managerName);

    if (it == m_managerMap.end()) {
        it = m_managerMap.emplace(managerName, std::make_unique<Manager>(managerName, *this, args...)).first;
        m_managerLayer.emplace_front(std::make_pair(0, managerName));
    }
    return (static_cast<Manager&>(*it->second.get()));
}

template<sw::ConcreteManager Manager>
inline Manager& sw::AScene::getManager(const std::string& managerName)
{
    auto it = m_managerMap.find(managerName);

    if (it == m_managerMap.end())
        throw sw::Error("sw::scene::getManager - scene <" + m_name + "> can't find Manager <" + managerName + ">", "4314");
    return (static_cast<Manager&>(*it->second.get()));
}