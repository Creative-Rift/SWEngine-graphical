/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SpriteFixture.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_TEST_SPRITEFIXTURE_HPP
#define SWENGINE_OPENGLMODULE_TEST_SPRITEFIXTURE_HPP

#include "gtest/gtest.h"

class SpriteFixture : public ::testing::Test
{
    protected:
        void SetUp() override;
        void TearDown() override;
};

#endif //SWENGINE_OPENGLMODULE_TEST_SPRITEFIXTURE_HPP
