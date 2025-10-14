#pragma once
#include "vector"
#include <iostream>
#include <memory>
#include <utility>
#include "raylib.h"
#include "../player/player.hpp"
#include "../piece/piece.hpp"
class Board{
public:
// implement the rule of 5 
// implement the default constructor
Board() {
    board_array.resize(_num_row);
    for (auto& row : board_array) {
        row.resize(_num_row);
    }
    std::cout << "[BOARD_GENERATED]";
}
bool generateBoard();
/**
 * @brief generate the board and assets in standard chess starting position
 * @details The full function should have all pieces instantiated and displayed on the board
 */

// generate the starting position of the board
void setDefaultBoard();

void drawBoard();
/**
 * @brief display the board
 * @details loop through the board array and draw each pointer by dereferecing and taking attributes
 */

// update board
void updateBoard(Player& player, Vector2 startPos, Vector2 endPos);
/**
 * @brief Change the position of the pieces on the board.
 * @details Select the starting index and end index.
 *          Should have a move validator function for the piece type. 
 */

// select square
Vector2 selectSquare();
/**
 * @brief Returns the square we have selected as a vector.
 * @details Take the current mouse position and return the what square
 *          the mouse is on when left-click.
 */
private:
    int _cell_size = 100;
    int _board_width = 800;
    int _board_height = 800;
    static constexpr int _num_row = 8;
    int _startX = 25;
    int _startY = 100;
    std::vector<std::vector<std::unique_ptr<Piece>>> board_array;
};