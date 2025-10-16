#pragma once
#include <memory>
#include <map>
#include <string>
#include <utility>
#include "raylib.h"
class Piece {
    public:

    enum class Type {King, Queen, Rook, Bishop, Knight, Pawn};
    enum class Color {White, Black};

    Piece(Type t, Color c) : _type(t), _color(c) {};
    virtual ~Piece() = default; 

    // this should be the function that will create the pieces with textures
    static std::unique_ptr<Piece> generatePiece(Type t, Color c);

    inline Type getType() const { return _type; };
    inline Color getColor() const { return _color; };
    inline Texture2D getTexture() const { return _texture; };
    inline int getRowPos() const { return _rowPos; };
    inline int getColPos() const { return _colPos; };

    inline void setRowPos(int newRowPos) {
        _rowPos = newRowPos;
    }

    inline void setColPos(int newColPos) {
        _colPos = newColPos;
    }

    const char* getAssetPath(Type t, Color c) {
        std::pair<Type, Color> pieceInfo = {t, c};
        return _assets_path[pieceInfo];
    }

    
    void initTexture();


    private:
    Type _type;
    Color _color;
    Texture2D _texture;
    int _rowPos;
    int _colPos;

    std::map<std::pair<Piece::Type, Piece::Color>, const char*> _assets_path {
        {{Piece::Type::Pawn, Piece::Color::White}, "./assets/white_pawn.png"},
        {{Piece::Type::Pawn, Piece::Color::Black}, "./assets/black_pawn.png"},

        {{Piece::Type::Knight, Piece::Color::White}, "./assets/white_knight.png"},
        {{Piece::Type::Knight, Piece::Color::Black}, "./assets/black_knight.png"},

        {{Piece::Type::Rook, Piece::Color::White}, "./assets/white_rook.png"},
        {{Piece::Type::Rook, Piece::Color::Black}, "./assets/black_rook.png"},

        {{Piece::Type::Bishop, Piece::Color::White}, "./assets/white_bishop.png"},
        {{Piece::Type::Bishop, Piece::Color::Black}, "./assets/black_bishop.png"},

        {{Piece::Type::Queen, Piece::Color::White}, "./assets/white_queen.png"},
        {{Piece::Type::Queen, Piece::Color::Black}, "./assets/black_queen.png"},

        {{Piece::Type::King, Piece::Color::White}, "./assets/white_king.png"},
        {{Piece::Type::King, Piece::Color::Black}, "./assets/black_king.png"},
    };
};