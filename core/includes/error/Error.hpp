/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Error.hpp
 *
 * Description:
 * Base class for error class.
 * Error provide a base class for all error you can find in the ShipWreck Engine.
 * We use it internaly but you also can use it to create your own errors.
 */

#ifndef __SHIPWRECK_CORE_ERROR_HPP__
#define __SHIPWRECK_CORE_ERROR_HPP__

#include <stdexcept>

#include "../Log.hpp"

namespace sw
{

    class Error :
        public std::exception
    {

        protected:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The code of the @b Error. It is a four-digit code.
            ///
            /// @see The online documentation contains a well made topic.
            //
            const std::string m_code;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The message of the @b Error. It contains more indication
            /// about the occuring @b Error.
            //
            const std::string m_message;
            ///

        public:
            Error() = delete;
            Error(Error &&) = delete;
            Error& operator=(Error const &) = delete;
            Error& operator=(Error&&) = delete;

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of an @b Error.
            ///
            /// @param message The message transfered by the @b Error.
            /// @param code The unique code of the @b Error.
            //
            Error(const std::string& message, const std::string& code);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Other @c Constructor of an @b Error. The message and
            /// the code of the log are use to create the Error.
            ///
            /// @param log The log used.
            //
            Error(const Log& log);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Other @c Constructor of an @b Error. The message and
            /// the code of the given error are use to create the new one.
            ///
            /// @param other The error to copy.
            //
            Error(const Error& other);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b Entity.
            //
            virtual ~Error() override = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the message of the @b Error.
            ///
            /// @return The @b Error message.
            //
            [[nodiscard]] const std::string& getMessage() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the message of the @b Error.
            ///
            /// @return The @b Error message.
            //
            [[nodiscard]] const char* what() const noexcept override;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the code of the @b Error.
            ///
            /// @return The @b Error message.
            //
            [[nodiscard]] const std::string& getCode() const;
            ///

    }; // class Error

    #include "Error.inl"

} // namespace sw

std::ostream &operator<<(std::ostream &s, const sw::Error &error);

#endif // __SHIPWRECK_CORE_ERROR_HPP__
