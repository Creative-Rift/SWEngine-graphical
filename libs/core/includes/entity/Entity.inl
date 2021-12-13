/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Entity.inl
*/

template<sw::ConcreteComponent Cpt, typename... Args>
inline Cpt& sw::Entity::createComponent(const std::string& managerName, Args... values)
{
    return (m_scene.getManager<sw::AManager<Cpt>>(managerName).createComponent(m_name, values...));
}

template <sw::ConcreteComponent Cpt>
inline Cpt& sw::Entity::getComponent(const std::string& managerName)
try
{
    return (m_scene.getManager<sw::AManager<Cpt>>(managerName)[m_name]);
}
catch (sw::Error& err) {
    throw sw::Error("sw::Entity::getComponent - Component for <" + m_name + "> not found in <" + managerName + ">", "4416");
}