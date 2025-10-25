#pragma once
#include "vector"
#include <iostream>
#include <memory>
#include <utility>
#include <cmath>
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

inline void setMoveCount() { _move_count++; };

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
void movePiece(int moveCount);
/**
 * @brief Change the position of the pieces on the board.
 * @details Select the end index.
 * TODO: Should have a move validator function for the piece type. 
 */

// select square
Vector2 selectSquare();
/**
 * @brief Returns the square we have selected as a vector.
 * @details Take the current mouse position and return the what square
 *          the mouse is on when left-click.
 * @returns a vector of the selected move in cols and rows
 */

bool userInput();
    // move a piece from start to end (column=x, row=y in Vector2)
    void movePieceFromTo(Vector2 startPos, Vector2 endPos);
/**
 * @brief Take the desired user move and decide if that move is legal
 * @details if th move is legal, then move the piece 
 */

bool validateMove(Vector2 startingPos, Vector2 endingPos, int moveCount);
/**
 * @brief 
 *  decide if a piece can move from startingPos to endingPos or not
 * @details 
 *  deconstruct the current piece at startingPos
 *  deconstruct the ending pos to check for nullprt
 */

void highlightSelectedSquare(Vector2 firstClick, int alphaLvl);

inline Piece* at(int row, int col) {
    if (row < 0 || row >= _num_row || col < 0 || col >= _num_row) return nullptr;
    return board_array[row][col] ? board_array[row][col].get() : nullptr;
}
inline const Piece* at(int row, int col) const {
    if (row < 0 || row >= _num_row || col < 0 || col >= _num_row) return nullptr;
    return board_array[row][col] ? board_array[row][col].get() : nullptr;
}

inline const std::vector<std::vector<std::unique_ptr<Piece>>>& getBoard() const {
    return board_array;
}

private:
    int _cell_size = 100;
    int _board_width = 800;
    int _board_height = 800;
    static constexpr int _num_row = 8;
    int _startX = 25;
    int _startY = 100;
    std::vector<std::vector<std::unique_ptr<Piece>>> board_array;
    int _move_count = 0;
    bool _ready = false;
    Vector2 _firstClick {-1,-1};
    Vector2 _secondClick {-1,-1};
};