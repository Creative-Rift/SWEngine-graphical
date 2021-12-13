/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** moduleFunction.inl
*/

template <sw::ConcreteModule Module>
inline Module& sw::Engine::createModule(const std::string& moduleName)
{
    auto it = m_modules.find(moduleName);

    if (it == m_modules.end()) {
        it = m_modules.emplace(moduleName, std::make_unique<Module>(moduleName)).first;
        if (m_activeModule.empty())
            m_activeModule = moduleName;
    }
    return (static_cast<Module&>(*it->second.get()));
}

template <sw::ConcreteModule Module>
inline Module& sw::Engine::getModule(const std::string& moduleName)
{
    auto it = m_modules.find(moduleName);

    if (it == m_modules.end())
        throw sw::Error("sw::Engine::getModule - Can't find Module <" + moduleName + ">", "4112");
    return (static_cast<Module&>(*it->second.get()));
}

template <sw::ConcreteModule Module>
Module& sw::Engine::activeModule()
{
    auto it = m_modules.find(m_activeModule);

    if (it == m_modules.end())
        throw sw::Error("sw::Engine::activeModule - Can't find Module <" + m_activeModule + ">", "4112");
    return (static_cast<Module&>(*it->second.get()));
}