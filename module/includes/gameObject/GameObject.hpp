/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * GameObject.hpp
 *
 * Description:
 */

#ifndef SHIPWRECK_ENGINE_GAMEOBJECT_HPP
#define SHIPWRECK_ENGINE_GAMEOBJECT_HPP

#include <string>
#include "concepts.hpp"
#include "../managers/base/AManager.hpp"

#include "scenes_manager/scene/Scene.hpp"
#include "gameObject/IGameObject.hpp"

namespace sw
{
    class Transform;

    class GameObject : public IGameObject
    {
        private:
            /// @brief The activity of an @b Entity.
            /// True by default, so the @b Manager will update its component.
            /// If it is false, the @b Manager will not update its component.
            bool m_isActive;

            /// @brief The name of the @b Entity.
            const std::string m_name;

            /// @brief The reference of the parent scene of the @b Entity.
            Scene& m_scene;

        public:

            Transform& transform;

            GameObject() = delete;

            /// @brief Default @c Constructor of an @b Entity.
            ///
            /// @param entityName The futur name of the @b Entity.
            /// @param sceneRef The reference of the parent @b Scene.
            GameObject(const std::string& gameObjectName, Scene& sceneRef);

            /// @brief Second @c Constructor of an @b Entity. You can determine
            /// the activity of the @b Entity directly.
            ///
            /// @param entityName The futur name of the @b Entity.
            /// @param sceneRef The reference of the parent @b Scene.
            /// @param isActive The activity of an @b Entity.
            ///
            /// If it is set to true, the @b Manager will update its component.
            /// If it is set to false, the @b Manager will not update its component.
            GameObject(const std::string& gameObjectName, Scene& sceneRef, bool isActive);

            /// @brief Default @c Destructor of an @b Entity.
            ~GameObject() override = default;

            /// @brief Return the name of the @b Entity.
            ///
            /// @return The @b Entity name.
            [[nodiscard]] std::string name() const override;

            /// @brief Return a reference of the parent @b Scene of the @b Entity.
            ///
            /// @return The parent @b Scene.
            Scene& scene() override;

            /// @brief Return the activity of the @b Entity.
            ///
            /// @return True or false.
            /// True by default, so the @b Manager will update its component.
            /// If it is false, the @b Manager will not update its component.
            bool isActive() const override;

            /// @brief Change the activity of the @b Entity.
            ///
            /// @param value True or false.
            /// True by default, so the @b Manager will update its component.
            /// If it is set to false, the @b Manager will not update its component.
            void setActive(bool value) override;

            /// @brief Add the @b Entity corresponding to the given name as
            /// a child of the @b Entity.
            ///
            /// @param entityName The futur @b Entity child name.
            ///void addChild(const std::string& entityName);

            /// @brief Remove the @b Entity corresponding to the given name as
            /// a child of the @b Entity.
            ///
            /// @param entityName The @b Entity child name to remove.
            ///void removeChild(const std::string& entityName);

            /// @brief Make a request to the @b Manager corresponding to the
            /// given name to create a @b Component for the @b Entity.
            ///
            /// @c ConcreteComponent Type of the wanted @b Component.
            ///
            /// @param managerName The @b Manager name.
            /// @param args The arguments for the @b Component constructor.
            ///
            /// @return The newly created @b Component.
            template <ConcreteComponent Cpt, typename... Args>
            Cpt& createComponent(const std::string& managerName, Args... values);

            /// @brief Make a request to the @b Manager corresponding to the
            /// given name to get the @b Component associate with the @b Entity.
            ///
            /// @c ConcreteComponent Type of the wanted @b Component.
            ///
            /// @param managerName The @b Manager name.
            ///
            /// @return The wanted @b Component.
            template <ConcreteComponent Cpt>
            Cpt& getComponent(const std::string& managerName);

            /// @brief Make a request to the @b Manager corresponding to the
            /// given name to check if the @b Component associate with the
            /// @b Entity exist.
            ///
            /// @param managerName The @b Manager name.
            ///
            /// @return True if it exist, false if not.
            [[nodiscard]] bool hasComponent(const std::string& managerName) const;

            /// @brief Make a request to the @b Manager corresponding to the
            /// given name to delete the @b Component associate with the @b Entity.
            ///
            /// @param managerName The @b Manager name.
            void deleteComponent(const std::string& managerName);

            /// @brief Make a request to the @b Manager corresponding to the
            /// given name to set the layer of the @b Component associate with the @b Entity.
            ///
            /// @param managerName The @b Manager name.
            void setLayer(const std::string& managerName, int layer) override;
    };

}

#include "GameObject.inl"

#endif //SHIPWRECK_ENGINE_GAMEOBJECT_HPP
