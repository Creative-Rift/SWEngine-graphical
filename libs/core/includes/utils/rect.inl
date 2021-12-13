/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** rect.inl
*/

#include "rect.hpp"
#include "vector2.hpp"

template <typename T>
inline sw::Rect<T>::Rect() :
left(0),
top(0),
width(0),
height(0)
{}

template <typename T>
inline sw::Rect<T>::Rect(T setLeft, T setTop, T setWidth, T setHeight) :
left(setLeft),
top(setTop),
width(setWidth),
height(setHeight)
{}

template <typename T>
inline sw::Rect<T>::Rect(const sw::Vector2<T>& position, const sw::Vector2<T>& size) :
left(position.x),
top(position.y),
width(size.x),
height(size.y)
{}

template <typename T>
inline bool sw::Rect<T>::contains(T x, T y) const
{
    if (x > left
    &&  y > top
    &&  x < width
    &&  y < height)
        return (true);
    return (false);
}

template <typename T>
inline bool sw::Rect<T>::contains(const sw::Vector2<T>& point) const
{
    if (point.x > left
    &&  point.y > top
    &&  point.x < width
    &&  point.y < height)
        return (true);
    return (false);
}

template <typename T>
inline bool sw::Rect<T>::intersects(const sw::Rect<T>& rectangle) const
{
    if (rectangle.width  < left
    ||  rectangle.height < top
    ||  rectangle.left   > width
    ||  rectangle.top    > height)
        return (false);
    return (true);
}

template <typename T>
inline sw::Rect<T> operator+(const sw::Rect<T>& left, const sw::Rect<T> right)
{
    return (sw::Rect<T>{left.left, left.top, left.width + right.width, left.height + right.height});
}

template <typename T>
inline sw::Rect<T> operator-(const sw::Rect<T>& left, const sw::Rect<T> right)
{
    return (sw::Rect<T>{left.left, left.top, left.width - right.width, left.height - right.height});
}

template <typename T>
inline sw::Rect<T> operator*(const sw::Rect<T>& left, const sw::Rect<T> right)
{
    return (sw::Rect<T>{left.left, left.top, left.width * right.width, left.height * right.height});
}

template <typename T>
inline sw::Rect<T> operator/(const sw::Rect<T>& left, const sw::Rect<T> right)
{
    return (sw::Rect<T>{left.left, left.top, left.width / right.width, left.height / right.height});
}

template <typename T>
inline sw::Rect<T> operator%(const sw::Rect<T>& left, const sw::Rect<T> right)
{
    return (sw::Rect<T>{left.left, left.top, left.width % right.width, left.height % right.height});
}

template <typename T>
inline sw::Rect<T>& operator+=(sw::Rect<T>& left, const sw::Rect<T> right)
{
    left.width += right.width;
    left.height += right.height;
    return (left);
}

template <typename T>
inline sw::Rect<T>& operator-=(sw::Rect<T>& left, const sw::Rect<T> right)
{
    left.width -= right.width;
    left.height -= right.height;
    return (left);
}

template <typename T>
inline sw::Rect<T>& operator*=(sw::Rect<T>& left, const sw::Rect<T> right)
{
    left.width *= right.width;
    left.height *= right.height;
    return (left);
}

template <typename T>
inline sw::Rect<T>& operator/=(sw::Rect<T>& left, const sw::Rect<T> right)
{
    left.width /= right.width;
    left.height /= right.height;
    return (left);
}

template <typename T>
inline sw::Rect<T>& operator%=(sw::Rect<T>& left, const sw::Rect<T> right)
{
    left.width %= right.width;
    left.height %= right.height;
    return (left);
}

template <typename T>
inline bool operator!=(const sw::Rect<T>& left, const sw::Rect<T>& right)
{
    if (left.left   != right.left
    ||  left.top    != right.top
    ||  left.width  != right.width
    ||  left.height != right.height)
        return (true);
    return (false);
}

template <typename T>
inline bool operator==(const sw::Rect<T>& left, const sw::Rect<T>& right)
{
    if (left.left   == right.left
    &&  left.top    == right.top
    &&  left.width  == right.width
    &&  left.height == right.height)
        return (true);
    return (false);
}

template <typename T>
inline bool operator<(const sw::Rect<T>& left, const sw::Rect<T>& right)
{
    if (left.width * left.height < right.width * right.height)
        return (true);
    return (false);
}

template <typename T>
inline bool operator>(const sw::Rect<T>& left, const sw::Rect<T>& right)
{
    if (left.width * left.height > right.width * right.height)
        return (true);
    return (false);
}

template <typename T>
inline bool operator<=(const sw::Rect<T>& left, const sw::Rect<T>& right)
{
    if (left.width * left.height <= right.width * right.height)
        return (true);
    return (false);
}

template <typename T>
inline bool operator>=(const sw::Rect<T>& left, const sw::Rect<T>& right)
{
    if (left.width * left.height >= right.width * right.height)
        return (true);
    return (false);
}