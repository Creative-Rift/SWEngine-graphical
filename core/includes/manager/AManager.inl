/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AManager.inl
 *
 * Description:
 * Implementation of Manager functions
 */

template<ConcreteComponent Cpt>
inline sw::AManager<Cpt>::AManager(const std::string& managerName, sw::AScene& sceneRef)
    :   m_isLoad{false},
        m_componentToDelete{},
        m_name{managerName},
        m_scene{sceneRef},
        m_isActive{true},
        m_components{},
        m_componentsLayers{}
{
    m_componentsLayers.needSort = true;
}

template<ConcreteComponent Cpt>
inline sw::AManager<Cpt>::~AManager()
{
    m_components.clear();
    m_componentsLayers.clear();
}

template <ConcreteComponent Cpt>
template <typename... Args>
inline Cpt& sw::AManager<Cpt>::createComponent(const std::string& entityName, Args... values)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error(sw::Log::error415(FUNCTION, m_name, entityName, m_scene.name()));
    if (m_components.contains(entityName))
        sw::Speech::Warning(sw::Log::warning426(FUNCTION, m_name, entityName));

    auto it = m_components.try_emplace(entityName, std::make_shared<Cpt>(m_scene.getEntity(entityName), values...));
    if (it.second)
        m_componentsLayers.emplace_front(std::make_pair(0, entityName));
    return (*(it.first->second));
}

template <ConcreteComponent Cpt>
template <ConcreteChild<Cpt> ChildCpt, typename... Args>
inline ChildCpt& sw::AManager<Cpt>::createComponent(const std::string& entityName, Args... values)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error(sw::Log::error415(FUNCTION, m_name, entityName, m_scene.name()));
    if (m_components.contains(entityName))
        sw::Speech::Warning(sw::Log::warning426(FUNCTION, m_name, entityName));

    auto it = m_components.try_emplace(entityName, std::make_shared<ChildCpt>(m_scene.getEntity(entityName), values...));
    if (it.second)
        m_componentsLayers.emplace_front(std::make_pair(0, entityName));
    return (static_cast<ChildCpt&>(*(it.first->second)));
}

template<ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::deleteComponent(const std::string& entityName)
{
    if (!m_components.contains(entityName)) {
        sw::Speech::Warning(sw::Log::warning436(FUNCTION, m_name, entityName));
        return;
    }
    m_componentToDelete.emplace(entityName);
}

template<ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::load()
try
{
    if (m_isLoad) {
        sw::Speech::Warning(sw::Log::warning450(FUNCTION, m_name));
        return;
    }

    if (m_componentsLayers.needSort)
        m_componentsLayers.sort();
    m_isLoad = true;
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error(sw::Log::error450(FUNCTION, m_name));
}

template<ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::update()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning(sw::Log::warning460(FUNCTION, m_name));
        return;
    }

    if (m_componentsLayers.needSort)
        m_componentsLayers.sort();

    deleteRequestedComponents();

    onUpdate();
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error(sw::Log::error460(FUNCTION, m_name));
}

template<ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::unload()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning(sw::Log::warning470(FUNCTION, m_name));
        return;
    }

    m_isLoad = false;
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error(sw::Log::error470(FUNCTION, m_name));
}

template<ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::setLayer(const std::string& entityName, int value)
{
    if (!m_components.contains(entityName)) {
        sw::Speech::Warning(sw::Log::warning416(FUNCTION, m_name, entityName));
        return;
    }
    for (auto& [layer, name] : m_componentsLayers)
        if (name == entityName) {
            layer = value;
            break;
        }
    m_componentsLayers.needSort = true;
}

template<ConcreteComponent Cpt>
inline int sw::AManager<Cpt>::getLayer(const std::string& entityName) const
{
    if (m_components.contains(entityName))
        for (auto& [layer, name] : m_componentsLayers)
            if (name == entityName)
                return (layer);
    throw sw::Error(sw::Log::error416(FUNCTION, m_name, entityName));
}

template<ConcreteComponent Cpt>
inline Cpt& sw::AManager<Cpt>::operator[](const std::string& entityName)
try
{
    return (*m_components.at(entityName));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error416(FUNCTION, m_name, entityName));
}

template<ConcreteComponent Cpt>
Cpt& sw::AManager<Cpt>::Components::get(const std::string& entityName)
try
{
    return (*(this->at(entityName)));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error416(FUNCTION, m_name, entityName));
}

template<ConcreteComponent Cpt>
const Cpt& sw::AManager<Cpt>::Components::get(const std::string& entityName) const
try
{
    return (*(this->at(entityName)));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error416(FUNCTION, m_name, entityName));
}

template<ConcreteComponent Cpt>
inline Cpt& sw::AManager<Cpt>::getComponent(const std::string& entityName)
try
{
    return (*m_components.at(entityName));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error416(FUNCTION, m_name, entityName));
}

template<ConcreteComponent Cpt>
template<ConcreteChild<Cpt> ChildCpt>
inline ChildCpt& sw::AManager<Cpt>::getComponent(const std::string& entityName)
try
{
    return (static_cast<ChildCpt&>(*m_components.at(entityName)));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error416(FUNCTION, m_name, entityName));
}

template <ConcreteComponent Cpt>
inline std::unordered_map<std::string, std::shared_ptr<Cpt>>::iterator sw::AManager<Cpt>::begin()
{
    return (m_components.begin());
}

template <ConcreteComponent Cpt>
inline std::unordered_map<std::string, std::shared_ptr<Cpt>>::iterator sw::AManager<Cpt>::end()
{
    return (m_components.end());
}

template <ConcreteComponent Cpt>
inline void sw::AManager<Cpt>::setActive(bool value)
{
    m_isActive = value;
}

template<ConcreteComponent Cpt>
bool sw::AManager<Cpt>::isLoad() const
{
    return (m_isLoad);
}

template<ConcreteComponent Cpt>
sw::AScene& sw::AManager<Cpt>::scene() const
{ return (m_scene); }

template<ConcreteComponent Cpt>
std::string sw::AManager<Cpt>::name() const
{ return (m_name); }

template<ConcreteComponent Cpt>
std::string AManager<Cpt>::type() const
{
    return ("AManager");
}

template <ConcreteComponent Cpt>
inline bool sw::AManager<Cpt>::isActive() const
{ return (m_isActive); }

template<ConcreteComponent Cpt>
inline bool sw::AManager<Cpt>::hasComponent(const std::string& entityName) const
{
    return (m_components.contains(entityName));
}

template<ConcreteComponent Cpt>
void sw::AManager<Cpt>::eraseComponents()
{
    for (auto& [name, _] : m_components)
        deleteComponent(name);
}

template<ConcreteComponent Cpt>
std::size_t sw::AManager<Cpt>::componentsCount() const
{
    return (m_components.size());
}

template<ConcreteComponent Cpt>
void sw::AManager<Cpt>::deleteRequestedComponents()
{
    for (auto cptName : m_componentToDelete) {
        m_components.erase(cptName);
        for (auto& [layer, name] : m_componentsLayers)
            if (name == cptName) {
                m_componentsLayers.remove(std::pair<int, std::string>(layer, name));
                break;
            }
    }
    m_componentToDelete.clear();
}

template <ConcreteComponent Cpt>
inline std::ostream& operator<<(std::ostream& os, const sw::AManager<Cpt>& manager)
{
    os  << "Manager '" << manager.name() << "'\n"
        << "\tType : '" << manager.type() << "'\n"
        << "\tIs Load : " << std::boolalpha << manager.isLoad() << "\n"
        << "\tIs Active : " << std::boolalpha << manager.isActive() << "\n"
        << "\nComponents count : " << manager.componentsCount() << "\n";
    return (os);
}