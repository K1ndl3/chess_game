#include "board.hpp"

bool Board::generateBoard()
{
    Color color{127, 106, 79, 255};
    DrawRectangle(_startX, _startY, _board_width, _board_height, color);
    for (int row = 0; row < _num_row; row++) {
        for (int col = 0; col < _num_row; col++) {
            Color squareColor = (col + row) % 2 == 0 ? GRAY : BLACK;
            int squareStartX = row * _cell_size + _startX;
            int squareStartY = col * _cell_size + _startY;
            DrawRectangle(squareStartX, squareStartY, _cell_size,_cell_size, squareColor);
        }
    }
    return true;

}

void Board::setDefaultBoard()

{
    static constexpr int BLK_PAWN_ROW = 1;
    static constexpr int WHT_PAWN_ROW = 6;
    static constexpr int FIRST_ROW = 0;
    static constexpr int LAST_ROW = 7;
    // put the black pawns on the second rank  = 1st row
    for (int i = 0; i < _num_row; i++) {
        board_array[BLK_PAWN_ROW][i] = Piece::generatePiece(Piece::Type::Pawn, Piece::Color::Black);
    }
    // put the pawns on the seventh rank = 6th row
    for (int i = 0; i < _num_row; i++) {
        board_array[WHT_PAWN_ROW][i] = Piece::generatePiece(Piece::Type::Pawn, Piece::Color::White);
    }
    // put the knight on b1, g1, b8, g8  = row(0,0), col(0,7) and row(7,7), col(0,7)
    board_array[FIRST_ROW][0] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[FIRST_ROW][7] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[LAST_ROW][0] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[LAST_ROW][7] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);

    // put the rook on a1, a8, h1, h8    = row(0,0), col(1,6), and row(7,7), col(1,6)
    board_array[FIRST_ROW][1] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[FIRST_ROW][6] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[LAST_ROW][1] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[LAST_ROW][6] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);

    // put the kings on e1, e8           = row(0), col(4) and row(7) col(4)
    board_array[FIRST_ROW][4] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[LAST_ROW][4] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);

    // put the bishops on c1, f1, c8, f8 = row(0,0), col(2,5) and row(7,7), col(2,5)
    board_array[FIRST_ROW][2] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[FIRST_ROW][5] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[LAST_ROW][2] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[LAST_ROW][5] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);

    // put the queens on d1, d8 = row(0,7), col(3,3)
    board_array[FIRST_ROW][3] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[LAST_ROW][3] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);

}