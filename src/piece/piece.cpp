#include "piece.hpp"
#include <memory>

std::unique_ptr<Piece> Piece::generatePiece(Piece::Type t, Piece::Color c)
{
    return std::make_unique<Piece>(t, c);
}