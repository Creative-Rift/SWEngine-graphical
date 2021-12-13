/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** ScriptFact.hpp
*/

#ifndef __SCRIPTFACT_H__
#define __SCRIPTFACT_H__

#include "AManager.hpp"
#include "../component/Component.hpp"

namespace sw
{

    class AScriptFact
        :   public AManager<Component>
    {
        public:
            using AManager<Component>::AManager;
            ~AScriptFact() override = default;
    };

}

#endif // __SCRIPTFACT_H__