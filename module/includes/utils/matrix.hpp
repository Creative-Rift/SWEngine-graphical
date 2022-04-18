/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * matrix.hpp
 *
 * Description:
 * Matrix class
 * The Matrix class allow you to create Matrix with the type and the size
 * you want.
 */

#ifndef __SHIPWRECK_CORE_MATRIX_HPP__
#define __SHIPWRECK_CORE_MATRIX_HPP__

#include <vector>
#include <ostream>

namespace sw
{

    template <typename T>
    class Matrix
    {
        private:
            unsigned m_col;
            unsigned m_line;
            std::vector< std::vector<T> > m_matrix;

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Create a size order square @b Matrix.
            ///
            /// @param size The number of line and column.
            //
            Matrix(unsigned size);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Create a @b Matrix with the given number of column and line.
            ///
            /// @param col The number of column.
            /// @param line The number of line.
            //
            Matrix(unsigned col, unsigned line);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Create a @b Matrix based on the given copy.
            ///
            /// @param copy The @b Matrix use to create the new one.
            //
            Matrix(const Matrix<T>& copy);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Create a @b Matrix based on the given two dimensional array.
            ///
            /// @param array The array used to create the new @b Matrix.
            //
            Matrix(const std::vector< std::vector<T> > array);
            //

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of a Matrix.
            //
            ~Matrix() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a two dimensional array corresponding to the @b Matrix.
            //
            const std::vector< std::vector<T> >& getMatrix() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Overwrite the actual @b Matrix to leave an identity @b Matrix.
            ///
            /// @warning Does not work if the number of columns is not equal
            /// to the number of lines.
            //
            void setIdentity();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the columns number of the @b Matrix.
            ///
            /// @return The columns number.
            //
            unsigned col() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the lines number of the @b Matrix.
            ///
            /// @return The lines number.
            //
            unsigned line() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Overload of operator =
            //
            Matrix<T>& operator=(const Matrix<T>&);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Overload of binary operator *=
            ///
            /// This operator performs a memberwise multiplication by right,
            /// and assigns the result to left.
            ///
            /// @param left  Left operand (a @b Matrix)
            /// @param right Right operand (a scalar value)
            ///
            /// @return Reference to left
            //
            Matrix<T>& operator*=(const T& right);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Overload of binary operator *
            ///
            /// @param left  Left operand (a @b Matrix)
            /// @param right Right operand (a scalar value)
            ///
            /// @return Memberwise multiplication by right
            //
            Matrix<T> operator*(const T& right);
            ///

    }; // class Matrix

    /*////////////////////////////////////////////////////////////////////////*/
    /// @brief Overload of binary operator *
    ///
    /// @param left  Left operand (a @b Matrix)
    /// @param right Right operand (a @b Matrix)
    ///
    /// @return Memberwise multiplication of both @b Matrix
    //
    template <typename T>
    Matrix<T> operator*(const Matrix<T>& left, const Matrix<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    /// @brief Overload of binary operator *=
    ///
    /// This operator performs a memberwise multiplication of both @b Matrix,
    /// and assigns the result to left.
    ///
    /// @param left  Left operand (a @b Matrix)
    /// @param right Right operand (a @b Matrix)
    ///
    /// @return Reference to left.
    //
    template <typename T>
    Matrix<T> operator*=(Matrix<T>& left, const Matrix<T>& right);
    ///

    // Define the most common types
    typedef Matrix<int>          Matrixi;
    typedef Matrix<unsigned int> Matrixu;
    typedef Matrix<float>        Matrixf;

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);

    #include "matrix.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_MATRIX_HPP__