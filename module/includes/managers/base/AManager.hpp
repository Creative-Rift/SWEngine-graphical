/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AManager.hpp
 *
 * Description:
 * Abstract class for Component Manager
 * A Component Manager is used to manage the Components for all the Entities
 * that need it.
 * A Component Manager can only have one type of Component (or an inherited one).
 * A Component Manager can only store one Component per Entity.
 */

#ifndef __SHIPWRECK_CORE_AMANAGER_HPP__
#define __SHIPWRECK_CORE_AMANAGER_HPP__

#include <iostream>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>
#include <type_traits>

#include "IManager.hpp"
#include "scenes_manager/scene/Scene.hpp"
#include "components/base/IComponent.hpp"
#include "exception/Error.hpp"
#include "utils/Speech.hpp"
#include "Log.hpp"

namespace sw
{

    template <ConcreteComponent Cpt>
    class AManager :
        public _IManager
    {

        private:
            /// @brief Use to know if the @b Manager is load or unload.
            bool m_isLoad;

            /// @brief When a @b Component is delete, its name is first place in
            /// this set, in order to not pose any problem during the update.
            std::unordered_set<std::string> m_componentToDelete;

        protected:
            /// @brief The name of the @b Manager.
            const std::string m_name;

            /// @brief The reference of the parent scene of the @b Manager.
            Scene& m_scene;

            /// @brief The activity of the @b Manager.
            /// True by default, so the @b Scene will update it.
            /// If it is false, the @b Scene will not update it.
            bool m_isActive;

            class Components :
                public std::unordered_map<std::string, std::shared_ptr<Cpt>>
            {
                protected:
                    using std::unordered_map<std::string, std::shared_ptr<Cpt>>::at;

                public:
                    using std::unordered_map<std::string, std::shared_ptr<Cpt>>::begin;
                    using std::unordered_map<std::string, std::shared_ptr<Cpt>>::end;
                    using std::unordered_map<std::string, std::shared_ptr<Cpt>>::operator[];

                Cpt& get(const std::string& entityName);
                const Cpt& get(const std::string& entityName) const;

                friend AManager;
            }
            /// @brief The map use to store the created @b Components.
            ///
            /// @c Cpt Type of the wanted @b Component.
            ///
            /// @arg std::string          The @b Component name.
            /// @arg std::shared_ptr<Cpt> The @b Component itself.
            m_components;

            class ComponentsLayers :
                private std::forward_list<std::pair<int, std::string>>
            {
                private:
                    bool needSort;

                public:
                    using std::forward_list<std::pair<int, std::string>>::begin;
                    using std::forward_list<std::pair<int, std::string>>::end;

                friend AManager;
            }
            /// @brief The map use to reference the @b Components by their layers.
            ///
            /// @arg int         The @b Component layer.
            /// @arg std::string The @b Component name.
            m_componentsLayers;

            /// @brief Function called on the update of the @b Manager.
            virtual void onUpdate() = 0;

            /// @brief This function delete the requested @b Components at the end
            /// of the update.
            void deleteRequestedComponents();

        public:

            /// @brief Default @c Constructor of an @b Manager.
            ///
            /// @param managerName The futur name of the @b Manager.
            /// @param sceneRef The reference of the parent @b Scene.
            AManager(const std::string& managerName, Scene& sceneRef);

            /// @brief Default @c Destructor of an @b Manager.
            virtual ~AManager();

            /// @brief Return the name of the @b Manager.
            ///
            /// @return The @b Manager name.
            std::string name() const override;

            /// @brief Return a reference of the parent @b Scene of the @b Manager.
            ///
            /// @return The parent @b Scene.
            Scene& scene() const override;

            /// @brief Return the activity of the @b Manager.
            ///
            /// @return True or false.
            /// True by default, so the @b Scene will update it.
            /// If it is false, the @b Scene will not update it.
            bool isActive() const override;

            /// @brief Change the activity of the @b Manager.
            ///
            /// @param value True or false.
            /// True by default, so the @b Scene will update it.
            /// If it is false, the @b Scene will not update it.
            void setActive(bool value) override;

            /// @brief Return the statut of the @b Manager.
            ///
            /// @return True if the @b Manager is load. False if not.
            bool isLoad() const override;

            /// @brief Function called to initialize the @b Manager.
            void load() override;

            /// @brief Function called to update the @b Manager.
            void update() override;

            /// @brief Function called to terminate the @b Manager.
            void unload() override;

            /// @brief Create a @b Component for the @b Entity corresponding to
            /// the given name.
            ///
            /// @param entityName The @b Entity name.
            /// @param args The arguments for the @b Component constructor.
            ///
            /// @return The newly created @b Component.
            template <typename... Args>
            Cpt& createComponent(const std::string& entityName, Args... values);

            /// @brief Create a @b Component based on the @b Component type stored
            /// by the @b Manager for the @b Entity corresponding to the given name.
            ///
            /// @c ConcreteComponent Type of the wanted @b Component, inherited from
            /// the @b Component type stored by the @b Manager.
            ///
            /// @param entityName The @b Entity name.
            /// @param args The arguments for the @b Component constructor.
            ///
            /// @return The newly created @b Component.
            template <ConcreteChild<Cpt> ChildCpt, typename... Args>
            ChildCpt& createComponent(const std::string& entityName, Args... values);

            /// @brief Get the @b Component associate with the @b Entity
            /// corresponding to the given name.
            ///
            /// @param entityName The @b Entity name.
            ///
            /// @return The wanted @b Component.
            Cpt& operator[](const std::string& entityName);

            /// @brief Get the @b Component associate with the @b Entity
            /// corresponding to the given name.
            ///
            /// @param entityName The @b Entity name.
            ///
            /// @return The wanted @b Component.
            Cpt& getComponent(const std::string& entityName);

            /// @brief Get the @b Component based on the @b Component type stored
            /// by the @b Manager associate with the @b Entity corresponding
            /// to the given name.
            ///
            /// @c ConcreteComponent Type of the wanted @b Component, inherited from
            /// the @b Component type stored by the @b Manager.
            ///
            /// @param entityName The @b Entity name.
            ///
            /// @return The wanted @b Component.
            template <ConcreteChild<Cpt> ChildCpt>
            ChildCpt& getComponent(const std::string& entityName);

            /// @brief Verify if the @b Component associate with the @b Entity
            /// corresponding to the given name exist or not.
            ///
            /// @param entityName The @b Entity Name.
            ///
            /// @return True if it exist, false if not.
            bool hasComponent(const std::string& entityName) const override;

            /// @brief Delete the @b Component associate with the @b Entity
            /// corresponding to the given name.
            ///
            /// @param entityName The @b Entity Name.
            void deleteComponent(const std::string& entityName) override;

            /// @brief Delete all the existing @b Components of the @b Manager.
            void eraseComponents() override;

            /// @brief Calculate the number of @b Components stored in the @b Manager.
            ///
            /// @return The number of @b Components.
            std::size_t componentsCount() const override;

            /// @brief Set the layer of the @b Component associate with the @b Entity
            /// corresponding to the given name.
            ///
            /// @param managerName The @b Manager name.
            /// @param layer The new layer of the @b Component.
            void setLayer(const std::string& entityName, int layer) override;

            /// @brief Get the @b Component layer associate with the @b Entity
            /// corresponding to the given name.
            ///
            /// @param entityName The @b Entity name.
            ///
            /// @return The layer of the wanted @b Component.
            [[nodiscard]] int getLayer(const std::string& entityName) const override;

            /// @brief Get the first iterator of the @b Component list. Corresponding
            /// to the first pair of @b Component name and @b Component itself of the list.
            /// @warning It does not necessary match with the first @b Component created.
            ///
            /// @return The first iterator of the list.
            typename std::unordered_map<std::string, std::shared_ptr<Cpt>>::iterator begin();

            /// @brief Get the last iterator of the @b Component list. Corresponding
            /// to the last pair of @b Component name and @b Component itself of the list.
            /// @warning It does not necessary match with the last @b Component created.
            ///
            /// @return The last iterator of the list.
            typename std::unordered_map<std::string, std::shared_ptr<Cpt>>::iterator end();

            [[nodiscard]] virtual YAML::Node save() const override;

    }; // class AManager

    template <ConcreteComponent Cpt>
    std::ostream& operator<<(std::ostream& os, const AManager<Cpt>& manager);

#include "AManager.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_AMANAGER_HPP__