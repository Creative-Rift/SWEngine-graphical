/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Engine_tests.cpp
** Description: [CHANGE]
*/

#include "Engine_tests.hpp"
#include "OpenGLModule.hpp"
#include "utils/Speech.hpp"

TEST_F (EngineTester, init_normal_end)
{
    ASSERT_NO_THROW(sw::OpenGLModule::load());
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
}

/*
TEST_F (EngineTester, init_throw)
{
    EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()).m_initThrow = true);
    ASSERT_ANY_THROW(sw::OpenGLModule::load());
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
    EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()).m_initThrow = false);
}
*/

TEST_F (EngineTester, clear_on_play)
{
    sw::Speech::clearOnPlay = true;
    EXPECT_NO_THROW(sw::OpenGLModule::load());
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
}

TEST_F (EngineTester, init_alreadyLoaded_end)
{
    testing::internal::CaptureStdout();
    sw::Speech::displayed = true;

    sw::OpenGLModule::load();
    sw::Speech::clearConsole();
    ASSERT_NO_THROW(sw::OpenGLModule::load());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("OpenGLModule is already load"), std::string::npos);
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
}

TEST_F (EngineTester, update_once)
{
    testing::internal::CaptureStdout();
    sw::Speech::displayed = true;

    ASSERT_NO_THROW(sw::OpenGLModule::load());
    sw::Speech::clearConsole();
    EXPECT_NO_THROW(sw::OpenGLModule::update());
    sw::Speech::flush();
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
    EXPECT_NE(testing::internal::GetCapturedStdout().find("OpenGLModule was successfully updated !"), std::string::npos);
}

TEST_F (EngineTester, update_throw)
{
    sw::Speech::displayed = true;
    ASSERT_NO_THROW(sw::OpenGLModule::load()); // TODO fix the test
    //EXPECT_NO_THROW(sw::OpenGLModule::update()).m_updateThrow = true);
    //EXPECT_NO_THROW(sw::OpenGLModule::update());
    //EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()).m_updateThrow = false);
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
}

/*
TEST_F (EngineTester, update_noLoaded)
{
    sw::Speech::displayed = true;

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(sw::OpenGLModule::update());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("OpenGLModule can not be update because it was not loaded !"), std::string::npos);
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
}
*/

TEST_F (EngineTester, unload)
{
    testing::internal::CaptureStdout();
    sw::Speech::displayed = true;

    ASSERT_NO_THROW(sw::OpenGLModule::load());
    sw::Speech::clearConsole();
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("OpenGLModule was successfully terminated !"), std::string::npos);
}

TEST_F (EngineTester, end_throw)
{// TODO fix the test
    //EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()).m_endThrow = true);
    ASSERT_NO_THROW(sw::OpenGLModule::load());
    EXPECT_ANY_THROW(sw::OpenGLModule::unload());
    //EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()).m_endThrow = false);
}

TEST_F (EngineTester, getModule)
{// TODO fix the test
    //EXPECT_NO_THROW(sw::OpenGLModule::getModule<EngineTestModule>());
}

/*
TEST_F (EngineTester, get_wrong_module)
{
    EXPECT_ANY_THROW(sw::OpenGLModule::getModule<EngineTestModule>());
}
*/

TEST_F (EngineTester, getModule_2)
{// TODO fix the test
    //ASSERT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()));
    //EngineTestModule module = dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule());
}

TEST_F (EngineTester, getModule_bis)
{// TODO fix the test
    //EXPECT_NO_THROW(sw::OpenGLModule::getModule());
}

TEST_F (EngineTester, getActive_no_active)
{// TODO fix the test
    sw::OpenGLModule::load();
    sw::OpenGLModule::unload();
    //EXPECT_ANY_THROW(sw::OpenGLModule::getModule());
}

TEST_F (EngineTester, getModule_template)
{// TODO fix the test
    //EXPECT_NO_THROW(sw::OpenGLModule::getModule<EngineTestModule>());
}

TEST_F (EngineTester, getActive_no_active_template)
{// TODO fix the test
    sw::OpenGLModule::load();
    sw::OpenGLModule::unload();
    //EXPECT_ANY_THROW(sw::OpenGLModule::getModule<EngineTestModule>());
}

/*
TEST_F (EngineTester, remove_module)
{
    sw::OpenGLModule::load();
    EXPECT_TRUE(sw::OpenGLModule::hasModule());
    EXPECT_NO_THROW(sw::OpenGLModule::deleteModule());
    sw::OpenGLModule::update();
    EXPECT_FALSE(sw::OpenGLModule::hasModule());
    sw::OpenGLModule::unload();
}
*/

TEST_F (EngineTester, createScene)
{
    sw::OpenGLModule::sceneManager().createScene("EngineTestsScene");

    EXPECT_NO_THROW(EXPECT_STREQ(sw::OpenGLModule::sceneManager().getScene("EngineTestsScene")->name.c_str(), "EngineTestsScene"));
}

TEST_F (EngineTester, get_wrong_scene)
{
    EXPECT_ANY_THROW(sw::OpenGLModule::sceneManager().getScene("scene"));
}

// TODO Recheck all tests for scene

TEST_F (EngineTester, get_scene_cast)
{
    sw::OpenGLModule::load(); // TODO check if the test is usefully
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().getScene("TestScene"));
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, get_wrong_scene_cast)
{
    sw::OpenGLModule::load();// TODO check if the test is usefully
    EXPECT_ANY_THROW(sw::OpenGLModule::sceneManager().getScene("TestsScene"));
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, getActiveScene)
{
    sw::OpenGLModule::load();
    EXPECT_NO_THROW(EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "TestScene"));
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, activeScene_wrong)
{
    sw::OpenGLModule::load();
    sw::OpenGLModule::unload();
    EXPECT_ANY_THROW(sw::OpenGLModule::sceneManager().getActiveScene());
}

TEST_F (EngineTester, activeScene_no_cast)
{
    sw::OpenGLModule::load();
    EXPECT_NO_THROW(EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "TestScene"));
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, activeScene_no_cast_wrong)
{
    sw::OpenGLModule::load();
    sw::OpenGLModule::unload();
    EXPECT_ANY_THROW(sw::OpenGLModule::sceneManager().getActiveScene());
}

TEST_F (EngineTester, deleteScene)
{
    sw::OpenGLModule::load(); // TODO Check feature
    //sw::OpenGLModule::sceneManager().deleteScene("TestScene");
    sw::OpenGLModule::update();
    //EXPECT_FALSE(sw::OpenGLModule::shasScene("TestScene"));
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, deleteScene_wrong)
{
    sw::OpenGLModule::load();
    //EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().deleteScene("TestScee"));
    //EXPECT_TRUE(sw::OpenGLModule::hasScene("TestScene"));
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, has_scene_true)
{
    sw::OpenGLModule::load();
    //EXPECT_NO_THROW(sw::OpenGLModule::createScene<EngineTestScene>("EngineTestScene"));
    //EXPECT_TRUE(sw::OpenGLModule::hasScene("TestScene"));
    //EXPECT_TRUE(sw::OpenGLModule::hasScene("EngineTestScene"));
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, has_scene_false)
{
    sw::OpenGLModule::load();
    //EXPECT_NO_THROW(sw::OpenGLModule::createScene<EngineTestScene>("EngineTestScene"));
    //EXPECT_FALSE(sw::OpenGLModule::hasScene("TestScne"));
    //EXPECT_FALSE(sw::OpenGLModule::hasScene("esxdcfhgbj"));
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, set_active_scene)
{
    sw::OpenGLModule::load();
    //EXPECT_NO_THROW(sw::OpenGLModule::createScene<EngineTestScene>("EngineTestScene"));
    EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "TestScene");
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().loadScene("EngineTestScene"));
    sw::OpenGLModule::update();
    EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "EngineTestScene");
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, set_active_wrong_scene)
{
    sw::OpenGLModule::load();
    EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "TestScene");
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().loadScene("EngineTestSne"));
    EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "TestScene");
    sw::OpenGLModule::unload();
}