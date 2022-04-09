/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Scene_Tests.cpp
** Description: [CHANGE]
*/

#include "SceneTester.hpp"

TEST_F (SceneTester, hasEntity)
{
    EXPECT_TRUE(sw::Engine::activeScene().hasEntity("Entity"));
    EXPECT_FALSE(sw::Engine::activeScene().hasEntity("Enti"));
}

TEST_F (SceneTester, deleteRequested)
{
    sw::Engine::activeScene().deleteEntity("Entity");
    sw::Engine::activeScene().update();
    EXPECT_FALSE(sw::Engine::activeScene().hasEntity("Entity"));
}

TEST_F (SceneTester, already_load)
{
    sw::Speech::displayed = true;
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(sw::Engine::activeScene().load());
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();
    EXPECT_NE(str.find("- TestScene - was already loaded !"), std::string::npos);
}

TEST_F (SceneTester, getResources)
{
    EXPECT_NO_THROW(sw::Engine::activeScene().resources());
}

TEST_F (SceneTester, update_once)
{
    EXPECT_NO_THROW(sw::Engine::activeScene().update());
}

TEST_F (SceneTester, update_not_loaded)
{
    sw::Speech::displayed = true;
    EXPECT_NO_THROW(sw::Engine::activeScene().unload());
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(sw::Engine::activeScene().update());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("- TestScene - can not be updated because it was not loaded."), std::string::npos);
}

TEST_F (SceneTester, scene_init_throw)
{
    EXPECT_NO_THROW(sw::Engine::createScene<TestThrowScene>("Throw"));
    sw::Engine::getScene<TestThrowScene>("Throw").m_init = true;
    EXPECT_ANY_THROW(sw::Engine::getScene<TestThrowScene>("Throw").load());
    sw::Engine::getScene<TestThrowScene>("Throw").m_init = false;
}

TEST_F (SceneTester, scene_update_throw)
{
    EXPECT_NO_THROW(sw::Engine::createScene<TestThrowScene>("Throw"));
    EXPECT_NO_THROW(sw::Engine::getScene<TestThrowScene>("Throw").load());
    sw::Engine::getScene<TestThrowScene>("Throw").m_update = true;
    EXPECT_ANY_THROW(sw::Engine::getScene<TestThrowScene>("Throw").update());
    sw::Engine::getScene<TestThrowScene>("Throw").m_update = false;
}

TEST_F (SceneTester, scene_update_manager_throw)
{
    EXPECT_NO_THROW(sw::Engine::createScene<TestThrowScene>("Throw"));
    sw::Engine::getScene<TestThrowScene>("Throw").m_manager = true;
    EXPECT_NO_THROW(sw::Engine::getScene<TestThrowScene>("Throw").load());
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(sw::Engine::getScene<TestThrowScene>("Throw").update());
    sw::Speech::displayed = true;
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();
    EXPECT_NE(str.find("TestCptManagerThrow"), std::string::npos);
    sw::Engine::getScene<TestThrowScene>("Throw").m_manager = false;
}

TEST_F (SceneTester, scene_terminate_throw)
{
    EXPECT_NO_THROW(sw::Engine::createScene<TestThrowScene>("Throw"));
    EXPECT_NO_THROW(sw::Engine::getScene<TestThrowScene>("Throw").load());
    sw::Engine::getScene<TestThrowScene>("Throw").m_term = true;
    EXPECT_ANY_THROW(sw::Engine::getScene<TestThrowScene>("Throw").unload());
    sw::Engine::getScene<TestThrowScene>("Throw").m_term = false;
}

TEST_F (SceneTester, has_facrtory)
{
    EXPECT_TRUE(sw::Engine::activeScene().hasManager("CptManager"));
    EXPECT_FALSE(sw::Engine::activeScene().hasManager("TestCpt"));
}

TEST_F (SceneTester, delete_manager)
{
    sw::Engine::activeScene().createManager<TestCptManager>("test");
    EXPECT_TRUE(sw::Engine::activeScene().hasManager("test"));
    sw::Engine::activeScene().deleteManager("test");
    sw::Engine::activeScene().update();
    EXPECT_FALSE(sw::Engine::activeScene().hasManager("test"));
}

TEST_F (SceneTester, set_layer_manager)
{
    sw::Engine::activeScene().createManager<TestCptManager>("test");
    EXPECT_TRUE(sw::Engine::activeScene().hasManager("test"));
    sw::Engine::activeScene().setLayer("test", 123);
    EXPECT_NO_THROW(sw::Engine::activeScene().setLayer("CManager", 1));
    EXPECT_EQ(sw::Engine::activeScene().getLayer("test"), 123);
    EXPECT_EQ(sw::Engine::activeScene().getLayer("CptManager"), 0);
}

TEST_F (SceneTester, get_layer_manager)
{
    EXPECT_EQ(sw::Engine::activeScene().getLayer("CptManager"), 0);
    EXPECT_ANY_THROW(sw::Engine::activeScene().getLayer("CManager"));
}