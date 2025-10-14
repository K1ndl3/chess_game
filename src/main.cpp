#include <iostream>
#include "raylib.h"
#include "./game/game.hpp"
#define WIN_HEIGHT 1000
#define WIN_WIDTH 850

int main() {
	InitWindow(WIN_WIDTH,WIN_HEIGHT,"chess");
	SetTargetFPS(30);
	Game game1;
	game1.run();

	return 0;
}

