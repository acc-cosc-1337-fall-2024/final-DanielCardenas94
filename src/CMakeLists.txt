# Define a library for shared components
add_library(craps_library
    die.h die.cpp
    roll.h roll.cpp
    shooter.h shooter.cpp
    phase.h phase.cpp
    point_phase.h point_phase.cpp
    come_out_phase.h come_out_phase.cpp
)

# Define the main program
add_executable(craps_exe
    main.cpp
    die.cpp
    roll.cpp
    shooter.cpp
    phase.cpp
    point_phase.cpp
    come_out_phase.cpp
)

# Link the library to the main program
target_link_libraries(craps_exe craps_library)



