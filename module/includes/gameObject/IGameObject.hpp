/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * IGameObject.cpp
 *
 * Description:
 */

#ifndef SHIPWRECK_ENGINE_IGAMEOBJECT_HPP
#define SHIPWRECK_ENGINE_IGAMEOBJECT_HPP

#include <string>

namespace sw
{
    class Scene;

    class IGameObject
    {
        public:
            /// @brief Default @c Destructor of an @b _IEntity.
            virtual ~IGameObject() = default;

            /// @brief Return the name of the @b Entity.
            ///
            /// @return The @b Entity name.
            [[nodiscard]] virtual std::string name() const = 0;

            /// @brief Return a reference of the parent @b Scene of the @b Entity.
            ///
            /// @return The parent @b Scene.
            virtual Scene& scene() = 0;

            /// @brief Return the activity of the @b Component.
            ///
            /// @return True or false.
            /// True by default, so the @b Manager will update its component.
            /// If it is false, the @b Manager will not update its component.
            [[nodiscard]] virtual bool isActive() const = 0;

            /// @brief Change the activity of the @b Component.
            ///
            /// @param value True or false.
            /// True by default, so the @b Manager will update its component.
            /// If it is set to false, the @b Manager will not update its component.
            virtual void setActive(bool value) = 0;

            /// @brief Make a requeste to the @b Manager corresponding to the
            /// given name to delete the @b Component associate with the @b Entity.
            ///
            /// @param managerName The manager name.
            virtual void setLayer(const std::string& managerName, int layer) = 0;
    };
}

#endif //SHIPWRECK_ENGINE_IGAMEOBJECT_HPP
