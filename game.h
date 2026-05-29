#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "map.h"
#include "creature.h"
#include "item.h"
using namespace std;

class Game {
private:
    Map map;
    Player player;
    vector<shared_ptr<Enemy>> enemies;
    bool running;

    void processInput(char input);
    void movePlayer(int dx, int dy);
    void openChest(Point p);
    void checkPlayerEnemyCollision();
    void updateEnemies();
    void removeDeadEnemies();
    void showStats() const;
    Point getRandomFreePoint() const;

public:
    Game();
    void run();
};

#endif
