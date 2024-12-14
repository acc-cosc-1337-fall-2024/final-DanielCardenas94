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

#include "../src/shooter.h"

TEST_CASE("Shooter creates rolls and tracks values") {
    Die die1, die2;
    Shooter shooter;

    for (int i = 0; i < 10; ++i) {
        Roll* roll = shooter.throw_dice(die1, die2);
        int result = roll->roll_value();
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }
}

#include "../src/come_out_phase.h"
#include "../src/point_phase.h"

TEST_CASE("ComeOutPhase correctly identifies roll outcomes") {
    Die die1, die2;
    Roll roll(die1, die2);

    ComeOutPhase come_out_phase;
    roll.roll_dice();
    RollOutcome outcome = come_out_phase.get_outcome(&roll);
    REQUIRE(outcome == RollOutcome::natural ||
            outcome == RollOutcome::craps ||
            outcome == RollOutcome::point);
}

TEST_CASE("PointPhase correctly identifies roll outcomes") {
    Die die1, die2;
    Roll roll(die1, die2);

    int point = 5;
    PointPhase point_phase(point);
    roll.roll_dice();
    RollOutcome outcome = point_phase.get_outcome(&roll);
    REQUIRE(outcome == RollOutcome::point ||
            outcome == RollOutcome::seven_out ||
            outcome == RollOutcome::nopoint);
}

