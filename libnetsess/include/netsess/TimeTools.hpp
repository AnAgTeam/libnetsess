#pragma once
#include <string>
#include <chrono>
#include <concepts>

namespace network {
    template<typename T>
    concept clock_time_point =
        std::same_as<T, std::chrono::time_point<typename T::clock>>;
    template<typename T>
    concept clock_duration =
        std::same_as<T, std::chrono::duration<typename T::rep, typename T::period>>;

    class TimeTools {
    public:
        template<clock_time_point T>
        static int64_t to_timestamp(T&& time) {
            return std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count();
        }
        template<clock_duration T>
        static int64_t to_timestamp(T&& duration) {
            return std::chrono::duration_cast<std::chrono::seconds>(duration).count();
        }

        template<clock_time_point T>
        static T from_timestamp(int64_t&& time_seconds) {
            return T{ std::chrono::seconds(time_seconds) };
        }
        template<clock_duration T>
        static T from_timestamp(int64_t&& time_seconds) {
            return std::chrono::system_clock::time_point{ std::chrono::seconds(time_seconds) }.time_since_epoch();
        }
    };
};