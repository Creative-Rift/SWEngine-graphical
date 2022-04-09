/*
** EPITECH PROJECT, 2021
** Software Engine Project
** File description:
** Entity_Test.cpp
*/

#include "SW/Entity.hpp"

#include "testHeader.hpp"

TEST_F (EntityTester, Constructor)
{
    sw::Entity entity = sw::Entity("Entity", *testScene);

    EXPECT_EQ    ( entity.name(), "Entity"         );
    EXPECT_TRUE  ( entity.isActive()               );
    EXPECT_EQ    ( entity.scene(), *testScene );
    EXPECT_TRUE  ( entity.m_childrenMap.empty()    );
    EXPECT_FALSE ( entity.m_parent.hasValue()      );
    (*testScene).deleteEntity("Entity");
}

TEST_F (EntityTester, constructor_bis)
{
    sw::Entity entity = sw::Entity("Entity", *testScene, false);

    EXPECT_EQ    ( entity.name(), "Entity"        );
    EXPECT_FALSE ( entity.isActive()               );
    EXPECT_EQ    ( entity.scene(), *testScene );
    EXPECT_TRUE  ( entity.m_childrenMap.empty()    );
    EXPECT_FALSE ( entity.m_parent.hasValue()      );
    (*testScene).deleteEntity("Entity");
}

TEST_F (EntityTester, setActive)
{
    sw::Entity entity = sw::Entity("Entity", *testScene);

    EXPECT_NO_THROW( entity.setActive(true)  );
    EXPECT_TRUE    ( entity.isActive()       );
    EXPECT_NO_THROW( entity.setActive(false) );
    EXPECT_FALSE   ( entity.isActive()       );
    EXPECT_NO_THROW( entity.setActive(false) );
    EXPECT_FALSE   ( entity.isActive()       );
    EXPECT_NO_THROW( entity.setActive(true)  );
    EXPECT_TRUE    ( entity.isActive()       );
    (*testScene).deleteEntity("Entity");
}

TEST_F (EntityTester, addChild)
{
    sw::Entity& entity = (*testScene).createEntity("Entity");
    sw::Entity& child = (*testScene).createEntity("Child");

    entity.addChild("Child");

    EXPECT_NE(entity.m_childrenMap.find("Child"), entity.m_childrenMap.end());
    EXPECT_EQ(child.m_parent, entity);
}

TEST_F (EntityTester, create_component)
{
    sw::Entity& entity = (*testScene).createEntity("Entity");

    EXPECT_NO_THROW(entity.createComponent<TestComponent>("CptManager"));
    EXPECT_NO_THROW(entity.getComponent<TestComponent>("CptManager"));
}

TEST_F (EntityTester, create_wrong_component)
{
    sw::Entity& entity = (*testScene).createEntity("Entity");

    EXPECT_ANY_THROW(entity.createComponent<TestComponent>("CptMnager"));
    EXPECT_ANY_THROW(entity.getComponent<TestComponent>("CptManager"));
}

TEST_F (EntityTester, get_wrong_entity)
{
    EXPECT_ANY_THROW((*testScene).getEntity("oui"));
}