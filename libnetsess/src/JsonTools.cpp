#include <netsess/JsonTools.hpp>

namespace network::json {
    constexpr uint8_t power_of_2_digits_count[65] = {
        20,
        19, 19, 19, 19,
        18, 18, 18,
        17, 17, 17,
        16, 16, 16, 16,
        15, 15, 15,
        14, 14, 14,
        13, 13, 13, 13,
        12, 12, 12,
        11, 11, 11,
        10, 10, 10, 10,
        9, 9, 9,
        8, 8, 8,
        7, 7, 7, 7,
        6, 6, 6,
        5, 5, 5,
        4, 4, 4, 4,
        3, 3, 3,
        2, 2, 2,
        1, 1, 1, 1
    };

	ParseJson::PredicateFunc ParseJson::DEFAULT_PRED = ParseJson::exists;
	JsonObject ParseJson::NULL_OBJECT = JsonObject();
	JsonArray ParseJson::NULL_ARRAY = JsonArray();
}