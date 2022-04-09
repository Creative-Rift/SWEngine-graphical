
#include <gtest/gtest.h>

#include "SW/Errors.hpp"

TEST (Error, getInfo) {
    sw::Error err("This is a message", "This is a code");

    EXPECT_STREQ(err.getMessage().c_str(), "This is a message");
    EXPECT_STREQ(err.getCode().c_str(), "This is a code");

}

TEST (Error, copyError)
{
    sw::Error err("This is a message", "This is a code");
    sw::Error copy(err);

    EXPECT_STREQ(copy.getMessage().c_str(), "This is a message");
    EXPECT_STREQ(copy.getCode().c_str(), "This is a code");
}

TEST (Error, format)
{
    sw::Error err("This is a message", "This is a code");
    std::string str;

    testing::internal::CaptureStdout();
    std::cout << err << std::endl;
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "[This is a code]: This is a message\n");
}

TEST (NotImplemented, getInfo) {
    sw::NotImplemented err("This is a message", "This is a code");

    EXPECT_STREQ(err.getMessage().c_str(), "This is a message");
    EXPECT_STREQ(err.getCode().c_str(), "This is a code");
}

TEST (NotImplemented, what) {
    sw::NotImplemented err("This is a message", "This is a code");

    EXPECT_STREQ(err.what(), "This is a message");
    EXPECT_STREQ(err.getCode().c_str(), "This is a code");
}

TEST (NotImplemented, copyError)
{
    sw::NotImplemented err;

    EXPECT_STREQ(err.getMessage().c_str(), "Function not implemented!");
    EXPECT_STREQ(err.getCode().c_str(), "0");
}

TEST (NotImplemented, format)
{
    sw::NotImplemented err("This is a message", "This is a code");
    std::string str;

    testing::internal::CaptureStdout();
    std::cout << err << std::endl;
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "[This is a code]: This is a message\n");
}