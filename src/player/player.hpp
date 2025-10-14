#pragma once
#include <vector>
class Player {
public:

private:
    char color;
    std::vector<char> taken_pieces;
    float min_max_rating;
    int captured_piece_points;
};