cmake_minimum_required(VERSION 3.10)
project(TicTacToeTests)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tic_tac_toe_tests test_main.cpp)

target_link_libraries(tic_tac_toe_tests ${GTEST_BOTH_LIBRARIES} game_lib)
target_include_directories(tic_tac_toe_tests PRIVATE ../src/game)

add_test(NAME tic_tac_toe_tests COMMAND tic_tac_toe_tests)
