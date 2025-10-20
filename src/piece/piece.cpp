#include "piece.hpp"
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
