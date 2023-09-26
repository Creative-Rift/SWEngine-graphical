/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Speech_Tests.cpp
** Description: [CHANGE]
*/

#include <thread>
#include <gtest/gtest.h>

#include "utils/Speech.hpp"

TEST (Speech, error_color)
{
    sw::Speech::colorized = true;
    sw::Speech::displayed = true;
    testing::internal::CaptureStdout();
    sw::Speech::Error("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_NE(str.find("Error: "), std::string::npos);
    EXPECT_NE(str.find("Message"), std::string::npos);
    EXPECT_NE(str.find("Code"), std::string::npos);
    EXPECT_NE(str.find("[91m"), std::string::npos);
}

TEST (Speech, error_no_color)
{
    sw::Speech::displayed = true;
    sw::Speech::colorized = false;
    testing::internal::CaptureStdout();
    sw::Speech::Error("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_NE(str.find("Error: "), std::string::npos);
    EXPECT_NE(str.find("Message"), std::string::npos);
    EXPECT_NE(str.find("Code"), std::string::npos);
    EXPECT_EQ(str.find("[91m"), std::string::npos);
}

TEST (Speech, error_no_display)
{
    sw::Speech::dispError = false;
    testing::internal::CaptureStdout();
    sw::Speech::Error("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_EQ(str.find("Error: "), std::string::npos);
    EXPECT_EQ(str.find("Message"), std::string::npos);
    EXPECT_EQ(str.find("Code"), std::string::npos);
    EXPECT_EQ(str.find("[91m"), std::string::npos);
}

TEST (Speech, warning_color)
{
    sw::Speech::displayed = true;
    sw::Speech::colorized = true;
    testing::internal::CaptureStdout();
    sw::Speech::Warning("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_NE(str.find("Warning: "), std::string::npos);
    EXPECT_NE(str.find("Message"), std::string::npos);
    EXPECT_NE(str.find("Code"), std::string::npos);
    EXPECT_NE(str.find("[93m"), std::string::npos);
}

TEST (Speech, warning_no_color)
{
    sw::Speech::displayed = true;
    sw::Speech::colorized = false;
    testing::internal::CaptureStdout();
    sw::Speech::Warning("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_NE(str.find("Warning: "), std::string::npos);
    EXPECT_NE(str.find("Message"), std::string::npos);
    EXPECT_NE(str.find("Code"), std::string::npos);
    EXPECT_EQ(str.find("[93m"), std::string::npos);
}

TEST (Speech, warning_no_display)
{
    sw::Speech::dispWarning = false;
    testing::internal::CaptureStdout();
    sw::Speech::Warning("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_EQ(str.find("Warning: "), std::string::npos);
    EXPECT_EQ(str.find("Message"), std::string::npos);
    EXPECT_EQ(str.find("Code"), std::string::npos);
    EXPECT_EQ(str.find("[93m"), std::string::npos);
}

TEST (Speech, debug_color)
{
    sw::Speech::displayed = true;
    sw::Speech::colorized = true;
    testing::internal::CaptureStdout();
    sw::Speech::Debug("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_NE(str.find("Debug: "), std::string::npos);
    EXPECT_NE(str.find("Message"), std::string::npos);
    EXPECT_NE(str.find("Code"), std::string::npos);
    EXPECT_NE(str.find("[36m"), std::string::npos);
}

TEST (Speech, debug_no_color)
{
    sw::Speech::displayed = true;
    sw::Speech::colorized = false;
    testing::internal::CaptureStdout();
    sw::Speech::Debug("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_NE(str.find("Debug: "), std::string::npos);
    EXPECT_NE(str.find("Message"), std::string::npos);
    EXPECT_NE(str.find("Code"), std::string::npos);
    EXPECT_EQ(str.find("[36m"), std::string::npos);
}

TEST (Speech, debug_no_display)
{
    sw::Speech::dispDebug = false;
    testing::internal::CaptureStdout();
    sw::Speech::Debug("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_EQ(str.find("Debug: "), std::string::npos);
    EXPECT_EQ(str.find("Message"), std::string::npos);
    EXPECT_EQ(str.find("Code"), std::string::npos);
    EXPECT_EQ(str.find("[36m"), std::string::npos);
}

TEST (Speech, info_color)
{
    sw::Speech::displayed = true;
    sw::Speech::colorized = true;
    testing::internal::CaptureStdout();
    sw::Speech::Info("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_NE(str.find("Info: "), std::string::npos);
    EXPECT_NE(str.find("Message"), std::string::npos);
    EXPECT_NE(str.find("Code"), std::string::npos);
    EXPECT_NE(str.find("[32m"), std::string::npos);
}

TEST (Speech, info_no_color)
{
    sw::Speech::displayed = true;
    sw::Speech::colorized = false;
    testing::internal::CaptureStdout();
    sw::Speech::Info("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_NE(str.find("Info: "), std::string::npos);
    EXPECT_NE(str.find("Message"), std::string::npos);
    EXPECT_NE(str.find("Code"), std::string::npos);
    EXPECT_EQ(str.find("[32m"), std::string::npos);
}

TEST (Speech, info_no_display)
{
    sw::Speech::displayed = true;
    sw::Speech::dispInfo = false;
    testing::internal::CaptureStdout();
    sw::Speech::Info("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_EQ(str.find("Info: "), std::string::npos);
    EXPECT_EQ(str.find("Message"), std::string::npos);
    EXPECT_EQ(str.find("Code"), std::string::npos);
    EXPECT_EQ(str.find("[32m"), std::string::npos);
}

TEST (Speech, no_display)
{
    sw::Speech::displayed = false;
    testing::internal::CaptureStdout();
    sw::Speech::Info("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_EQ(str.find("Info: "), std::string::npos);
    EXPECT_EQ(str.find("Message"), std::string::npos);
    EXPECT_EQ(str.find("Code"), std::string::npos);
    EXPECT_EQ(str.find("[32m"), std::string::npos);
}

TEST (Speech, is_same)
{
    sw::Speech::colorized = true;
    sw::Speech::displayed = true;
    sw::Speech::dispError = true;
    testing::internal::CaptureStdout();
    sw::Speech::Error("Message", "Code");
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    sw::Speech::Error("Message", "Code");
    sw::Speech::flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    sw::Speech::Error("Message", "Code");
    sw::Speech::flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    sw::Speech::Error("Message", "Code");
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();

    EXPECT_NE(str.find("Error: "), std::string::npos);
    EXPECT_NE(str.find("Message"), std::string::npos);
    EXPECT_NE(str.find("Code"), std::string::npos);
    EXPECT_NE(str.find("[91m"), std::string::npos);
}