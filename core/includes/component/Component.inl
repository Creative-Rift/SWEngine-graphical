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

inline sw::Component::Component(sw::Entity& entityRef)
    :   m_isActive{true},
        m_entity{entityRef}
{}

inline std::string sw::Component::name() const
{
    return (m_entity.name());
}

inline void sw::Component::setActive(bool value)
{
    m_isActive = value;
}

inline bool sw::Component::isActive() const
{
    return (m_isActive);
}

inline sw::Entity& sw::Component::entity() const
{
    return (m_entity);
}

inline std::string sw::Component::type() const
{
    return ("Component");
}

inline std::ostream& operator<<(std::ostream& os, const sw::Component& cpt )
{
    os << "Component [" << cpt.type() << "] of " << cpt.entity().name() << "\n";
    return (os);
}

#endif // __SHIPWRECK_CORE_COMPONENT_INL__