/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** AManager.hpp
*/

#ifndef __SHIPWRECK_AFACTORY_HPP__
#define __SHIPWRECK_AFACTORY_HPP__

#include <iostream>
#include <utility>
#include <unordered_map>
#include <string>
#include <memory>
#include <type_traits>

#include "IManager.hpp"
#include "engine/Engine.hpp"
#include "scene/AScene.hpp"
#include "error/Error.hpp"
#include "component/IComponent.hpp"

namespace sw
{

    template <ConcreteComponent Cpt>
    class AManager :
        public IManager
    {

        protected:
            class Components :
                private std::unordered_map<std::string, std::unique_ptr<Cpt>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<Cpt>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<Cpt>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<Cpt>>::operator[];

                friend AManager;

            } m_componentMap;

            class ComponentLayer :
                private std::forward_list<std::pair<int, std::string>>
            {
                private:
                    bool needSort;

                public:
                    using std::forward_list<std::pair<int, std::string>>::begin;
                    using std::forward_list<std::pair<int, std::string>>::end;

                friend AManager;

            } m_componentLayer;

            AScene& m_scene;
            bool m_isActive;
            const std::string m_name;

            bool m_isLoad;

            virtual void onUpdate() = 0;

        public:
            AManager(const std::string& managerName, AScene& sceneRef);
            ~AManager();

            AScene& scene() const override;
            std::string name() const override;
            bool isActive() const override;
            void setActive(bool value) override;

            void load() override;
            void update() override;
            void unload() override;

            template <typename... Args>
            Cpt& createComponent(const std::string& entityName, Args... values);
            template <ConcreteComponent ChildCpt, typename... Args>
            ChildCpt& createComponent(const std::string& entityName, Args... values);

            bool hasComponent(const std::string& entityName) const override;
            void deleteComponent(const std::string& entityName) override;

            void setLayer(const std::string& entityName, int layer) override;
            [[nodiscard]] int getLayer(const std::string& entityName) const override;

            std::unordered_map<std::string, std::unique_ptr<Cpt>>::iterator begin();
            std::unordered_map<std::string, std::unique_ptr<Cpt>>::iterator end();
            Cpt& operator[](const std::string& entityName);

        template <ConcreteComponent T>
        friend std::ostream& operator<<(std::ostream& os, AManager<T>& manager);

    }; // class AManager

    #include "AManager.inl"

} // namespace sw

#endif // __SHIPWRECK_AFACTORY_HPP__