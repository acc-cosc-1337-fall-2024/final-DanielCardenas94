#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <iostream>
#include <ctime>

int main() {
    srand(time(0)); // Seed random number generator

    Die die1, die2;
    Shooter shooter;

    ComeOutPhase come_out_phase;
    Roll* roll = shooter.throw_dice(die1, die2);

    while (come_out_phase.get_outcome(roll) == RollOutcome::natural ||
           come_out_phase.get_outcome(roll) == RollOutcome::craps) {
        std::cout << "Rolled " << roll->roll_value() << " roll again" << std::endl;
        roll = shooter.throw_dice(die1, die2);
    }

    std::cout << "Rolled " << roll->roll_value() << " start of point phase" << std::endl;
    int point = roll->roll_value();

    PointPhase point_phase(point);
    roll = shooter.throw_dice(die1, die2);

    while (point_phase.get_outcome(roll) != RollOutcome::seven_out &&
           point_phase.get_outcome(roll) != RollOutcome::nopoint) {
        std::cout << "Rolled " << roll->roll_value() << " roll again" << std::endl;
        roll = shooter.throw_dice(die1, die2);
    }

    std::cout << "Rolled " << roll->roll_value() << " end of point phase" << std::endl;
    shooter.display_rolled_values();

    return 0;
}
