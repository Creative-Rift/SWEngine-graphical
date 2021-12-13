/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** AManager.inl
*/

template<sw::ConcreteComponent Cpt>
inline sw::AManager<Cpt>::AManager(const std::string& managerName, AScene& sceneRef)
    :   m_componentMap{},
        m_componentLayer{},
        m_scene{sceneRef},
        m_isActive{true},
        m_name{managerName},
        m_isLoad{false}
{
    m_componentLayer.needSort = true;
}

template<sw::ConcreteComponent Cpt>
inline sw::AManager<Cpt>::~AManager()
{
    m_componentMap.clear();
    m_componentLayer.clear();
}

template <sw::ConcreteComponent Cpt>
template <typename... Args>
inline Cpt& sw::AManager<Cpt>::createComponent(const std::string& entityName, Args... values)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("sw::AManager::createComponent - Entity <" + entityName + "> not found", "4415");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end()) {
        it = m_componentMap.try_emplace(entityName, std::make_unique<Cpt>(m_scene.getEntity(entityName), values...)).first;
        m_componentLayer.emplace_front(std::make_pair(0, entityName));
    }
    return (*it->second);
}

template <sw::ConcreteComponent Cpt>
template <sw::ConcreteComponent ChildCpt, typename... Args>
inline ChildCpt& sw::AManager<Cpt>::createComponent(const std::string& entityName, Args... values)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("sw::AManager::createComponent - Entity <" + entityName + "> not found", "4415");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end()) {
        it = m_componentMap.try_emplace(entityName, std::make_unique<ChildCpt>(m_scene.getEntity(entityName), values...)).first;
        m_componentLayer.emplace_front(std::make_pair(0, entityName));
    }
    return (static_cast<ChildCpt&>(*it->second));
}

template<sw::ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::deleteComponent(const std::string& entityName)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("sw::AManager::deleteComponent - Entity <" + entityName + "> not found", "4415");
    m_componentMap.erase(entityName);
}

template<sw::ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::load()
try
{
    if (m_isLoad) {
        sw::Speech::Warning("Manager <" + m_name + "> it was already loaded !", "3420");
        return;
    }

    if (m_componentLayer.needSort)
        m_componentLayer.sort();
    m_isLoad = true;
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error("Manager <" + m_name + "> can not be loaded.", "4420");
}

template<sw::ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::update()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning("Manager <" + m_name + "> can not be update because it was not loaded.", "3430");
        return;
    }

    if (m_componentLayer.needSort)
        m_componentLayer.sort();
    onUpdate();
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error("Manager <" + m_name + "> can not be updated.", "4430");
}

template<sw::ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::unload()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning("Manager <" + m_name + "> was alredy unloaded !", "3440");
        return;
    }

    m_isLoad = false;
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error("Manager <" + m_name + "> can not be unloaded.", "4440");
}

template<sw::ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::setLayer(const std::string& entityName, int newLayer)
{
    for (auto& [layer, name] : m_componentLayer)
        if (name == entityName) {
            layer = newLayer;
            break;
        }
    m_componentLayer.needSort = true;
}

template<sw::ConcreteComponent Cpt>
inline int sw::AManager<Cpt>::getLayer(const std::string& entityName) const
{
    for (auto& [layer, name] : m_componentLayer)
        if (name == entityName)
            return (layer);
    throw sw::Error("sw::AManager::getLayer - Entity <" + entityName + "> not found", "4415");
}

template <sw::ConcreteComponent Cpt>
inline std::ostream& operator<<(std::ostream& os, sw::AManager<Cpt>& sys)
{
    std::cout << "Display AManager" << std::endl;
    for (auto& [entityName, obj] : sys.m_componentMap)
        std::cout << "  " << entityName << std::endl;
    std::cout << "<------------>" << std::endl << std::endl;
    return (os);
}

template<sw::ConcreteComponent Cpt>
inline Cpt& sw::AManager<Cpt>::operator[](const std::string& entityName)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("sw::AManager::operator[] - Entity <" + entityName + "> not found", "4415");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end())
        throw sw::Error("sw::AManager::operator[] - Component for <" + entityName + "> not found", "4416");
    return (*it->second);
}

template <sw::ConcreteComponent Cpt>
inline std::unordered_map<std::string, std::unique_ptr<Cpt>>::iterator sw::AManager<Cpt>::begin()
{
    return (m_componentMap.begin());
}

template <sw::ConcreteComponent Cpt>
inline std::unordered_map<std::string, std::unique_ptr<Cpt>>::iterator sw::AManager<Cpt>::end()
{
    return (m_componentMap.end());
}

template <sw::ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::setActive(bool value)
{
    m_isActive = value;
}

template<sw::ConcreteComponent Cpt>
sw::AScene& sw::AManager<Cpt>::scene() const
{ return (m_scene); }

template<sw::ConcreteComponent Cpt>
std::string sw::AManager<Cpt>::name() const
{ return (m_name); }

template <sw::ConcreteComponent Cpt>
inline bool sw::AManager<Cpt>::isActive() const
{ return (m_isActive); }


template<sw::ConcreteComponent Cpt>
inline bool sw::AManager<Cpt>::hasComponent(const std::string& entityName) const
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("sw::AManager::operator[] - Entity <" + entityName + "> not found", "4415");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end())
        return (false);
    return (true);
}