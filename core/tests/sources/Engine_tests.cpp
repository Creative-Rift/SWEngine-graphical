/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Engine_tests.cpp
** Description: [CHANGE]
*/

#include "Engine_tests.hpp"

#include "SW/utils/Speech.hpp"

TEST_F (EngineTester, init_normal_end)
{
    ASSERT_NO_THROW(sw::Engine::initialize());
    EXPECT_NO_THROW(sw::Engine::terminate());
}

/*
TEST_F (EngineTester, init_throw)
{
    EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::Engine::getModule()).m_initThrow = true);
    ASSERT_ANY_THROW(sw::Engine::initialize());
    EXPECT_NO_THROW(sw::Engine::terminate());
    EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::Engine::getModule()).m_initThrow = false);
}
*/

TEST_F (EngineTester, clear_on_play)
{
    sw::Speech::clearOnPlay = true;
    EXPECT_NO_THROW(sw::Engine::initialize());
    EXPECT_NO_THROW(sw::Engine::terminate());
}

TEST_F (EngineTester, init_alreadyLoaded_end)
{
    testing::internal::CaptureStdout();
    sw::Speech::displayed = true;

    sw::Engine::initialize();
    sw::Speech::clearConsole();
    ASSERT_NO_THROW(sw::Engine::initialize());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("Engine is already initialize"), std::string::npos);
    EXPECT_NO_THROW(sw::Engine::terminate());
}

TEST_F (EngineTester, update_once)
{
    testing::internal::CaptureStdout();
    sw::Speech::displayed = true;

    ASSERT_NO_THROW(sw::Engine::initialize());
    sw::Speech::clearConsole();
    EXPECT_NO_THROW(sw::Engine::update());
    sw::Speech::flush();
    EXPECT_NO_THROW(sw::Engine::terminate());
    EXPECT_NE(testing::internal::GetCapturedStdout().find("Engine was successfully updated !"), std::string::npos);
}

TEST_F (EngineTester, update_throw)
{
    sw::Speech::displayed = true;
    ASSERT_NO_THROW(sw::Engine::initialize());
    EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::Engine::getModule()).m_updateThrow = true);
    EXPECT_NO_THROW(sw::Engine::update());
    EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::Engine::getModule()).m_updateThrow = false);
    EXPECT_NO_THROW(sw::Engine::terminate());
}

/*
TEST_F (EngineTester, update_noLoaded)
{
    sw::Speech::displayed = true;

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(sw::Engine::update());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("Engine can not be update because it was not loaded !"), std::string::npos);
    EXPECT_NO_THROW(sw::Engine::terminate());
}
*/

TEST_F (EngineTester, terminate)
{
    testing::internal::CaptureStdout();
    sw::Speech::displayed = true;

    ASSERT_NO_THROW(sw::Engine::initialize());
    sw::Speech::clearConsole();
    EXPECT_NO_THROW(sw::Engine::terminate());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("Engine was successfully terminated !"), std::string::npos);
}

TEST_F (EngineTester, end_throw)
{
    EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::Engine::getModule()).m_endThrow = true);
    ASSERT_NO_THROW(sw::Engine::initialize());
    EXPECT_ANY_THROW(sw::Engine::terminate());
    EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::Engine::getModule()).m_endThrow = false);
}

TEST_F (EngineTester, getModule)
{
    EXPECT_NO_THROW(sw::Engine::getModule<EngineTestModule>());
}

/*
TEST_F (EngineTester, get_wrong_module)
{
    EXPECT_ANY_THROW(sw::Engine::getModule<EngineTestModule>());
}
*/

TEST_F (EngineTester, getModule_2)
{
    ASSERT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::Engine::getModule()));
    EngineTestModule module = dynamic_cast<EngineTestModule&>(sw::Engine::getModule());
}

TEST_F (EngineTester, getModule_bis)
{
    EXPECT_NO_THROW(sw::Engine::getModule());
}

TEST_F (EngineTester, getActive_no_active)
{
    sw::Engine::initialize();
    sw::Engine::terminate();
    EXPECT_ANY_THROW(sw::Engine::getModule());
}

TEST_F (EngineTester, getModule_template)
{
    EXPECT_NO_THROW(sw::Engine::getModule<EngineTestModule>());
}

TEST_F (EngineTester, getActive_no_active_template)
{
    sw::Engine::initialize();
    sw::Engine::terminate();
    EXPECT_ANY_THROW(sw::Engine::getModule<EngineTestModule>());
}

/*
TEST_F (EngineTester, remove_module)
{
    sw::Engine::initialize();
    EXPECT_TRUE(sw::Engine::hasModule());
    EXPECT_NO_THROW(sw::Engine::deleteModule());
    sw::Engine::update();
    EXPECT_FALSE(sw::Engine::hasModule());
    sw::Engine::terminate();
}
*/

TEST_F (EngineTester, createScene)
{
    sw::Engine::createScene<EngineTestScene>("EngineTestsScene");

    EXPECT_NO_THROW(EXPECT_STREQ(sw::Engine::getScene<EngineTestScene>("EngineTestsScene").name().c_str(), "EngineTestsScene"));
}

TEST_F (EngineTester, get_wrong_scene)
{
    EXPECT_ANY_THROW(sw::Engine::getScene<EngineTestScene>("scene"));
}

TEST_F (EngineTester, get_scene_cast)
{
    sw::Engine::initialize();
    EXPECT_NO_THROW(dynamic_cast<EngineTestScene&>(sw::Engine::getScene("TestScene")));
    sw::Engine::terminate();
}

TEST_F (EngineTester, get_wrong_scene_cast)
{
    sw::Engine::initialize();
    EXPECT_ANY_THROW(dynamic_cast<EngineTestScene&>(sw::Engine::getScene("TestsScene")));
    sw::Engine::terminate();
}

TEST_F (EngineTester, activeScene)
{
    sw::Engine::initialize();
    EXPECT_NO_THROW(EXPECT_STREQ(sw::Engine::activeScene<EngineTestScene>().name().c_str(), "TestScene"));
    sw::Engine::terminate();
}

TEST_F (EngineTester, activeScene_wrong)
{
    sw::Engine::initialize();
    sw::Engine::terminate();
    EXPECT_ANY_THROW(sw::Engine::activeScene<EngineTestScene>());
}

TEST_F (EngineTester, activeScene_no_cast)
{
    sw::Engine::initialize();
    EXPECT_NO_THROW(EXPECT_STREQ(sw::Engine::activeScene().name().c_str(), "TestScene"));
    sw::Engine::terminate();
}

TEST_F (EngineTester, activeScene_no_cast_wrong)
{
    sw::Engine::initialize();
    sw::Engine::terminate();
    EXPECT_ANY_THROW(sw::Engine::activeScene());
}

TEST_F (EngineTester, deleteScene)
{
    sw::Engine::initialize();
    sw::Engine::deleteScene("TestScene");
    sw::Engine::update();
    EXPECT_FALSE(sw::Engine::hasScene("TestScene"));
    sw::Engine::terminate();
}

TEST_F (EngineTester, deleteScene_wrong)
{
    sw::Engine::initialize();
    EXPECT_NO_THROW(sw::Engine::deleteScene("TestScee"));
    EXPECT_TRUE(sw::Engine::hasScene("TestScene"));
    sw::Engine::terminate();
}

TEST_F (EngineTester, has_scene_true)
{
    sw::Engine::initialize();
    EXPECT_NO_THROW(sw::Engine::createScene<EngineTestScene>("EngineTestScene"));
    EXPECT_TRUE(sw::Engine::hasScene("TestScene"));
    EXPECT_TRUE(sw::Engine::hasScene("EngineTestScene"));
    sw::Engine::terminate();
}

TEST_F (EngineTester, has_scene_false)
{
    sw::Engine::initialize();
    EXPECT_NO_THROW(sw::Engine::createScene<EngineTestScene>("EngineTestScene"));
    EXPECT_FALSE(sw::Engine::hasScene("TestScne"));
    EXPECT_FALSE(sw::Engine::hasScene("esxdcfhgbj"));
    sw::Engine::terminate();
}

TEST_F (EngineTester, set_active_scene)
{
    sw::Engine::initialize();
    EXPECT_NO_THROW(sw::Engine::createScene<EngineTestScene>("EngineTestScene"));
    EXPECT_STREQ(sw::Engine::activeScene().name().c_str(), "TestScene");
    EXPECT_NO_THROW(sw::Engine::setActiveScene("EngineTestScene"));
    sw::Engine::update();
    EXPECT_STREQ(sw::Engine::activeScene().name().c_str(), "EngineTestScene");
    sw::Engine::terminate();
}

TEST_F (EngineTester, set_active_wrong_scene)
{
    sw::Engine::initialize();
    EXPECT_STREQ(sw::Engine::activeScene().name().c_str(), "TestScene");
    EXPECT_NO_THROW(sw::Engine::setActiveScene("EngineTestSne"));
    EXPECT_STREQ(sw::Engine::activeScene().name().c_str(), "TestScene");
    sw::Engine::terminate();
}