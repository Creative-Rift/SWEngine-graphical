/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Log.hpp
 *
 * Description:
 * Header file to generalize the log messages use by Speech Info, Warning or Error.
 * You can create your proper log messages to use in your code with the Log class.
 */

#ifndef __SHIPWRECK_CORE_LOG_HPP__
#define __SHIPWRECK_CORE_LOG_HPP__

#include <string>
#include <iostream>

#define FUNCTION __FUNCTION__

namespace sw
{

    class Log
    {

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The message of the @b Log. It contains more informations
            /// about the Info, Warning or Error that is send.
            //
            std::string message;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The code of the @b Log. It is a four-digit code.
            ///
            /// @see The online documentation contains a well made topic.
            //
            std::string code;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of a @b Log.
            ///
            /// @param message The message transfered by the @b Log.
            /// @param code The unique code of the @b Log.
            //
            Log(const std::string& messageValue, const std::string& codeValue = "0")
                :   message(messageValue),
                    code(codeValue)
            {}
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of an @b Entity.
            //
            ~Log() = default;
            ///


        /// Error Engine Load
        static Log error150(const std::string& function)
        { return Log(function + " - Engine can not be initialized", "4150"); }

        /// Error Engine Update
        static Log error160(const std::string& function)
        { return Log(function + " - Engine can not be updated", "4160"); }

        /// Error Engine Unload
        static Log error170(const std::string& function)
        { return Log(function + " - Engine can not be terminated", "4170"); }

        /// Error Engine Find Module
        static Log error112(const std::string& function)
        { return Log(function + " - Don't have any Module", "4112"); }

        /// Error Engine Find Scene
        static Log error113(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Scene <" + sceneName + "> doesn't exist.", "4113"); }

        /// Error Scene Load
        static Log error350(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Scene <" + sceneName + "> can not be initialized", "4350"); }

        /// Error Scene Update
        static Log error360(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Scene <" + sceneName + "> can not be updated", "4360"); }

        /// Error Scene Unload
        static Log error370(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Scene <" + sceneName + "> can not be terminated", "4370"); }

        /// Error Scene Find Manager
        static Log error314(const std::string& function, const std::string& sceneName, const std::string& managerName)
        { return Log(function + " - " + sceneName + " - Manager <" + managerName + "> doesn't exist.", "4314"); }

        /// Error Scene Find Entity
        static Log error315(const std::string& function, const std::string& sceneName, const std::string& entityName)
        { return Log(function + " - " + sceneName + " - Entity <" + entityName + "> doesn't exist.", "3315"); }

        /// Error Manager Load
        static Log error450(const std::string& function, const std::string& managerName)
        { return Log(function + " - Manager <" + managerName + "> can not be loaded.", "4450"); }

        /// Error Manager Update
        static Log error460(const std::string& function, const std::string& managerName)
        { return Log(function + " - Manager <" + managerName + "> can not be updated.", "4460"); }

        /// Error Manager Unload
        static Log error470(const std::string& function, const std::string& managerName)
        { return Log(function + " - Manager <" + managerName + "> can not be unloaded.", "4470"); }

        /// Error Manager Find Entity
        static Log error415(const std::string& function, const std::string& managerName, const std::string& entityName, const std::string& sceneName)
        { return Log(function + " - " + managerName + " - Entity <" + entityName + "> for Scene <" + sceneName + "> doesn't exist.", "4415"); }

        /// Error Manager Find Component
        static Log error416(const std::string& function, const std::string& managerName, const std::string& entityName)
        { return Log(function + " - <" + managerName + "> - Component for Entity <" + entityName + "> doesn't exist.", "4416"); }

        /// Error Entity Find Component
        static Log error516(const std::string& function, const std::string& entityName, const std::string& managerName)
        { return Log(function + " - " + entityName + " - Its Component in <" + managerName + "> doesn't exist.", "4516"); }

        /// Error Entity Find Manager
        static Log error514(const std::string& function, const std::string& entityName, const std::string& managerName)
        { return Log(function + " - " + entityName + " - Manager <" + managerName + "> doesn't exist.", "4514"); }

        static Log errorA1B(const std::string& function, const std::string& sceneName, const std::string& eventName)
        { return Log(function + " - Event <" + eventName + "> doesn't exist in EventManager of Scene <" + sceneName + ">.", "4A1B"); }



        /// Warning Engine Load
        static Log warning150(const std::string& function)
        { return Log(function + " - Engine is already initialize !", "3150"); }

        /// Warning Engine Update
        static Log warning160(const std::string& function)
        { return Log(function + " - Engine can not be update because it was not loaded !", "3160"); }

        /// Warning Engine Unload
        static Log warning170(const std::string& function)
        { return Log(function + " - Engine was already terminated !", "3170"); }

        /// Warning Engine Find Module
        static Log warning112(const std::string& function)
        { return Log(function + " - Don't have any Module.", "3112"); }

        /// Warning Engine Create Module
        static Log warning122(const std::string& function)
        { return Log(function + " - Module already exist. Return the existing module.", "3122"); }

        /// Warning Engine Delete Module
        static Log warning132(const std::string& function)
        { return Log(function + " - Don't have any Module. Can't delete it.", "3132"); }

        /// Warning Engine Find Scene
        static Log warning113(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Scene <" + sceneName + "> doesn't exist.", "3113"); }

        /// Warning Engine Create Scene
        static Log warning123(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Scene <" + sceneName + "> - already exist. Return the existing scene.", "3123"); }

        /// Warning Engine Delete Scene
        static Log warning133(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Scene <" + sceneName + "> doesn't exist. Can't delete it.", "3133"); }

        /// Warning Scene Load
        static Log warning350(const std::string& function, const std::string& sceneName)
        { return Log(function + " - " + sceneName + " - was already loaded !", "3350"); }

        /// Warning Scene Update
        static Log warning360(const std::string& function, const std::string& sceneName)
        { return Log(function + " - " + sceneName + " - can not be updated because it was not loaded.", "3360"); }

        /// Warning Scene Unload
        static Log warning370(const std::string& function, const std::string& sceneName)
        { return Log(function + " - " + sceneName + " - was already unloaded !", "3370"); }

        /// Warning Scene Find Manager
        static Log warning314(const std::string& function, const std::string& sceneName, const std::string& managerName)
        { return Log(function + " - " + sceneName + " - Manager <" + managerName + "> doesn't exist.", "3314"); }

        /// Warning Scene Create Manager
        static Log warning324(const std::string& function, const std::string& sceneName, const std::string& managerName)
        { return Log(function + " - " + sceneName + " - Manager <" + managerName + "> already exist. Return the existing manager", "3324"); }

        /// Warning Scene Delete Manager
        static Log warning334(const std::string& function, const std::string& sceneName, const std::string& managerName)
        { return Log(function + " - " + sceneName + " - Manager <" + managerName + "> doesn't exist. Can't delete it.", "3334"); }

        /// Warning Scene Find Entity
        static Log warning315(const std::string& function, const std::string& sceneName, const std::string& entityName)
        { return Log(function + " - " + sceneName + " - Entity <" + entityName + "> doesn't exist.", "3315"); }

        /// Warning Scene Create Entity
        static Log warning325(const std::string& function, const std::string& sceneName, const std::string& entityName)
        { return Log(function + " - " + sceneName + " - Entity <" + entityName + "> already exist. Return the existing Entity.", "3325"); }

        /// Warning Scene Delete Entity
        static Log warning335(const std::string& function, const std::string& sceneName, const std::string& entityName)
        { return Log(function + " - " + sceneName + " - Entity <" + entityName + "> doesn't exist. Can't delete it.", "3335"); }

        /// Warning Manager Load
        static Log warning450(const std::string& function, const std::string& managerName)
        { return Log(function + " - " + managerName + " - was already loaded !", "3450"); }

        /// Warning Manager Update
        static Log warning460(const std::string& function, const std::string& managerName)
        { return Log(function + " - " + managerName + " - can not be updated because it was not loaded.", "3460"); }

        /// Warning Manager Unload
        static Log warning470(const std::string& function, const std::string& managerName)
        { return Log(function + " - " + managerName + " - was already unloaded !", "3470"); }

        /// Warning Manager Find Component
        static Log warning416(const std::string& function, const std::string& managerName, const std::string& entityName)
        { return Log(function + " - " + managerName + " - Component for Entity <" + entityName + "> doesn't exist.", "3416"); }

        /// Warning Manager Create Component
        static Log warning426(const std::string& function, const std::string& managerName, const std::string& entityName)
        { return Log(function + " - " + managerName + " - Component for Entity <" + entityName + "> already exist. Return the existing Component.", "3426"); }

        /// Warning Manager Delete Component
        static Log warning436(const std::string& function, const std::string& managerName, const std::string& entityName)
        { return Log(function + " - " + managerName + " - Component for Entity <" + entityName + "> doesn't exist. Can't delete it.", "3436"); }

        /// Warning Entity Find Component
        static Log warning516(const std::string& function, const std::string& entityName, const std::string& managerName)
        { return Log(function + " - " + entityName + " - Its Component in <" + managerName + "> doesn't exist.", "3516"); }

        /// Warning Entity Create Component
        static Log warning526(const std::string& function, const std::string& entityName, const std::string& managerName)
        { return Log(function + " - " + entityName + " - Its Component in <" + managerName + "> already exist. Return the existing manager", "3526"); }

        /// Warning Entity Delete Component
        static Log warning536(const std::string& function, const std::string& entityName, const std::string& managerName)
        { return Log(function + " - " + entityName + " - Its Component in <" + managerName + "> doesn't exist. Can't delete it.", "3536"); }

        /// Warning EventManager Delete Event
        static Log warningA2B(const std::string& function, const std::string& sceneName, const std::string& eventName)
        { return Log(function + " - Event <" + eventName + "> already exist in EventManager of Scene <" + sceneName + ">. Return the existing Event.", "3A2B"); }

        /// Warning EventListener BadVariantAccess
        static Log warningC40(const std::string& function, const std::string& entityName)
        { return Log(function + " - EventListener linked with Entity <" + entityName + "> can't use this function. You might use the other catchEvent function.", "3C40"); }


        /// Warning Engine Load
        static Log info150(const std::string& function)
        { return Log(function + " - Initialize Engine ...", "1150"); }

        /// Warning Engine Load Successfully
        static Log info150_Success(const std::string& function)
        { return Log(function + " - Engine was successfully initialized !", "1150"); }

        /// Warning Engine Update
        static Log info160(const std::string& function)
        { return Log(function + " - Updating Engine ...", "1160"); }

        /// Warning Engine Update Successfully
        static Log info160_Success(const std::string& function)
        { return Log(function + " - Engine was successfully updated !", "1160"); }

        /// Warning Engine Unload
        static Log info170(const std::string& function)
        { return Log(function + " - Terminating Engine ...", "1170"); }

        /// Warning Engine Unload Successfully
        static Log info170_Success(const std::string& function)
        { return Log(function + " - Engine was successfully terminated !", "1170"); }

        /// Warning Scene Load
        static Log info350(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Loading Scene <" + sceneName + "> ...", "1350"); }

        /// Warning Scene Load Successfully
        static Log info350_Success(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Scene <" + sceneName + "> was successfully load !", "1350"); }

        /// Warning Scene Update
        static Log info360(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Updating Scene <" + sceneName + "> ...", "1360"); }

        /// Warning Scene Update Successfully
        static Log info360_Success(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Scene <" + sceneName + "> was successfully updated !", "1360"); }

        /// Warning Scene Unload
        static Log info370(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Unloading Scene <" + sceneName + "> ...", "1370"); }

        /// Warning Scene Unload Successfully
        static Log info370_Success(const std::string& function, const std::string& sceneName)
        { return Log(function + " - Scene <" + sceneName + "> was successfully unload !", "1370"); }


        /*
        static Log error(const std::string& function)
        { return Log(function + ); }

        static Log warning(const std::string& function)
        { return Log(function + ); }

        static Log info(const std::string& function)
        { return Log(function + ); }
        */

    };

    inline std::ostream& operator<<(std::ostream& os, const Log& log)
    {
        os << std::string("[") << log.code << std::string("] ") << log.message << std::endl;
        return (os);
    }

} // namespace sw

#endif // __SHIPWRECK_CORE_LOG_HPP__