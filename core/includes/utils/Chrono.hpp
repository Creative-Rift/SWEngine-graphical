/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Chrono.hpp
 *
 * Description:
 * Chrono class
 * It provide you a low encapsulation of std::chrono and allow you
 * to make simple chronometer.
 * You can start and stop it, but also make tour to get either the time
 * since the start or the time since the last tour.
 */

#ifndef __SHIPWRECK_CORE_CHRONO_HPP__
#define __SHIPWRECK_CORE_CHRONO_HPP__

#include <ostream>
#include <chrono>

namespace sw
{

    class Chrono
    {

        private:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief The start time point of a @b Chrono.
            /// It is set at all call to the start method.
            //
            std::chrono::time_point<std::chrono::steady_clock> m_start;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The tour time point of a @b Chrono.
            /// It is set at all call to the tour method.
            //
            std::chrono::time_point<std::chrono::steady_clock> m_tour;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The last time point of a @b Chrono. It is corresponding to
            /// either the current time or the time you stoped or paused the @b Chrono.
            /// It is set when the time is get.
            //
            mutable std::chrono::time_point<std::chrono::steady_clock> m_end;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief The status of the chrono.
            /// If it is true, the chrono is running. If it is false, the chrono
            /// is either paused or stoped.
            //
            bool m_isRunning;
            ///

        public:
            enum ctorState { Wait, Lauch };

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Constructor of a @b Chrono.
            /// You can define the constructor status, whether or not it should
            /// be run when created.
            ///
            /// @param state 'Lauch' if you want to start the chrono directly after
            /// have been created, 'Wait' otherwise.
            //
            explicit Chrono(ctorState state = Wait);
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Default @c Destructor of a @b Chrono.
            //
            ~Chrono() = default;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Start the @b Chrono.
            //
            void start();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Stop the @b Chrono. Then, if you try get the time, it will
            /// not change.
            //
            void stop();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Make a checkpoint. Then, you can either get the time since
            /// the start or the last checkpoint.
            //
            void tour();
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the time since the last checkpoint (call to the tour function).
            ///
            /// @return The time in second.
            //
            double getElapsedTime() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the time since the start of the @b Chrono
            /// (call to the start function).
            ///
            /// @return The time in second.
            //
            double getTotalTime() const;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Get the status of the @b Chrono.
            ///
            /// @return True if it is running, false otherwise.
            //
            [[nodiscard]] bool isRunning() const;
            ///

    }; // class Chrono

    std::ostream& operator<<(std::ostream& os, const Chrono& chrono);

    #include "Chrono.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_CHRONO_HPP__