/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** IManager.hpp
*/

#ifndef __SHIPWRECK_IFACTORY_HPP__
#define __SHIPWRECK_IFACTORY_HPP__

#include <string>

#include "concepts.hpp"

namespace sw
{

    class IManager
    {

        public:
            virtual ~IManager() = default;

            virtual AScene& scene() const = 0;
            virtual std::string name() const = 0;
            virtual bool isActive() const = 0;
            virtual void setActive(bool value) = 0;

            virtual bool hasComponent(const std::string& entityName) const = 0;
            virtual void setLayer(const std::string& entityName, int layer) = 0;
            [[nodiscard]] virtual int getLayer(const std::string& entityName) const = 0;
            virtual void deleteComponent(const std::string& entityName) = 0;

            virtual void load() = 0;
            virtual void update() = 0;
            virtual void unload() = 0;

    }; // class IManager

} // namespace sw

#endif // __SHIPWRECK_IFACTORY_HPP__