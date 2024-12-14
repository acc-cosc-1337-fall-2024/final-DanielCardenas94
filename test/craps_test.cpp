#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/die.h"

TEST_CASE("Die rolls return values between 1 and 6") {
    Die die;
    for (int i = 0; i < 10; ++i) {
        int roll_value = die.roll();
        REQUIRE(roll_value >= 1);
        REQUIRE(roll_value <= 6);
    }
}
