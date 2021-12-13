/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** AModule.hpp
*/

#ifndef __SHIPWRECK_ISYSTEM_HPP__
#define __SHIPWRECK_ISYSTEM_HPP__

#include <string>
#include <memory>

#include "../resources/AResources.hpp"

namespace sw
{

    class AModule
    {

        protected:
            std::string m_name;
            bool m_isLoad;

            virtual void onInitialize() = 0;
            virtual void onUpdate() = 0;
            virtual void onTerminate() = 0;

        public:
            AModule(const std::string& name);
            virtual ~AModule() = default;

            std::string name() const;

            virtual void initialize() = 0;
            virtual bool isOk() = 0;
            virtual void update() = 0;
            virtual void terminate() = 0;
            virtual bool isDebuging() = 0;
            virtual std::unique_ptr<sw::AResources> createResourceInstance() = 0;

    }; // class AModule

} // namespace sw

#endif // __SHIPWRECK_ISYSTEM_HPP__