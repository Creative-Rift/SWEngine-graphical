/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * rect.hpp
 *
 * Description:
 * Rect class
 * The Rect class allow you to create Rectangle with the type and the size you want.
 * You also need to give a position to it.
 * You can check if a point is in a Rect or if two Rect collide.
 */

#ifndef __SHIPWRECK_CORE_RECT_HPP__
#define __SHIPWRECK_CORE_RECT_HPP__

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

        /*////////////////////////////////////////////////////////////////*/
        /// @brief Default @c Constructor of a @b Rect.
        ///
        /// Creates an empty @b Rect (it is equivalent to calling
        /// Rect(0, 0, 0, 0)).
        //
        Rect();
        ///

        /*////////////////////////////////////////////////////////////////*/
        /// @brief Construct the @b Rect from its coordinates.
        ///
        /// @warning Be careful, the last two parameters are the width
        /// and height, not the right and bottom coordinates !
        ///
        /// @param rectLeft   Left coordinate of the @b Rect.
        /// @param rectTop    Top coordinate of the @b Rect.
        /// @param rectWidth  Width of the @b Rect.
        /// @param rectHeight Height of the @b Rect.
        //
        Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight);
        ///

        /*////////////////////////////////////////////////////////////////*/
        /// @brief Construct the @b Rect from position and size
        ///
        /// @warning Be careful, the last parameter is the size,
        /// not the bottom-right corner !
        ///
        /// @param position Position of the top-left corner of the @b Rect
        /// @param size     Size of the @b Rect
        //
        Rect(const sw::Vector2<T>& position, const sw::Vector2<T>& size);
        ///

        /*////////////////////////////////////////////////////////////////*/
        /// @brief Check if a point is inside the @b Rect's area.
        ///
        /// @warning This check is non-inclusive. If the point lies on
        /// the edge of the @b Rect, this function will return false.
        ///
        /// @param x X coordinate of the point to test.
        /// @param y Y coordinate of the point to test.
        ///
        /// @return True if the point is inside, false otherwise.
        //
        bool contains(T x, T y) const;
        ///

        /*////////////////////////////////////////////////////////////////*/
        /// @brief Check if a point is inside the @b Rect's area.
        ///
        /// @warning This check is non-inclusive. If the point lies on the
        /// edge of the @b Rect, this function will return false.
        ///
        /// @param point Point to test.
        ///
        /// @return True if the point is inside, false otherwise.
        //
        bool contains(const sw::Vector2<T>& point) const;
        ///

        /*////////////////////////////////////////////////////////////////*/
        /// @brief Check the intersection between two @b Rects.
        ///
        /// @param rectangle @b Rect to test.
        ///
        /// @return True if the @b Rects overlap, false otherwise.
        //
        bool intersects(const sw::Rect<T>& rectangle) const;
        ///

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

    /*////////////////////////////////////////////////////////////////*/
    /// @brief Overload of binary operator==
    ///
    /// This operator compares strict equality between two rectangles.
    ///
    /// @param left  Left operand (a rectangle)
    /// @param right Right operand (a rectangle)
    ///
    /// @return True if left is equal to right
    //
    template <typename T>
    bool operator==(const Rect<T>& left, const Rect<T>& right);


    /*////////////////////////////////////////////////////////////////*/
    /// @brief Overload of binary operator
    ///
    /// @param left  Left operand (a rectangle)
    /// @param right Right operand (a rectangle)
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

    /// Define the most common types
    typedef Rect<int>   IntRect;
    typedef Rect<float> FloatRect;

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Rect<T>& rect);

    #include "rect.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_RECT_HPP__