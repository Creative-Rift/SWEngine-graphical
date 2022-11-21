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

#include "managers/base/AManager.hpp"

#include "../components/base/Component.hpp"

namespace sw
{

    class ScriptManager : public AManager<Component>
    {

        public:
            using AManager<Component>::AManager;
            virtual ~ScriptManager() override = default;

            void onUpdate() override {};

    }; // class ScriptManager

} // namespace sw

#endif // __SHIPWRECK_CORE_SCRIPTMANAGER_HPP__