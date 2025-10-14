#pragma once
class Game {
public:
    // default constructor
    Game();
    // Implement the rule of 5
    // Copy Constructor
    Game(Game& old_game);
    // Copy Assignment Operator
    
    // Move Constructor
    // Move Assignment Operator
    // Destructor

    // game.run() method to drive the game
    void run();
private:
    bool isOver = false;
};