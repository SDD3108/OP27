#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>
#include <memory>
#include "creature.h"
#include "item.h"
using namespace std;

Game::Game() : map(30, 15), player({1, 1}), running(true){
    map.generateProceduralDungeon();
    player.addToInventory(make_shared<Potion>("Small potion", 10, 25));
    player.addToInventory(make_shared<Weapon>("Sword", 50, 10));
    enemies.push_back(make_shared<Goblin>(getRandomFreePoint()));
    enemies.push_back(make_shared<Goblin>(getRandomFreePoint()));
    enemies.push_back(make_shared<Goblin>(getRandomFreePoint()));
    enemies.push_back(make_shared<Dragon>(getRandomFreePoint()));
}

void Game::run(){
    while(running && player.isAlive()){
        map.draw(player, enemies);
        showStats();
        if(enemies.empty()){
            cout << "You win" << endl;
            break;
        }
        cout << "w/a/s/d move, i inventory, u use item, q quit" << endl;
        char input;
        cin >> input;
        processInput(input);
        removeDeadEnemies();
        if(running && player.isAlive()){
            updateEnemies();
            removeDeadEnemies();
        }
    }
    if(!player.isAlive()){
        cout << "Game over" << endl;
    }
}

void Game::processInput(char input){
    if(input == 'w'){
        movePlayer(0, -1);
    }
    else if(input == 's'){
        movePlayer(0, 1);
    }
    else if(input == 'a'){
        movePlayer(-1, 0);
    }
    else if(input == 'd'){
        movePlayer(1, 0);
    }
    else if(input == 'i'){
        player.showInventory();
        cout << "Press any char" << endl;
        char temp;
        cin >> temp;
    }
    else if(input == 'u'){
        player.showInventory();
        cout << "Index: ";
        int index;
        cin >> index;
        player.useItem(index);
        cout << "Press any char" << endl;
        char temp;
        cin >> temp;
    }
    else if(input == 'q'){
        running = false;
    }
}

void Game::movePlayer(int dx, int dy){
    Point oldPosition = player.getPosition();
    Point newPosition = {oldPosition.x + dx, oldPosition.y + dy};
    if(!map.isWalkable(newPosition)){
        return;
    }
    player.setPosition(newPosition);
    if(map.getCell(newPosition) == 'C'){
        openChest(newPosition);
        map.setCell(newPosition, '.');
    }
    checkPlayerEnemyCollision();
}

void Game::openChest(Point){
    int random = rand() % 3;
    if(random == 0){
        player.addToInventory(make_shared<Potion>("Hp potion", 10, 30));
        cout << "You found potion" << endl;
    }
    else if(random == 1){
        player.addToInventory(make_shared<Weapon>("Axe", 60, 15));
        cout << "You found weapon" << endl;
    }
    else{
        player.addToInventory(make_shared<Armor>("Shield", 40, 5));
        cout << "You found armor" << endl;
    }
}

void Game::checkPlayerEnemyCollision(){
    Point playerPosition = player.getPosition();
    for(int i = 0; i < static_cast<int>(enemies.size()); i++){
        if(enemies[i]->isAlive() && enemies[i]->getPosition() == playerPosition){
            player.attack(*enemies[i]);
            if(enemies[i]->isAlive()){
                enemies[i]->attack(player);
                cout << enemies[i]->getName() << " hp: " << enemies[i]->getHp() << endl;
            }
            else{
                player.addGold(10);
                player.addExp(5);
                cout << enemies[i]->getName() << " defeated" << endl;
            }
            cout << "Press any char" << endl;
            char temp;
            cin >> temp;
        }
    }
}

void Game::updateEnemies(){
    Point playerPosition = player.getPosition();
    for(int i = 0; i < static_cast<int>(enemies.size()); i++){
        if(!enemies[i]->isAlive()){
            continue;
        }
        Point oldPosition = enemies[i]->getPosition();
        enemies[i]->takeTurn();
        Point newPosition = enemies[i]->getPosition();
        if(!map.isWalkable(newPosition)){
            enemies[i]->setPosition(oldPosition);
            continue;
        }
        if(newPosition == playerPosition){
            enemies[i]->attack(player);
            cout << enemies[i]->getName() << " attacked player" << endl;
            enemies[i]->setPosition(oldPosition);
            cout << "Press any char" << endl;
            char temp;
            cin >> temp;
        }
    }
}

void Game::removeDeadEnemies(){
    enemies.erase(remove_if(enemies.begin(), enemies.end(), [](shared_ptr<Enemy> enemy){
        return !enemy->isAlive();
    }), enemies.end());
}

void Game::showStats() const{
    cout << "HP: " << player.getHp() << "/" << player.getMaxHp() << endl;
    cout << "Gold: " << player.getGold() << endl;
    cout << "Exp: " << player.getExp() << endl;
    cout << "Enemies: " << enemies.size() << endl;
}

Point Game::getRandomFreePoint() const{
    Point p;
    do{
        p.x = rand() % (map.getWidth() - 2) + 1;
        p.y = rand() % (map.getHeight() - 2) + 1;
    }while(!map.isWalkable(p) || p == player.getPosition());
    return p;
}
