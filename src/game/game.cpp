#include "game.hpp"
#include "raylib.h"
#include "iostream"
#include "../board/board.hpp"

// Make sure the Board class is declared in board.hpp
//default constructor
Game::Game()
{
    std::cout << "Game Object initialized";
}
// copy constructor
Game::Game(Game &old_game)
{

}

void Game::run()
{
    Board board;
    while (!WindowShouldClose()) {
        BeginDrawing();
        board.generateBoard();
        board.setDefaultBoard();
        ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();
}
