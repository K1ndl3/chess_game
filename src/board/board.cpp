#include "board.hpp"
#define WIN_WIDTH 850
#define WIN_HEIGHT 1000
bool Board::generateBoard()
{
    Color color{127, 106, 79, 255};
    DrawRectangle(_startX, _startY, _board_width, _board_height, color);
    for (int row = 0; row < _num_row; row++) {
        for (int col = 0; col < _num_row; col++) {
            Color squareColor = (col + row) % 2 == 0 ? GRAY : BLACK;
            int squareStartX = col * _cell_size + _startX;
            int squareStartY = row * _cell_size + _startY;
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
    // put the knight on b1, g1, b8, g8  = row(0,0), col(1,6) and row(7,7), col(1,6)
    board_array[FIRST_ROW][1] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::Black);
    board_array[FIRST_ROW][6] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::Black);

    board_array[LAST_ROW][1] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);
    board_array[LAST_ROW][6] = Piece::generatePiece(Piece::Type::Knight, Piece::Color::White);

    // put the rook on a1, a8, h1, h8    = row(0,0), col(1,6), and row(7,7), col(1,6)
    board_array[FIRST_ROW][0] = Piece::generatePiece(Piece::Type::Rook, Piece::Color::Black);
    board_array[FIRST_ROW][7] = Piece::generatePiece(Piece::Type::Rook, Piece::Color::Black);

    board_array[LAST_ROW][0] = Piece::generatePiece(Piece::Type::Rook, Piece::Color::White);
    board_array[LAST_ROW][7] = Piece::generatePiece(Piece::Type::Rook, Piece::Color::White);

    // put the kings on e1, e8           = row(0), col(4) and row(7) col(4)
    board_array[FIRST_ROW][4] = Piece::generatePiece(Piece::Type::King, Piece::Color::Black);

    board_array[LAST_ROW][4] = Piece::generatePiece(Piece::Type::King, Piece::Color::White);

    // put the bishops on c1, f1, c8, f8 = row(0,0), col(2,5) and row(7,7), col(2,5)
    board_array[FIRST_ROW][2] = Piece::generatePiece(Piece::Type::Bishop, Piece::Color::Black);
    board_array[FIRST_ROW][5] = Piece::generatePiece(Piece::Type::Bishop, Piece::Color::Black);

    board_array[LAST_ROW][2] = Piece::generatePiece(Piece::Type::Bishop, Piece::Color::White);
    board_array[LAST_ROW][5] = Piece::generatePiece(Piece::Type::Bishop, Piece::Color::White);

    // put the queens on d1, d8 = row(0,7), col(3,3)
    board_array[FIRST_ROW][3] = Piece::generatePiece(Piece::Type::Queen, Piece::Color::Black);

    board_array[LAST_ROW][3] = Piece::generatePiece(Piece::Type::Queen, Piece::Color::White);

    for (int row = 0; row < _num_row; row++) {
        for (int col = 0; col < _num_row; col++) {
            auto& currPiece = board_array[row][col];
            if (currPiece) {
                currPiece->initTexture();
            }
        }
    }
}

void Board::drawBoard()
{
    for (int row = 0; row < _num_row; row++) {
        for (int col = 0; col < _num_row; col++) {
            if (board_array[row][col] == nullptr) {
                continue;
            }
            const auto& currPieceText = board_array[row][col]->getTexture();
            float textHeight = currPieceText.height;
            float textWidth = currPieceText.width;

            Rectangle sourceRect{0,0,textWidth, textHeight};
            // location of where the piece should sit
            // take the row and col and resize to fill the whole rect
            // the final size should be about 100x100
            Rectangle destRect {col*_cell_size + _startX + 11, row *_cell_size + _startY + 16, 80, 80};
            Vector2 origin_vec{0,0};
            float rotation = 0;  
            DrawTexturePro(currPieceText, sourceRect, destRect, origin_vec, rotation, WHITE);
            // refactor this so that we load the textures on the setDefaultBoard function once and then draw in the draw function
        }
    }
}

void Board::movePiece(int moveCount)
{
    // simple wrapper: process user input (two clicks) to drive moves
    userInput();
}


Vector2 Board::selectSquare()
{
    Vector2 squareLocation{-1, -1}; // default invalid

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();
        int xPos = mousePos.x;
        int yPos = mousePos.y;

        if (xPos >= _startX && xPos < _startX + _board_width &&
            yPos >= _startY && yPos < _startY + _board_height) {

            int col = (xPos - _startX) / _cell_size;
            int row = (yPos - _startY) / _cell_size;

            squareLocation.x = col;
            squareLocation.y = row;

            // highlight the square
            DrawRectangle(_startX + col * _cell_size, _startY + row * _cell_size,
                          _cell_size, _cell_size, YELLOW);
            std::cout << "Selected square: " << col << ", " << row << "\n";
        }
    }

    return squareLocation;
}

bool Board::userInput()
{
    Vector2 clicked = selectSquare();
    if (clicked.x < 0) return false; // go back to this line later and check what happens if we dont include it
    if (_firstClick.x < 0) {
        if (board_array[(int)clicked.y][(int)clicked.x]) {
            _firstClick = clicked;
        }
        return false;
    }

    movePieceFromTo(_firstClick, clicked);
    _firstClick = {-1,-1};
    return true;
}

void Board::movePieceFromTo(Vector2 startPos, Vector2 endPos)
{
    // we are to use the std::move function to move the startpos to endpos
    // since the userInput function handles validation, we dont need to validate
    // take the piece at startpos and move to endpos
    // deconstruct the startpos and endpos Vector2
    int startCol = startPos.x;
    int startRow = startPos.y;

    int endCol = endPos.x;
    int endRow = endPos.y;

    auto& currPiece = board_array[startRow][startCol];
    
    auto& nextPiecePos = board_array[endRow][endCol];
    nextPiecePos = nullptr;

    nextPiecePos = std::move(currPiece);
}
