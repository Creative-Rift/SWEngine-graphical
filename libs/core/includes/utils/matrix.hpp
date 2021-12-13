/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** matrix.hpp
*/

#ifndef __SHIPWRECK_MATRIX_HPP__
#define __SHIPWRECK_MATRIX_HPP__

#include <vector>

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
            ///////////////////////////////////////////////////////////////////
            ///
            /// Initialize a size order square matrix.
            ///
            /// @param size The number of line and column.
            //
            Matrix(unsigned size);
            //
            ///////////////////////////////////////////////////////////////////
            ///
            /// Initialize a matrix with the given column and line.
            ///
            /// @param col The number of column.
            /// @param line The number of line.
            //
            Matrix(unsigned col, unsigned line);
            //
            ///////////////////////////////////////////////////////////////////
            ///
            /// Initialize a matrix based on the given copy.
            ///
            /// @param copy The matrix use to create the new one.
            //
            Matrix(const Matrix<T>& copy);
            //
            ///////////////////////////////////////////////////////////////////
            ///
            /// Initialize a matrix based on the given two dimensional array.
            ///
            /// @param array The array used to create the new matrix.
            //
            Matrix(const std::vector< std::vector<T> > array);
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Destroy a Matrix.
            //
            ~Matrix() = default;
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Return a two dimensional array corresponding to the matrix.
            //
            const std::vector< std::vector<T> >& getMatrix() const;
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Overwrite the actual matrix to leave a identity matrix.
            ///
            /// @warning Does not work if the number of columns is not equal
            /// to the number of lines
            //
            void setIdentity();
            //
            ///////////////////////////////////////////////////////////////////

            unsigned col() const;
            unsigned line() const;

            ///////////////////////////////////////////////////////////////////
            //
            Matrix<T>& operator=(const Matrix<T>&);
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////////////
            ///
            /// \relates Matrix
            /// \brief Overload of binary operator *=
            ///
            /// This operator performs a memberwise multiplication by right,
            /// and assigns the result to left.
            ///
            /// \param left  Left operand (a matrix)
            /// \param right Right operand (a scalar value)
            ///
            /// \return Reference to left
            //
            Matrix<T>& operator*=(const T& right);
            //
            ///////////////////////////////////////////////////////////////////////////
            ///
            /// \relates Matrix
            /// \brief Overload of binary operator *
            ///
            /// \param left  Left operand (a matrix)
            /// \param right Right operand (a scalar value)
            ///
            /// \return Memberwise multiplication by right
            //
            Matrix<T> operator*(const T& right);
        //
        ///////////////////////////////////////////////////////////////////////////
    };

    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Matrix
    /// \brief Overload of binary operator *
    ///
    /// \param left  Left operand (a matrix)
    /// \param right Right operand (a matrix)
    ///
    /// \return Memberwise multiplication of both matrix
    //
    template <typename T>
    Matrix<T> operator*(const Matrix<T>& left, const Matrix<T>& right);
    //


    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Matrix
    /// \brief Overload of binary operator *=
    ///
    /// This operator performs a memberwise multiplication of both matrix,
    /// and assigns the result to left.
    ///
    /// \param left  Left operand (a matrix)
    /// \param right Right operand (a matrix)
    ///
    /// \return Reference to left
    //
    template <typename T>
    Matrix<T> operator*=(Matrix<T>& left, const Matrix<T>& right);

    // Define the most common types
    typedef Matrix<int>          Matrixi;
    typedef Matrix<unsigned int> Matrixu;
    typedef Matrix<float>        Matrixf;

    #include "matrix.inl"

} // namespace sw

#endif // __SHIPWRECK_MATRIX_HPP__