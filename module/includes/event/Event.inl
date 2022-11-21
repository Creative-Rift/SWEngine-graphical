/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Event.inl
 *
 * Description:
 * Implementation of Event functions
 */

inline sw::Event::Event()
    :   m_listenerList{}
{}

template <class Cpt>
inline void sw::Event::subscribe(std::string name, Cpt* cpt, void (Cpt::*call)())
{
    m_listenerList.emplace(name, std::make_shared<EventListener<Cpt>>(*cpt, call));
}

template <class Cpt>
inline void sw::Event::subscribe(std::string name, Cpt* cpt, void (Cpt::*call)(EventInfo&))
{
    m_listenerList.emplace(name, std::make_shared<EventListener<Cpt>>(*cpt, call));
}