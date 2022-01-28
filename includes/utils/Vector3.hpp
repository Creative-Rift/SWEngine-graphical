/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Vector3.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_VECTOR3_HPP
#define SWENGINE_OPENGLMODULE_VECTOR3_HPP

namespace sw
{
    template <typename T>
    class Vector3
    {

        public:
            ///////////////////////////////////////////////////////////////////
            ///
            /// Member data.
            //
            T x;
            T y;
            T z;
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// \brief Default constructor.
            ///
            /// Creates a Vector3(0, 0).
            //
            Vector3();
            //
            ///////////////////////////////////////////////////////////////////
            ///
            /// \brief Construct the vector from the given coordinates.
            ///
            /// \param X X coordinate.
            /// \param Y Y coordinate.
            /// \param Z Z coordinate.
            //
            Vector3(T x, T y, T z);
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// \brief Default destructor.
            //
            ~Vector3();
            //
            ///////////////////////////////////////////////////////////////////

    }; // class Vector3

    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector3
    /// \brief Overload of binary operator -
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a vector)
    ///
    /// \return Memberwise subtraction of both vectors
    //
    template <typename T>
    Vector3<T> operator -(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    //
    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector3
    /// \brief Overload of unary operator -
    ///
    /// \param right Vector to negate
    ///
    /// \return Memberwise opposite of the vector
    //
    template <typename T>
    Vector3<T> operator -(const sw::Vector3<T>& right);
    //
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector3
    /// \brief Overload of binary operator +
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a vector)
    ///
    /// \return Memberwise addition of both vectors
    //
    template <typename T>
    Vector3<T> operator +(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    //
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector2
    /// \brief Overload of binary operator *
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a vector)
    ///
    /// \return Memberwise multiplication of both vectors
    //
    template <typename T>
    Vector3<T> operator *(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    //
    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector3
    /// \brief Overload of binary operator *
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a scalar value)
    ///
    /// \return Memberwise multiplication by right
    //
    template <typename T>
    Vector3<T> operator *(const sw::Vector3<T>& left, T right);
    //
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector2
    /// \brief Overload of binary operator /
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a vector)
    ///
    /// \return Memberwise division of both vectors
    //
    template <typename T>
    Vector3<T> operator /(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    //
    ///////////////////////////////////////////////////////////////////////////
    /// \relates Vector2
    /// \brief Overload of binary operator /
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a scalar value)
    ///
    /// \return Memberwise division by right
    //
    template <typename T>
    Vector3<T> operator /(const sw::Vector3<T>& left, T right);
    //
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector2
    /// \brief Overload of binary operator -=
    ///
    /// This operator performs a memberwise subtraction of both vectors,
    /// and assigns the result to left.
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a vector)
    ///
    /// \return Reference to left
    //
    template <typename T>
    Vector3<T>& operator -=(sw::Vector3<T>& left, const sw::Vector3<T>& right);
    //
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \relates Vector2
    /// \brief Overload of binary operator +=
    ///
    /// This operator performs a memberwise addition of both vectors,
    /// and assigns the result to left.
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a vector)
    ///
    /// \return Reference to left
    //
    template <typename T>
    Vector3<T>& operator +=(sw::Vector3<T>& left, const sw::Vector3<T>& right);
    //
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector2
    /// \brief Overload of binary operator *=
    ///
    /// This operator performs a memberwise multiplication of both vectors,
    /// and assigns the result to left.
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a vector)
    ///
    /// \return Reference to left
    //
    template <typename T>
    Vector3<T>& operator *=(sw::Vector3<T>& left, const sw::Vector3<T>& right);
    //
    //////////protected:ight Right operand (a scalar value)
    ///
    /// \return Reference to left
    //
    template <typename T>
    Vector3<T>& operator *=(sw::Vector3<T>& left, T right);
    //
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector2
    /// \brief Overload of binary operator /
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a scalar value)
    ///
    /// \return Memberwise division of both vectors
    //
    template <typename T>
    Vector3<T>& operator /=(sw::Vector3<T>& left, const sw::Vector3<T>& right);
    //
    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector2
    /// \brief Overload of binary operator /
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a scalar value)
    ///
    /// \return Memberwise division by right
    //
    template <typename T>
    Vector3<T>& operator /=(sw::Vector3<T>& left, T right);
    //
    ///////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector2
    /// \brief Overload of binary operator ==
    ///
    /// This operator compares strict equality between two vectors.
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a vector)
    ///
    /// \return True if left is equal to right
    //
    template <typename T>
    bool operator ==(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    //
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    /// \relates Vector2
    /// \brief Overload of binary operator !=
    ///
    /// This operator compares strict difference between two vectors.
    ///
    /// \param left  Left operand (a vector)
    /// \param right Right operand (a vector)
    ///
    /// \return True if left is not equal to right
    //
    template <typename T>
    bool operator !=(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    //
    ///////////////////////////////////////////////////////////////////////////


    /// Define the most common types //////////////////////////////////////////
    //
    typedef Vector3<int>          Vector3i;
    typedef Vector3<unsigned int> Vector3u;
    typedef Vector3<float>        Vector3f;
    //
    ///////////////////////////////////////////////////////////////////////////

#include "Vector3.inl"

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_VECTOR3_HPP
