/*
** EPITECH PROJECT, 2021
** Software Engine Project
** File description:
** GameObject_Test.cpp
*/

#include "GameObjectTester.hpp"

// TODO Fix comment

TEST_F (GameObjectTester, Constructor)
{
    std::string str = "GameObject";
    sw::GameObject GameObject = sw::GameObject(str, *m_scene);

    EXPECT_EQ    ( GameObject.name(), "GameObject"         );
    EXPECT_TRUE  ( GameObject.isActive()               );
    //EXPECT_EQ    ( GameObject.scene(), *m_scene );
    EXPECT_TRUE  ( GameObject.m_childrenMap.empty()    );
    EXPECT_FALSE ( GameObject.m_parent.hasValue()      );
    (*m_scene).deleteGameObject("GameObject");
}

TEST_F (GameObjectTester, constructor_bis)
{
    sw::GameObject GameObject = sw::GameObject("GameObject", *m_scene, false);

    EXPECT_EQ    ( GameObject.name(), "GameObject"        );
    EXPECT_FALSE ( GameObject.isActive()               );
    //EXPECT_EQ    ( GameObject.scene(), *m_scene );
    EXPECT_TRUE  ( GameObject.m_childrenMap.empty()    );
    EXPECT_FALSE ( GameObject.m_parent.hasValue()      );
    (*m_scene).deleteGameObject("GameObject");
}

TEST_F (GameObjectTester, setActive)
{
    sw::GameObject GameObject = sw::GameObject("GameObject", *m_scene);

    EXPECT_NO_THROW( GameObject.setActive(true)  );
    EXPECT_TRUE    ( GameObject.isActive()       );
    EXPECT_NO_THROW( GameObject.setActive(false) );
    EXPECT_FALSE   ( GameObject.isActive()       );
    EXPECT_NO_THROW( GameObject.setActive(false) );
    EXPECT_FALSE   ( GameObject.isActive()       );
    EXPECT_NO_THROW( GameObject.setActive(true)  );
    EXPECT_TRUE    ( GameObject.isActive()       );
    (*m_scene).deleteGameObject("GameObject");
}

TEST_F (GameObjectTester, addChild)
{
    sw::GameObject& GameObject = (*m_scene).createGameObject("GameObject");
    sw::GameObject& child = (*m_scene).createGameObject("Child");

    GameObject.addChild("Child");

    EXPECT_NE(GameObject.m_childrenMap.find("Child"), GameObject.m_childrenMap.end());
    //EXPECT_EQ(child.m_parent, GameObject);
}

TEST_F (GameObjectTester, create_component)
{
    sw::GameObject& GameObject = (*m_scene).createGameObject("GameObject");

    EXPECT_NO_THROW(GameObject.createComponent<TestComponent>("CptManager"));
    EXPECT_NO_THROW(GameObject.getComponent<TestComponent>("CptManager"));
}

TEST_F (GameObjectTester, create_wrong_component)
{
    sw::GameObject& GameObject = (*m_scene).createGameObject("GameObject");

    EXPECT_ANY_THROW(GameObject.createComponent<TestComponent>("CptMnager"));
    EXPECT_ANY_THROW(GameObject.getComponent<TestComponent>("CptManager"));
}

TEST_F (GameObjectTester, get_wrong_GameObject)
{
    EXPECT_ANY_THROW((*m_scene).getGameObject("oui"));
}