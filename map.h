#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include "point.h"
#include "creature.h"
using namespace std;

class Map {
private:
    int width;
    int height;
    
    // Двумерный массив символов карты ('.' - пол, '#' - стена, 'C' - сундук)
    vector<vector<char>> grid;

public:
    Map(int w, int h);
    
    // TODO: Написать геттеры getWidth и getHeight

    void generateProceduralDungeon();
    bool isWalkable(Point p) const;
    
    int getWidth() const {
        return width;    
    };
    int getHeight() const {
        return height;
    };
    
    char getCell(Point p) const;
    void setCell(Point p, char c);
    
    void draw(const Player& player, const vector<shared_ptr<Enemy>>& enemies);
};

#endif // MAP_H