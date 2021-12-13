/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Speech.hpp
*/

#ifndef __Speech_H__
#define __Speech_H__

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <vector>

#include "utils/Chrono.hpp"

namespace sw
{

    class Speech
    {

        private:
            static std::vector<std::pair<std::string, std::string>> logList;
            static std::vector<std::pair<std::string, std::string>> lastLogList;

            static std::string time();

        public:
            static bool colorized;
            static bool displayed;
            static bool dispError;
            static bool dispWarning;
            static bool dispDebug;
            static bool dispInfo;
            static bool clearOnPlay;
            class Color {
                public:
                    static constexpr char const *Reset        {"\e[0m"};
                    static constexpr char const *Bold         {"\e[1m"};
                    static constexpr char const *Dim          {"\e[2m"};
                    static constexpr char const *Underlined   {"\e[4m"};
                    static constexpr char const *Blink        {"\e[5m"};
                    static constexpr char const *Inverted     {"\e[7m"};
                    static constexpr char const *Hidden       {"\e[8m"};

                    static constexpr char const *White        {"\e[39m"};
                    static constexpr char const *Black        {"\e[30m"};
                    static constexpr char const *Grey         {"\e[90m"};
                    static constexpr char const *Red          {"\e[31m"};
                    static constexpr char const *Green        {"\e[32m"};
                    static constexpr char const *Yellow       {"\e[33m"};
                    static constexpr char const *Blue         {"\e[34m"};
                    static constexpr char const *Magenta      {"\e[35m"};
                    static constexpr char const *Cyan         {"\e[36m"};

                    static constexpr char const *LightWhite   {"\e[97m"};
                    static constexpr char const *LightGrey    {"\e[246m"};
                    static constexpr char const *LightRed     {"\e[91m"};
                    static constexpr char const *LightGreen   {"\e[92m"};
                    static constexpr char const *LightYellow  {"\e[93m"};
                    static constexpr char const *LightBlue    {"\e[94m"};
                    static constexpr char const *LightMagenta {"\e[95m"};
                    static constexpr char const *LightCyan    {"\e[96m"};

                    static constexpr char const *BackWhite    {"\e[49m"};
                    static constexpr char const *BackBlack    {"\e[40m"};
                    static constexpr char const *BackGrey     {"\e[100m"};
                    static constexpr char const *BackRed      {"\e[41m"};
                    static constexpr char const *BackGreen    {"\e[42m"};
                    static constexpr char const *BackYellow   {"\e[43m"};
                    static constexpr char const *BackBlue     {"\e[44m"};
                    static constexpr char const *BackMagenta  {"\e[45m"};
                    static constexpr char const *BackCyan     {"\e[46m"};

                    static constexpr char const *BackLightWhite  {"\e[107m"};
                    static constexpr char const *BackLightGrey   {"\e[47m"};
                    static constexpr char const *BackLightRed    {"\e[101m"};
                    static constexpr char const *BackLightGreen  {"\e[102m"};
                    static constexpr char const *BackLightYellow {"\e[103m"};
                    static constexpr char const *BackLightBlue   {"\e[104m"};
                    static constexpr char const *BackLightMagenta{"\e[105m"};
                    static constexpr char const *BackLightCyan   {"\e[106m"};
            };

            static void Info(std::string str, std::string code = "0");
            static void Debug(std::string str, std::string code = "0");
            static void Warning(std::string str, std::string code = "0");
            static void Error(std::string str, std::string code = "0");
            static void flush();
            static void clear();

    }; // class Speech

} // namespace sw

#endif // __Speech_H__