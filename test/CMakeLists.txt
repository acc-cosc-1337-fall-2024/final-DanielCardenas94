# Define the test executable
add_executable(craps_tests
    craps_test.cpp
)

# Link the test executable to the shared library
target_link_libraries(craps_tests craps_library)

# Register the test with CTest
add_test(NAME craps_tests COMMAND craps_tests)

# Specify include directories for headers
target_include_directories(craps_tests PRIVATE ../src)
