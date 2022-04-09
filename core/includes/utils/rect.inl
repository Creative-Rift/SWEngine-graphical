/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * rect.inl
 *
 * Description:
 * Rect functions implementation
 */

template <typename T>
inline sw::Rect<T>::Rect()
    :   left(0),
        top(0),
        width(0),
        height(0)
{}

template <typename T>
inline sw::Rect<T>::Rect(T setLeft, T setTop, T setWidth, T setHeight)
    :   left(setLeft),
        top(setTop),
        width(setWidth),
        height(setHeight)
{}

template <typename T>
inline sw::Rect<T>::Rect(const sw::Vector2<T>& position, const sw::Vector2<T>& size)
    :   left(position.x),
        top(position.y),
        width(size.x),
        height(size.y)
{}

template <typename T>
inline bool sw::Rect<T>::contains(T x, T y) const
{
    if (x > left
    &&  y > top
    &&  x < left + width
    &&  y < top  + height)
        return (true);
    return (false);
}

template <typename T>
inline bool sw::Rect<T>::contains(const sw::Vector2<T>& point) const
{
    if (point.x > left
    &&  point.y > top
    &&  point.x < left + width
    &&  point.y < top  + height)
        return (true);
    return (false);
}

template <typename T>
inline bool sw::Rect<T>::intersects(const sw::Rect<T>& rectangle) const
{
    if (rectangle.left + rectangle.width  < left
    ||  rectangle.top  + rectangle.height < top
    ||  rectangle.left                    > left + width
    ||  rectangle.top                     > top  + height)
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

template <typename T>
std::ostream& operator<<(std::ostream& os, const sw::Rect<T>& rect)
{
    os  << "Rectangle<" << typeid(rect.left).name() << "> : [ left:" << rect.left << " , top:" << rect.top << " , width" << rect.width << " , height:" << rect.height << " ]\n";
    return (os);
}