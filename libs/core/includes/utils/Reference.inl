/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Reference.inl
*/

template <typename T>
sw::Reference<T>::Reference()
    :   m_value()
{}

template <typename T>
sw::Reference<T>::Reference(T& value)
    :   m_value(value)
{}

template <typename T>
void sw::Reference<T>::emplace(T& newValue)
{
    m_value.emplace(newValue);
}

template <typename T>
bool sw::Reference<T>::hasValue() const
{
    return (m_value.has_value());
}

template <typename T>
T& sw::Reference<T>::value() const
{
    return (m_value.value().get());
}

template <typename T>
T& sw::Reference<T>::operator=(T& newValue)
{
    m_value.emplace(newValue);
    return (m_value.value().get());
}

template <typename T>
T& sw::Reference<T>::operator*() const
{
    return (m_value.value().get());
}