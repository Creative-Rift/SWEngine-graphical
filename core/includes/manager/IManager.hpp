/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * IManager.hpp
 *
 * Description:
 * Interface class for Component Manager
 * A Component Manager is used to manage the Components for all the Entities
 * that need it.
 * A Component Manager can only have one type of Component (or an inherited one).
 * A Component Manager can only store one Component per Entity.
 */

#ifndef __SHIPWRECK_CORE_IMANAGER_HPP__
#define __SHIPWRECK_CORE_IMANAGER_HPP__

#include <string>

#include "../concepts.hpp"

namespace sw
{

    class _IManager
    {

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b Manager.
            //
            virtual ~_IManager() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the name of the @b Manager.
            ///
            /// @return The @b Manager name.
            //
            virtual std::string name() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a reference of the parent @b Scene of the @b Manager.
            ///
            /// @return The parent @b Scene.
            //
            virtual AScene& scene() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the activity of the @b Manager.
            ///
            /// @return True or false.
            /// True by default, so the @b Scene will update it.
            /// If it is false, the @b Scene will not update it.
            //
            virtual bool isActive() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Change the activity of the @b Manager.
            ///
            /// @param value True or false.
            /// True by default, so the @b Scene will update it.
            /// If it is false, the @b Scene will not update it.
            //
            virtual void setActive(bool value) = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return the statut of the @b Manager.
            ///
            /// @return True if the @b Manager is load. False if not.
            //
            virtual bool isLoad() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Return a string corresponding to the type name of the @b Manager.
            ///
            /// @return The type name of the @b Manager.
            //
            virtual std::string type() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to initialize the @b Manager.
            //
            virtual void load() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to update the @b Manager.
            //
            virtual void update() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Function called to terminate the @b Manager.
            //
            virtual void unload() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Verify if the @b Component associate with the @b Entity
            /// corresponding to the given name exist or not.
            ///
            /// @param entityName The @b Entity Name.
            ///
            /// @return True if it exist, false if not.
            //
            virtual bool hasComponent(const std::string& entityName) const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Delete the @b Component associate with the @b Entity
            /// corresponding to the given name.
            ///
            /// @param entityName The @b Entity Name.
            //
            virtual void deleteComponent(const std::string& entityName) = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Delete all the existing @b Components of the @b Manager.
            //
            virtual void eraseComponents() = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Calculate the count of @b Components stored in the @b Manager.
            ///
            /// @return The number of @b Components.
            //
            virtual std::size_t componentsCount() const = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Set the layer of the @b Component associate with the @b Entity
            /// corresponding to the given name.
            ///
            /// @param managerName The @b Manager name.
            //
            virtual void setLayer(const std::string& entityName, int layer) = 0;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the @b Component layer associate with the @b Entity
            /// corresponding to the given name.
            ///
            /// @param entityName The @b Entity name.
            ///
            /// @return The layer of the wanted @b Component.
            //
            [[nodiscard]] virtual int getLayer(const std::string& entityName) const = 0;
            ///

    }; // class IManager

} // namespace sw

#endif // __SHIPWRECK_CORE_IMANAGER_HPP__