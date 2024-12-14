#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll) {
    int value = roll->roll_value();
    if (value == 7 || value == 11) return RollOutcome::natural;
    if (value == 2 || value == 3 || value == 12) return RollOutcome::craps;
    return RollOutcome::point;
}

