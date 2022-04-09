/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Speech.hpp
 *
 * Description:
 * Speech class
 * The Speech class provide you a NICE system of console log.
 * Use it to disp Info, Debug, Warning or Error message with stylic output.
 *
 * (Warning /!\ The Creative Rift Society decline all responsibility in case
 * of explosion)
 */

#ifndef __SHIPWRECK_CORE_SPEECH_HPP__
#define __SHIPWRECK_CORE_SPEECH_HPP__

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <vector>
#include <map>

#include "Chrono.hpp"
#include "../Log.hpp"
#include "../Config.hpp"

namespace sw
{

    class SW_CORE_API_EXPORT Speech
    {

        private:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The list of logs. The pair is composed of two string.
            /// The first corresponding to the time the log was sent.
            /// The second corresponding to the log built with the message
            /// and the log sended.
            //
            static std::vector<std::pair<std::string, std::string>> m_logList;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The last list of logs. Each time the logs list is disp,
            /// it moves in this lastLogList and be cleared.
            /// It is used to stack same messages that was sent each frame.
            //
            static std::vector<std::pair<std::string, std::string>> m_lastLogList;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Used to get the time when a new log was sent.
            ///
            /// @return The actual time, in hh:mm:ss format.
            //
            static std::string time();
            //

            static bool isBlackList(std::string code);
            static bool isWhiteList(std::string code);

            static std::map<std::string, std::map<std::string, std::vector<std::string>>> m_listSpeech;

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief Define whether the logs will be in color or not.
            //
            static bool colorized;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Define whether the logs will be displayed or not.
            //
            static bool displayed;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Define whether the errors will be displayed or not.
            //
            static bool dispError;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Define whether the warnings will be displayed or not.
            //
            static bool dispWarning;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Define whether the debugs will be displayed or not.
            //
            static bool dispDebug;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Define whether the infos will be displayed or not.
            //
            static bool dispInfo;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Define whether the terminal will be cleared or not when
            /// the @b Engine will be initialized.
            //
            static bool clearOnPlay;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Define whether the time will be displayed or not.
            //
            static bool dispTime;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Define whether the errors will be displayed or not.
            //
            static bool stack;
            ///

            #if (__unix__)
                #define E_CHAR "\e"
            #elif (_WIN32)
                #define E_CHAR
            #endif

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Define some colors.
            //
            class Color {
                public:
                    static constexpr char const *Reset        {E_CHAR"[0m"};
                    static constexpr char const *Bold         {E_CHAR"[1m"};
                    static constexpr char const *Dim          {E_CHAR"[2m"};
                    static constexpr char const *Underlined   {E_CHAR"[4m"};
                    static constexpr char const *Blink        {E_CHAR"[5m"};
                    static constexpr char const *Inverted     {E_CHAR"[7m"};
                    static constexpr char const *Hidden       {E_CHAR"[8m"};

                    static constexpr char const *White        {E_CHAR"[39m"};
                    static constexpr char const *Black        {E_CHAR"[30m"};
                    static constexpr char const *Grey         {E_CHAR"[90m"};
                    static constexpr char const *Red          {E_CHAR"[31m"};
                    static constexpr char const *Green        {E_CHAR"[32m"};
                    static constexpr char const *Yellow       {E_CHAR"[33m"};
                    static constexpr char const *Blue         {E_CHAR"[34m"};
                    static constexpr char const *Magenta      {E_CHAR"[35m"};
                    static constexpr char const *Cyan         {E_CHAR"[36m"};

                    static constexpr char const *LightWhite   {E_CHAR"[97m"};
                    static constexpr char const *LightGrey    {E_CHAR"[246m"};
                    static constexpr char const *LightRed     {E_CHAR"[91m"};
                    static constexpr char const *LightGreen   {E_CHAR"[92m"};
                    static constexpr char const *LightYellow  {E_CHAR"[93m"};
                    static constexpr char const *LightBlue    {E_CHAR"[94m"};
                    static constexpr char const *LightMagenta {E_CHAR"[95m"};
                    static constexpr char const *LightCyan    {E_CHAR"[96m"};

                    static constexpr char const *BackWhite    {E_CHAR"[49m"};
                    static constexpr char const *BackBlack    {E_CHAR"[40m"};
                    static constexpr char const *BackGrey     {E_CHAR"[100m"};
                    static constexpr char const *BackRed      {E_CHAR"[41m"};
                    static constexpr char const *BackGreen    {E_CHAR"[42m"};
                    static constexpr char const *BackYellow   {E_CHAR"[43m"};
                    static constexpr char const *BackBlue     {E_CHAR"[44m"};
                    static constexpr char const *BackMagenta  {E_CHAR"[45m"};
                    static constexpr char const *BackCyan     {E_CHAR"[46m"};

                    static constexpr char const *BackLightWhite  {E_CHAR"[107m"};
                    static constexpr char const *BackLightGrey   {E_CHAR"[47m"};
                    static constexpr char const *BackLightRed    {E_CHAR"[101m"};
                    static constexpr char const *BackLightGreen  {E_CHAR"[102m"};
                    static constexpr char const *BackLightYellow {E_CHAR"[103m"};
                    static constexpr char const *BackLightBlue   {E_CHAR"[104m"};
                    static constexpr char const *BackLightMagenta{E_CHAR"[105m"};
                    static constexpr char const *BackLightCyan   {E_CHAR"[106m"};
            };


            /*////////////////////////////////////////////////////////////////*/
            /// @brief Emplace a new Info log with the given @b Log.
            /// The message and the code are copied.
            ///
            /// @param log The log to copy.
            //
            static void Info(const Log& log);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Emplace a new Info log with the given message and code.
            ///
            /// @param message The message to disp.
            /// @param code The code to disp.
            //
            static void Info(const std::string& message, const std::string& code = "0");
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Emplace a new Debug log with the given @b Log.
            /// The message and the code are copied.
            ///
            /// @param log The log to copy.
            //
            static void Debug(const Log& log);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Emplace a new Debug log with the given message and code.
            ///
            /// @param message The message to disp.
            /// @param code The code to disp.
            //
            static void Debug(const std::string& message, const std::string& code = "0");
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Emplace a new Warning log with the given @b Log.
            /// The message and the code are copied.
            ///
            /// @param log The log to copy.
            //
            static void Warning(const Log& log);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Emplace a new Warning log with the given message and code.
            ///
            /// @param message The message to disp.
            /// @param code The code to disp.
            //
            static void Warning(const std::string& message, const std::string& code = "0");
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Emplace a new Error log with the given @b Log.
            /// The message and the code are copied.
            ///
            /// @param log The log to copy.
            //
            static void Error(const Log& log);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Emplace a new Error log with the given message and code.
            ///
            /// @param message The message to disp.
            /// @param code The code to disp.
            //
            static void Error(const std::string& message, const std::string& code = "0");
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Write in the given out stream all the log saved.
            ///
            /// @param os The out stream, std::cout by default.
            //
            static void flush(std::ostream& os = std::cout);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Clear the given out stream.
            //
            static void clearConsole(std::ostream& os = std::cout);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Clear all the log saved.
            //
            static void clearLog();
            ///

            /*////////////////////////////////////////////////////////////////*/
            static void setDisplayed(bool value); // TODO Check if it usefull or not

            static void addBlackList(std::string list, std::string element);
            static void addWhiteList(std::string list, std::string element);
            static void ConfigSpeech();

    }; // class Speech

} // namespace sw

#endif // __SHIPWRECK_CORE_SPEECH_HPP__