/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * entityFunction.inl
 *
 * Description:
 * Implementation of Scene Entities functions
 */

inline bool sw::AScene::hasEntity(const std::string& entityName)
{
    return (m_entities.contains(entityName));
}

inline std::size_t sw::AScene::entitiesCount() const
{
    return (m_entities.size());
}