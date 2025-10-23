#include "piece.hpp"
#include "board.hpp"
#include <memory>

std::unique_ptr<Piece> Piece::generatePiece(Piece::Type t, Piece::Color c)
{

    return std::make_unique<Piece>(t, c);
}

void Piece::generatePossibleMoves(Vector2 mousePos, Piece currPiece) {
    
}


void Piece::initTexture()
{
    const char* path = getAssetPath(getType(), getColor());
    if (path && path[0] != '\0') {
        _texture = LoadTexture(path);
    }
    
}

bool Piece::validateMove(Vector2 endingPos, int moveCount, const Board& board)
{
    auto currPieceType = this->getType();
    auto currPieceColor = this->getColor();
    int endingPosRow = endingPos.x;
    int endingPosCol = endingPos.y;
    const auto& checkingPiece = board.at(endingPosRow, endingPosCol);
    // check if the right color can make the right move
    if (currPieceColor == Piece::Color::Black && moveCount % 2 != 0) return false;
    if (currPieceColor == Piece::Color::White && moveCount % 2 != 1) return false;
    switch (currPieceType)
    {
        case Piece::Type::King :
        if (currPieceColor == Piece::Color::Black) {
             
        }
        break;
    case Piece::Type::Queen :
        break;
    case Piece::Type::Pawn :
        break;
    case Piece::Type::Bishop :
        break;
    case Piece::Type::Rook :
        break;
    case Piece::Type::Knight : 
        break;

    default:
        break;
    }
    return false;
}

