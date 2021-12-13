/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: EventListener.cpp
** Description: [CHANGE]
*/

template<sw::ConcreteComponent Cpt>
sw::EventListener<Cpt>::EventListener(Cpt& obj, void (Cpt::*call)())
    :   m_cpt{obj},
        m_call{call}
{}

template<sw::ConcreteComponent Cpt>
sw::EventListener<Cpt>::EventListener(Cpt& obj, void (Cpt::*call)(EventInfo&))
    :   m_cpt{obj},
        m_call{call}
{}

template<sw::ConcreteComponent Cpt>
inline void sw::EventListener<Cpt>::catchEvent()
{
    auto& call = std::get<void (Cpt::*)()>(m_call);
    ((m_cpt).*call)();
}

template<sw::ConcreteComponent Cpt>
inline void sw::EventListener<Cpt>::catchEvent(EventInfo& info)
{
    auto& call = std::get<void (Cpt::*)(EventInfo&)>(m_call);
    ((m_cpt).*call)(info);
}

template<sw::ConcreteComponent Cpt>
inline std::string sw::EventListener<Cpt>::linkedEntity() const
{
    return (m_cpt.entity().name());
}