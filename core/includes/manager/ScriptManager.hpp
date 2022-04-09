/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * ScriptManager.hpp
 *
 * Description:
 * Basic Component Manager for all Scripted Component.
 * Use it as template to your own Component Manager.
 */

#ifndef __SHIPWRECK_CORE_SCRIPTMANAGER_HPP__
#define __SHIPWRECK_CORE_SCRIPTMANAGER_HPP__

#include "AManager.hpp"

#include "../component/Component.hpp"

namespace sw
{

    class ScriptManager
        :   public AManager<Component>
    {

        public:
            using AManager<Component>::AManager;
            virtual ~ScriptManager() override = default;

            virtual void update() override {};
            void onUpdate() override {};

            virtual std::string type() const { return ("ScriptManager"); }

    }; // class ScriptManager

} // namespace sw

#endif // __SHIPWRECK_CORE_SCRIPTMANAGER_HPP__