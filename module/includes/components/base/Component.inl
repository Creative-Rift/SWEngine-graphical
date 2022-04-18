/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Component.inl
 *
 * Description:
 * Implementation of Component functions
 */

#ifndef __SHIPWRECK_CORE_COMPONENT_INL__
#define __SHIPWRECK_CORE_COMPONENT_INL__

inline sw::Component::Component(GameObject& gameObjectRef)
    :   m_isActive{true},
        m_gameObject{gameObjectRef}
{}

inline std::string sw::Component::name() const
{
    return (m_gameObject.name());
}

inline void sw::Component::setActive(bool value)
{
    m_isActive = value;
}

inline bool sw::Component::isActive() const
{
    return (m_isActive);
}

inline sw::GameObject& sw::Component::gameObject() const
{
    return (m_gameObject);
}

#endif // __SHIPWRECK_CORE_COMPONENT_INL__