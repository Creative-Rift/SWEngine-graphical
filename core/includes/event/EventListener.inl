/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * EventListener.inl
 *
 * Description:
 * Implementation of EventListener functions
 */

template<EventCallable Element>
inline sw::EventListener<Element>::EventListener(Element& obj, void (Element::*call)())
    :   m_element{obj},
        m_call{call}
{}

template<EventCallable Element>
inline sw::EventListener<Element>::EventListener(Element& obj, void (Element::*call)(EventInfo&))
    :   m_element{obj},
        m_call{call}
{}

template<EventCallable Element>
inline void sw::EventListener<Element>::catchEvent()
try
{
    auto& call = std::get<void (Element::*)()>(m_call);
    ((m_element).*call)();
}
catch (std::bad_variant_access&)
{
    sw::Speech::Warning(sw::Log::warningC40(FUNCTION, m_element.entity().name()));
}

template<EventCallable Element>
inline void sw::EventListener<Element>::catchEvent(EventInfo& info)
try
{
    auto& call = std::get<void (Element::*)(EventInfo&)>(m_call);
    ((m_element).*call)(info);
}
catch (std::bad_variant_access&)
{
    sw::Speech::Warning(sw::Log::warningC40(FUNCTION, m_element.entity().name()));
}

template<EventCallable Element>
inline std::string sw::EventListener<Element>::linkedElement() const
{
    return (m_element.name());
}