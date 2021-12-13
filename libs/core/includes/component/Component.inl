/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Component.inl
** Description: [CHANGE]
*/

#ifndef SWENGINE_CORE_TESTS_COMPONENT_INL
#define SWENGINE_CORE_TESTS_COMPONENT_INL

inline std::ostream& operator<<(std::ostream& os, sw::Component& cpt )
{
    os << "Component of " << cpt.entity().name();
    return (os);
}

#endif //SWENGINE_CORE_TESTS_COMPONENT_INL
