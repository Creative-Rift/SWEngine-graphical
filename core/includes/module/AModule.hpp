/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AModule.hpp
 *
 * Description:
 * Abstract class for Module.
 * A Module is used to encapsulate a Graphic Library to fit it with the Engine.
 * If you want to use a Graphic Library that are not developed for the ShipWreck Engine,
 * you need to create your own Module based on this class and override his functions.
 */

#ifndef __SHIPWRECK_CORE_AMODULE_HPP__
#define __SHIPWRECK_CORE_AMODULE_HPP__

#include <string>
#include <memory>
#include <ios>
#include <ostream>

#include "../Config.hpp"
#include "../concepts.hpp"

namespace sw
{

    class AModule
    {

        protected:
            bool m_isLoad;

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of an @b Module.
            ///
            AModule();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b Module.
            //
            virtual ~AModule() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the statut of the @b Module.
            ///
            /// @return True if the @b Module is load. False if not.
            //
            bool isLoad() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a string corresponding to the type name of the @b Module.
            ///
            /// @return The type name of the @b Module.
            //
            [[nodiscard]] virtual std::string type() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to initialize the @b Module.
            //
            virtual void initialize() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to check if the @b Module is able to run.
            //
            virtual bool isOk() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to update the @b Module.
            //
            virtual void update() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to terminate the @b Module.
            //
            virtual void terminate() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Create an instance of @b Resources needed that fit
            /// with the @b Module and can be used by the user throught the @b Engine.
            //
            virtual std::unique_ptr<sw::AResources> createResourceInstance() = 0;
            ///

            virtual void loadResourcesFile(const std::string& path) = 0;

    }; // class AModule

    std::ostream& operator<<(std::ostream& os, const AModule& module);

    #include "AModule.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_AMODULE_HPP__