/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** rect.hpp
*/

#ifndef __SHIPWRECK_RECT_HPP__
#define __SHIPWRECK_RECT_HPP__

#include "vector2.hpp"

namespace sw
{

    template <typename T>
    class Rect
    {

        public:
            T left;
            T top;
            T width;
            T height;

        ///////////////////////////////////////////////////////////////////////
        /// Default constructor
        ///
        /// Creates an empty rectangle (it is equivalent to calling
        /// Rect(0, 0, 0, 0)).
        //
        Rect();

        ///////////////////////////////////////////////////////////////////////
        /// Construct the rectangle from its coordinates
        ///
        /// @warning Be careful, the last two parameters are the width
        /// and height, not the right and bottom coordinates!
        ///
        /// @param rectLeft   Left coordinate of the rectangle
        /// @param rectTop    Top coordinate of the rectangle
        /// @param rectWidth  Width of the rectangle
        /// @param rectHeight Height of the rectangle
        //
        Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight);

        ///////////////////////////////////////////////////////////////////////
        /// Construct the rectangle from position and size
        ///
        /// @warning Be careful, the last parameter is the size,
        /// not the bottom-right corner!
        ///
        /// @param position Position of the top-left corner of the rectangle
        /// @param size     Size of the rectangle
        //
        Rect(const sw::Vector2<T>& position, const sw::Vector2<T>& size);

        ////////////////////////////////////////////////////////////
        /// Check if a point is inside the rectangle's area
        ///
        /// @warning This check is non-inclusive. If the point lies on
        /// the edge of the rectangle, this function will return false.
        ///
        /// @param x X coordinate of the point to test
        /// @param y Y coordinate of the point to test
        ///
        /// @return True if the point is inside, false otherwise
        //
        bool contains(T x, T y) const;

        ////////////////////////////////////////////////////////////
        /// Check if a point is inside the rectangle's area
        ///
        /// @warning This check is non-inclusive. If the point lies on the
        /// edge of the rectangle, this function will return false.
        ///
        /// @param point Point to test
        ///
        /// @return True if the point is inside, false otherwise
        //
        bool contains(const sw::Vector2<T>& point) const;

        ////////////////////////////////////////////////////////////
        /// Check the intersection between two rectangles
        ///
        /// @param rectangle Rectangle to test
        ///
        /// @return True if rectangles overlap, false otherwise
        //
        bool intersects(const sw::Rect<T>& rectangle) const;

    }; // class Rect


    template <typename T>
    Rect<T> operator+(const Rect<T>& left, const Rect<T> right);

    template <typename T>
    Rect<T> operator-(const Rect<T>& left, const Rect<T> right);

    template <typename T>
    Rect<T> operator*(const Rect<T>& left, const Rect<T> right);

    template <typename T>
    Rect<T> operator/(const Rect<T>& left, const Rect<T> right);

    template <typename T>
    Rect<T> operator%(const Rect<T>& left, const Rect<T> right);

    template <typename T>
    Rect<T>& operator+=(Rect<T>& left, const Rect<T> right);

    template <typename T>
    Rect<T>& operator-=(Rect<T>& left, const Rect<T> right);

    template <typename T>
    Rect<T>& operator*=(Rect<T>& left, const Rect<T> right);

    template <typename T>
    Rect<T>& operator/=(Rect<T>& left, const Rect<T> right);

    template <typename T>
    Rect<T>& operator%=(Rect<T>& left, const Rect<T> right);

    ////////////////////////////////////////////////////////////
    /// @relates Rect
    ///
    /// Overload of binary operator==
    ///
    /// This operatorcompares strict equality between two rectangles.
    ///
    /// @param left  Left operand (a rectangle)
    /// @param right Right operand (a rectangle)
    ///
    /// @return True if left is equal to right
    //
    template <typename T>
    bool operator==(const Rect<T>& left, const Rect<T>& right);


    ////////////////////////////////////////////////////////////
    /// @relates Rect
    /// Overload of binary operator
    ///
    /// @param left  Left operand (a rectangle)
    /// @param right Right operand (a rectangle)
    ///
    //
    template <typename T>
    bool operator!=(const Rect<T>& left, const Rect<T>& right);
    //
    template <typename T>
    bool operator<(const Rect<T>& left, const Rect<T>& right);
    //
    template <typename T>
    bool operator>(const Rect<T>& left, const Rect<T>& right);
    //
    template <typename T>
    bool operator<=(const Rect<T>& left, const Rect<T>& right);
    //
    template <typename T>
    bool operator>=(const Rect<T>& left, const Rect<T>& right);

    /// Define the most common types //////////////////////////////////////////
    //
    typedef Rect<int>   IntRect;
    typedef Rect<float> FloatRect;
    //
    ///////////////////////////////////////////////////////////////////////////

    #include "rect.inl"

} // namespace sw

#endif // __SHIPWRECK_RECT_HPP__