/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Reference.hpp
 *
 * Description:
 * Basic encapsulation of a std::optional<std::reference_wrapper<>>.
 * It allow you to create reference variable without initialize it.
 */

#ifndef __SHIPWRECK_CORE_REFERENCE_HPP__
#define __SHIPWRECK_CORE_REFERENCE_HPP__

#include <ostream>
#include <optional>
#include <functional>

namespace sw
{

    template <typename T>
    class Reference
    {

        private:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The stored reference.
            //
            std::optional<std::reference_wrapper<T>> m_value;
            ///

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The default @c Constructor.
            //
            Reference();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The other @c Constructor. You can emplace the reference
            /// directly.
            //
            explicit Reference(T& value);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The default @c Destructor.
            //
            ~Reference() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Store the given value.
            ///
            /// @param newValue A reference to stored.
            //
            void emplace(T& newValue);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Erase the referenced value.
            //
            void erase();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Check if the @b Reference has a value.
            ///
            /// @return True if a value is stored, false otherwise.
            //
            [[nodiscard]] bool hasValue() const;
            T& value() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Store the given value in the @b Reference.
            ///
            /// @return The stored value.
            //
            T& operator=(T& newValue);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the value stored in the @b Reference.
            ///
            /// @return The stored value.
            //
            T& operator*() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Checkif the stored reference is the same at the given @b Reference.
            ///
            /// @return The stored value.
            //
            bool operator==(const Reference<T>& other) const
            {
                return (m_value.value() == other.m_value.value());
            }
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Checkif the stored reference is the same at the given one.
            ///
            /// @return The stored value.
            //
            bool operator==(const T& other) const
            {
                return (m_value.value() == other);
            }
            ///

    }; // class Reference

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Reference<T>& ref);

    #include "Reference.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_REFERENCE_HPP__