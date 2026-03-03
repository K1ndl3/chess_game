#include "game.hpp"
#include "raylib.h"
#include "iostream"
#include <string>
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
    board.setDefaultBoard();
    enum class GameState { Start, Playing, End } state = GameState::Start;

    Rectangle restartBtn{300, 700, 120, 40};
    Rectangle quitBtn{440, 700, 120, 40};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        if (state == GameState::Start) {
            DrawText("Welcome to Chess", 220, 300, 40, BLACK);
            DrawText("Press ENTER to start", 240, 360, 30, DARKGRAY);
            DrawText("Or click to start", 280, 400, 20, DARKGRAY);
            if (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                state = GameState::Playing;
            }
        } else if (state == GameState::Playing) {
            // process input (select/move)
            board.userInput();
            // draw board and pieces
            board.generateBoard();
            board.drawBoard();
            if (board.gameOver()) {
                state = GameState::End;
            }
        } else if (state == GameState::End) {
            // show winner and options to restart or quit
            std::string winnerText = (board.getWinnerColor() == Piece::Color::White) ? "White wins!" : "Black wins!";
            DrawText(winnerText.c_str(), 300, 300, 40, BLACK);

            // draw buttons
            DrawRectangleRec(restartBtn, LIGHTGRAY);
            DrawRectangleRec(quitBtn, LIGHTGRAY);
            DrawText("Restart", (int)restartBtn.x + 20, (int)restartBtn.y + 8, 20, BLACK);
            DrawText("Quit", (int)quitBtn.x + 40, (int)quitBtn.y + 8, 20, BLACK);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                Vector2 m = GetMousePosition();
                if (CheckCollisionPointRec(m, restartBtn)) {
                    board = Board();
                    board.setDefaultBoard();
                    state = GameState::Playing;
                }
                if (CheckCollisionPointRec(m, quitBtn)) {
                    CloseWindow();
                    return;
                }
            }
        }

        EndDrawing();
    }
    CloseWindow();
}
