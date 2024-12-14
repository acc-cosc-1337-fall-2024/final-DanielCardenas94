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

#include "../src/roll.h"

TEST_CASE("Roll combines two dice and returns values between 2 and 12") {
    Die die1, die2;
    Roll roll(die1, die2);
    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        int result = roll.roll_value();
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }
}

