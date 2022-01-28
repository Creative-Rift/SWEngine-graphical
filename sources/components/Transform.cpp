/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Transform.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"

sw::Transform::Transform(sw::Entity& entityRef)
        :   sw::Component(entityRef),
            m_position(0, 0, 0),
            m_globalPosition(0, 0, 0),
            m_scale(1, 1, 1),
            m_globalScale(1, 1, 1),
            m_angle(0),
            m_rotation(0, 0, 0),
            m_globalRotation(0, 0, 0),
            m_matrix(3),
            m_globalMatrix(3),
            m_need_update(false),
            m_global_need_update(false)
{
    m_matrix.setIdentity();
}

bool sw::Transform::checkUpdate() const
{
    return (m_need_update
            && m_global_need_update);
}

void sw::Transform::updateSfTransform() const
{
    std::vector<std::vector<float>> resultFlist = m_matrix.getMatrix();

    //m_sfTransform = sf::Transform(resultFlist[0][0], resultFlist[0][1], resultFlist[0][2],
    //                              resultFlist[1][0], resultFlist[1][1], resultFlist[1][2],
    //                              resultFlist[2][0], resultFlist[2][1], resultFlist[2][2]);
}

//const sf::Transform& sfml::Transform::getTransform() const
//{
//    if (m_need_update) {
//        updateMatrix();
//        updateSfTransform();
//        m_need_update = false;
//    }
//    return (m_sfTransform);
//}

void sw::Transform::updateGlobalSfTransform() const
{
    std::vector<std::vector<float>> resultFlist = m_globalMatrix.getMatrix();

    // m_globalSfTransform = sf::Transform(resultFlist[0][0], resultFlist[0][1], resultFlist[0][2],
    //                                     resultFlist[1][0], resultFlist[1][1], resultFlist[1][2],
    //                                     resultFlist[2][0], resultFlist[2][1], resultFlist[2][2]);
}

//const sf::Transform& sfml::Transform::getGlobalTransform() const
//{
//    if (m_global_need_update) {
//        m_globalMatrix = getGlobalMatrix();
//        updateGlobalSfTransform();
//        m_global_need_update = false;
//    }
//    return (m_sfTransform);
//}