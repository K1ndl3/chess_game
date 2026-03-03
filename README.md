# ♟️ Chess Game

A C++ chess game implementation built with [Raylib](https://www.raylib.com/), featuring a fully interactive 8x8 chess board with graphical piece rendering and user input handling.

## 📋 Overview

This project is a graphical chess game written in modern C++ that leverages the Raylib graphics library to render a traditional chess board and pieces. The game includes piece initialization in standard chess starting positions, visual rendering of the board and pieces, and user interaction capabilities for selecting and moving pieces.

## ✨ Features

- **Interactive Chess Board**: 8x8 chess board with alternating square colors (gray and black)
- **Chess Pieces**: All standard chess pieces (King, Queen, Rook, Bishop, Knight, Pawn) with both white and black variants
- **Graphical Rendering**: Textured chess pieces loaded from PNG assets
- **User Input System**: Click-based square selection for piece movement
- **Move Validation**: Framework for validating legal moves based on piece type
- **Piece Highlighting**: Visual feedback when selecting squares
- **Starting Position**: Automatic setup of pieces in standard chess starting positions

## 🏗️ Architecture

The project is organized into several key components:

### Core Classes

- **`Game`** - Main game loop controller
  - Initializes the game window (850x1000)
  - Manages the game loop with 30 FPS target
  - Coordinates board and piece interactions

- **`Board`** - Chess board representation and management
  - 8x8 grid of chess pieces stored as unique pointers
  - Board rendering and visualization
  - Move tracking and validation
  - User input processing for piece selection
  - Piece highlighting for visual feedback

- **`Piece`** - Individual chess piece representation
  - Type: King, Queen, Rook, Bishop, Knight, Pawn
  - Color: White or Black
  - Texture loading from asset files
  - Row and column position tracking
  - Factory method for piece generation with textures

- **`Player`** - Player information tracking (in development)
  - Player color
  - Captured pieces tracking
  - Move rating system

### Key Methods

**Game Loop**:
```cpp
Game::run()
  ├─ Create Board
  ├─ Set Default Board (pieces in starting position)
  └─ Main Loop:
      ├─ Process user input
      ├─ Generate board visuals
      ├─ Draw board and pieces
      └─ Continue until window close
```

**Board Operations**:
- `setDefaultBoard()` - Initialize all pieces in standard starting positions
- `generateBoard()` - Render the chess board grid
- `drawBoard()` - Draw all pieces on the board
- `userInput()` - Handle mouse clicks and piece selection
- `validateMove()` - Check if a move is legal
- `movePieceFromTo()` - Move a piece from one square to another

## 🛠️ Building and Running

### Prerequisites

- C++ compiler (C++17 or later recommended)
- Raylib library installed
- CMake (if using CMake build system)

### Compilation

```bash
# Navigate to the project directory
cd chess_game

# Create a build directory
mkdir build
cd build

# Compile
cmake ..
make

# Run the executable
./main
```

### Alternative: Direct Compilation

```bash
g++ -std=c++17 src/main.cpp src/game/game.cpp src/board/board.cpp src/piece/piece.cpp -o chess_game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./chess_game
```

## 🎮 How to Play

1. **Launch** the game executable
2. **View** the chess board with pieces in their starting positions
3. **Click** on a square to select a piece
4. **Click** on a destination square to move the selected piece
5. **Game Loop**: The board will render and respond to your input continuously

## 🗂️ File Structure

```
chess_game/
├── src/
│   ├── main.cpp              # Entry point, window initialization
│   ├── game/
│   │   ├── game.hpp          # Game class header
│   │   └── game.cpp          # Game class implementation
│   ├── board/
│   │   ├── board.hpp         # Board class header
│   │   └── board.cpp         # Board class implementation
│   ├── piece/
│   │   ├── piece.hpp         # Piece class header
│   │   └── piece.cpp         # Piece class implementation
│   └── player/
│       └── player.hpp        # Player class header
├── assets/                   # Texture images for chess pieces
├── build/                    # Build output directory
└── README.md                 # This file
```

## 📦 Dependencies

- **Raylib** - Graphics and input handling library
  - For installation, visit: https://www.raylib.com/

## 🚀 Future Enhancements

- [ ] Complete move validation for all piece types
- [ ] Implement turn-based player system
- [ ] Add checkmate and stalemate detection
- [ ] Implement castling, en passant, and pawn promotion
- [ ] Add move history and undo functionality
- [ ] AI opponent using minimax algorithm
- [ ] Sound effects and animations
- [ ] Save and load game state
- [ ] Network multiplayer support

## 📝 Notes

- The project demonstrates modern C++ concepts including:
  - Smart pointers (`std::unique_ptr`)
  - Object-oriented design
  - Memory management best practices
  - Enumeration classes
  
- The "Rule of 5" is partially implemented and ready for completion with move semantics

## 📄 License

MIT License

## 👤 Author

Created by K1ndl3

---

**Enjoy playing chess!** ♚♕
