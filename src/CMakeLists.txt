add_library(game_lib
    game/Board.cpp
    game/Game.cpp
    game/Player.cpp
)

target_include_directories(game_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/game)
add_executable(TicTacToe main.cpp)
target_link_libraries(TicTacToe PRIVATE game_lib)
