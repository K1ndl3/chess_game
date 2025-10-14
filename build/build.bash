#!/bin/bash

# Compile
g++ ./src/main.cpp ./src/game/game.cpp ./src/board/board.cpp ./src/player/player.cpp ./src/piece/piece.cpp -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Check if compilation succeeded
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

./main
