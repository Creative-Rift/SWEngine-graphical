/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Metrix_Tests.cpp
** Description: [CHANGE]
*/

#include <gtest/gtest.h>

#include "utils/matrix.hpp"

TEST (Matrix, constructor_default)
{
    sw::Matrixi matrix(2);

    EXPECT_EQ(matrix.getMatrix()[0][0], 0);
    EXPECT_EQ(matrix.getMatrix()[0][1], 0);
    EXPECT_EQ(matrix.getMatrix()[1][0], 0);
    EXPECT_EQ(matrix.getMatrix()[1][1], 0);
}

TEST (Matrix, constructor_value)
{
    sw::Matrixi matrix(2, 1);

    EXPECT_EQ(matrix.getMatrix()[0][0], 0);
    EXPECT_EQ(matrix.getMatrix()[0][1], 0);
}

TEST (Matrix, constructor_copy)
{
    sw::Matrixi matrix(2);
    sw::Matrixi copy(matrix);

    EXPECT_EQ(copy.getMatrix()[0][0], 0);
    EXPECT_EQ(copy.getMatrix()[0][1], 0);
    EXPECT_EQ(copy.getMatrix()[1][0], 0);
    EXPECT_EQ(copy.getMatrix()[1][1], 0);
}

TEST (Matrix, constructor_copy_vector)
{
    sw::Matrixi matrix(2);
    sw::Matrixi copy(matrix.getMatrix());

    EXPECT_EQ(copy.getMatrix()[0][0], 0);
    EXPECT_EQ(copy.getMatrix()[0][1], 0);
    EXPECT_EQ(copy.getMatrix()[1][0], 0);
    EXPECT_EQ(copy.getMatrix()[1][1], 0);
}

TEST (Matrix, copy)
{
    sw::Matrixi matrix(2);
    sw::Matrixi copy(2);

    EXPECT_EQ(matrix.getMatrix()[0][0], 0);
    EXPECT_EQ(matrix.getMatrix()[0][1], 0);
    EXPECT_EQ(matrix.getMatrix()[1][0], 0);
    EXPECT_EQ(matrix.getMatrix()[1][1], 0);
    matrix.setIdentity();
    copy = matrix;

    EXPECT_EQ(copy.getMatrix()[0][0], 1);
    EXPECT_EQ(copy.getMatrix()[0][1], 0);
    EXPECT_EQ(copy.getMatrix()[1][0], 0);
    EXPECT_EQ(copy.getMatrix()[1][1], 1);
}

TEST (Matrix, col_line)
{
    sw::Matrixi matrix(2, 3);

    EXPECT_EQ(matrix.col(), 2);
    EXPECT_EQ(matrix.line(), 3);
}

TEST (Matrix, identity)
{
    sw::Matrixi matrix(2, 2);
    std::vector<std::vector<int>> vResult = {{1, 0}, {0, 1}};

    matrix.setIdentity();
    for (int i = 0; i < matrix.line(); i++)
        for (int j = 0; j < matrix.col(); j++)
            EXPECT_EQ(matrix.getMatrix()[i][j], vResult[i][j]);
}

TEST (Matrix, wrong_identity)
{
    sw::Matrixi matrix(2, 3);
    std::vector<std::vector<int>> vResult = {{0, 0}, {0, 0}, {0, 0}};

    matrix.setIdentity();
    for (int i = 0; i < matrix.line(); i++)
        for (int j = 0; j < matrix.col(); j++)
            EXPECT_EQ(matrix.getMatrix()[i][j], vResult[i][j]);
}

TEST (Matrix, wrong_multiplication)
{
    std::vector<std::vector<int>> vector{{1, 2}};
    std::vector<std::vector<int>> vector2{{4, 3}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> matrix2(vector2);
    sw::Matrix<int> result(2);

    result = matrix * matrix2;
    EXPECT_EQ(result.getMatrix()[0][0], 1);
    EXPECT_EQ(result.getMatrix()[0][1], 2);
}

TEST (Matrix, wrong_multiplication_bis)
{
    std::vector<std::vector<int>> vector{{1, 2}};
    std::vector<std::vector<int>> vector2{{4, 3}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> matrix2(vector2);

    matrix *= matrix2;
    EXPECT_EQ(matrix.getMatrix()[0][0], 1);
    EXPECT_EQ(matrix.getMatrix()[0][1], 2);
}

TEST (Matrix, multiplication_2)
{
    std::vector<std::vector<int>> vector{{1, 2}, {3, 4}};
    std::vector<std::vector<int>> vector2{{4, 3}, {2, 1}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> matrix2(vector2);
    sw::Matrix<int> result(2);

    result = matrix * matrix2;
    EXPECT_EQ(result.getMatrix()[0][0], 8);
    EXPECT_EQ(result.getMatrix()[1][0], 20);
    EXPECT_EQ(result.getMatrix()[0][1], 5);
    EXPECT_EQ(result.getMatrix()[1][1], 13);
}

TEST (Matrix, multiplication_3)
{
    std::vector<std::vector<int>> vector{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> vector2{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> matrix2(vector2);
    sw::Matrix<int> result(3);

    result = matrix * matrix2;
    EXPECT_EQ(result.getMatrix()[0][0], 30);
    EXPECT_EQ(result.getMatrix()[0][1], 24);
    EXPECT_EQ(result.getMatrix()[0][2], 18);
    EXPECT_EQ(result.getMatrix()[1][0], 84);
    EXPECT_EQ(result.getMatrix()[1][1], 69);
    EXPECT_EQ(result.getMatrix()[1][2], 54);
    EXPECT_EQ(result.getMatrix()[2][0], 138);
    EXPECT_EQ(result.getMatrix()[2][1], 114);
    EXPECT_EQ(result.getMatrix()[2][2], 90);
}

TEST (Matrix, multiplication_4)
{
    std::vector<std::vector<int>> vector{{1, 2, 3, 4},
                                         {5, 6, 7, 8},
                                         {9, 10, 11, 12},
                                         {13, 14, 15, 16}};
    std::vector<std::vector<int>> vector2{{16, 15, 14, 13},
                                          {12, 11, 10, 9},
                                          {8, 7, 6, 5},
                                          {4, 3, 2, 1}};
    std::vector<std::vector<int>> vResult{{80, 70, 60, 50},
                                          {240, 214, 188, 162},
                                          {400, 358, 316, 274},
                                          {560, 502, 444, 386}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> matrix2(vector2);
    sw::Matrix<int> result(vector2);

    result = matrix * matrix2;
    for (int i = 0; i < result.line(); i++)
        for (int j = 0; j < result.col(); j++)
            EXPECT_EQ(result.getMatrix()[i][j], vResult[i][j]);
}

TEST (Matrix, multiplication_5)
{
    std::vector<std::vector<int>> vector{{1, 2, 3, 4, 5},
                                         {6, 7, 8, 9, 10},
                                         {11, 12, 13, 14, 15},
                                         {16, 17, 18, 19, 20},
                                         {21, 22, 23, 24, 25}};
    std::vector<std::vector<int>> vector2{{25, 24, 23, 22, 21},
                                          {20, 19, 18, 17, 16},
                                          {15, 14, 13, 12, 11},
                                          {10, 9, 8, 7, 6},
                                          {5, 4, 3, 2, 1}};
    std::vector<std::vector<int>> vResult{{175, 160, 145, 130, 115},
                                          {550, 510, 470, 430, 390},
                                          {925, 860, 795, 730, 665},
                                          {1300, 1210, 1120, 1030, 940},
                                          {1675, 1560, 1445, 1330, 1215}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> matrix2(vector2);
    sw::Matrix<int> result(5);

    result = matrix * matrix2;
    for (int i = 0; i < result.line(); i++)
        for (int j = 0; j < result.col(); j++)
            EXPECT_EQ(result.getMatrix()[i][j], vResult[i][j]);
}

TEST (Matrix, equal_multiplication_2)
{
    std::vector<std::vector<int>> vector{{1, 2}, {3, 4}};
    std::vector<std::vector<int>> vector2{{4, 3}, {2, 1}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> matrix2(vector2);

    matrix *= matrix2;
    EXPECT_EQ(matrix.getMatrix()[0][0], 8);
    EXPECT_EQ(matrix.getMatrix()[1][0], 20);
    EXPECT_EQ(matrix.getMatrix()[0][1], 5);
    EXPECT_EQ(matrix.getMatrix()[1][1], 13);
}

TEST (Matrix, equal_multiplication_3)
{
    std::vector<std::vector<int>> vector{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> vector2{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> matrix2(vector2);

    matrix *= matrix2;
    EXPECT_EQ(matrix.getMatrix()[0][0], 30);
    EXPECT_EQ(matrix.getMatrix()[0][1], 24);
    EXPECT_EQ(matrix.getMatrix()[0][2], 18);
    EXPECT_EQ(matrix.getMatrix()[1][0], 84);
    EXPECT_EQ(matrix.getMatrix()[1][1], 69);
    EXPECT_EQ(matrix.getMatrix()[1][2], 54);
    EXPECT_EQ(matrix.getMatrix()[2][0], 138);
    EXPECT_EQ(matrix.getMatrix()[2][1], 114);
    EXPECT_EQ(matrix.getMatrix()[2][2], 90);
}

TEST (Matrix, equal_multiplication_4)
{
    std::vector<std::vector<int>> vector{{1, 2, 3, 4},
                                         {5, 6, 7, 8},
                                         {9, 10, 11, 12},
                                         {13, 14, 15, 16}};
    std::vector<std::vector<int>> vector2{{16, 15, 14, 13},
                                          {12, 11, 10, 9},
                                          {8, 7, 6, 5},
                                          {4, 3, 2, 1}};
    std::vector<std::vector<int>> vResult{{80, 70, 60, 50},
                                          {240, 214, 188, 162},
                                          {400, 358, 316, 274},
                                          {560, 502, 444, 386}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> matrix2(vector2);

    matrix *= matrix2;
    for (int i = 0; i < matrix.line(); i++)
        for (int j = 0; j < matrix.col(); j++)
            EXPECT_EQ(matrix.getMatrix()[i][j], vResult[i][j]);
}

TEST (Matrix, equal_multiplication_5)
{
    std::vector<std::vector<int>> vector{{1, 2, 3, 4, 5},
                                         {6, 7, 8, 9, 10},
                                         {11, 12, 13, 14, 15},
                                         {16, 17, 18, 19, 20},
                                         {21, 22, 23, 24, 25}};
    std::vector<std::vector<int>> vector2{{25, 24, 23, 22, 21},
                                          {20, 19, 18, 17, 16},
                                          {15, 14, 13, 12, 11},
                                          {10, 9, 8, 7, 6},
                                          {5, 4, 3, 2, 1}};
    std::vector<std::vector<int>> vResult{{175, 160, 145, 130, 115},
                                          {550, 510, 470, 430, 390},
                                          {925, 860, 795, 730, 665},
                                          {1300, 1210, 1120, 1030, 940},
                                          {1675, 1560, 1445, 1330, 1215}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> matrix2(vector2);

    matrix *= matrix2;
    for (int i = 0; i < matrix.line(); i++)
        for (int j = 0; j < matrix.col(); j++)
            EXPECT_EQ(matrix.getMatrix()[i][j], vResult[i][j]);
}

TEST (Matrix, multiplication_value)
{
    std::vector<std::vector<int>> vector{{1, 2}, {3, 4}};
    sw::Matrix<int> matrix(vector);
    sw::Matrix<int> result(2);

    result = matrix * 2;
    EXPECT_EQ(result.getMatrix()[0][0], 2);
    EXPECT_EQ(result.getMatrix()[0][1], 4);
    EXPECT_EQ(result.getMatrix()[1][0], 6);
    EXPECT_EQ(result.getMatrix()[1][1], 8);
}

TEST (Matrix, equal_multiplication_value)
{
    std::vector<std::vector<int>> vector{{1, 2}, {3, 4}};
    sw::Matrix<int> matrix(vector);

    matrix *= 2;
    EXPECT_EQ(matrix.getMatrix()[0][0], 2);
    EXPECT_EQ(matrix.getMatrix()[0][1], 4);
    EXPECT_EQ(matrix.getMatrix()[1][0], 6);
    EXPECT_EQ(matrix.getMatrix()[1][1], 8);
}