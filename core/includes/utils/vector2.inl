/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * vector2.inl
 *
 * Description:
 * Vector2 functions implementation
 */

template <typename T>
inline sw::Vector2<T>::Vector2()
{
    x = 0;
    y = 0;
}

template <typename T>
inline sw::Vector2<T>::Vector2(T X, T Y)
{
    x = X;
    y = Y;
}

template <typename T>
inline sw::Vector2<T> operator-(const sw::Vector2<T>& left, const sw::Vector2<T>& right)
{
    return (sw::Vector2<T>(left.x - right.x, left.y - right.y));
}

template <typename T>
inline sw::Vector2<T> operator-(const sw::Vector2<T>& right)
{
    return (sw::Vector2<T>(-right.x, -right.y));
}

template <typename T>
inline sw::Vector2<T> operator+(const sw::Vector2<T>& left, const sw::Vector2<T>& right)
{
    return (sw::Vector2<T>(left.x + right.x, left.y + right.y));
}

template <typename T>
inline sw::Vector2<T> operator*(const sw::Vector2<T>& left, const sw::Vector2<T>& right)
{
    return (sw::Vector2<T>(left.x * right.x, left.y * right.y));
}

template <typename T>
inline sw::Vector2<T> operator*(const sw::Vector2<T>& left, T right)
{
    return (sw::Vector2<T>(left.x * right, left.y * right));
}

template <typename T>
inline sw::Vector2<T> operator/(const sw::Vector2<T>& left, const sw::Vector2<T>& right)
{
    return (sw::Vector2<T>(left.x / right.x, left.y / right.y));
}

template <typename T>
inline sw::Vector2<T> operator/(const sw::Vector2<T>& left, T right)
{
    return (sw::Vector2<T>(left.x / right, left.y / right));
}

template <typename T>
inline sw::Vector2<T>& operator-=(sw::Vector2<T>& left, const sw::Vector2<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    return (left);
}

template <typename T>
inline sw::Vector2<T>& operator+=(sw::Vector2<T>& left, const sw::Vector2<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    return (left);
}

template <typename T>
inline sw::Vector2<T>& operator*=(sw::Vector2<T>& left, const sw::Vector2<T>& right)
{
    left.x *= right.x;
    left.y *= right.y;
    return (left);
}

template <typename T>
inline sw::Vector2<T>& operator*=(sw::Vector2<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    return (left);
}

template <typename T>
inline sw::Vector2<T>& operator/=(sw::Vector2<T>& left, const sw::Vector2<T>& right)
{
    left.x /= right.x;
    left.y /= right.y;
    return (left);
}

template <typename T>
inline sw::Vector2<T>& operator/=(sw::Vector2<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    return (left);
}

template <typename T>
inline bool operator==(const sw::Vector2<T>& left, const sw::Vector2<T>& right)
{
    return ((left.x == right.x) && (left.y == right.y));
}

template <typename T>
inline bool operator!=(const sw::Vector2<T>& left, const sw::Vector2<T>& right)
{
    return ((left.x != right.x) || (left.y != right.y));
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const sw::Vector2<T>& vector)
{
    os << "Vector<" << typeid(vector.x).name() << "> : [ x:" << vector.x << " , y:" << vector.y << " ]\n";
    return (os);
}