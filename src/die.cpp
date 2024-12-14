#include "die.h"
#include <cstdlib> // For rand()

int Die::roll() {
    return rand() % sides + 1; 
}
