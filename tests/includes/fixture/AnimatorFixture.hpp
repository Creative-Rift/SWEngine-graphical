/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AnimatorFixture.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_TEST_ANIMATORFIXTURE_HPP
#define SWENGINE_OPENGLMODULE_TEST_ANIMATORFIXTURE_HPP

#include "gtest/gtest.h"

class AnimatorFixture : public ::testing::Test
{
    protected:
        void SetUp() override;
        void TearDown() override;
};

#endif //SWENGINE_OPENGLMODULE_TEST_ANIMATORFIXTURE_HPP
