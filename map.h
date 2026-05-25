#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include "Point.h"
#include "Creature.h"

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
    
    char getCell(Point p) const;
    void setCell(Point p, char c);
    
    void draw(const Player& player, const std::vector<std::shared_ptr<Enemy>>& enemies);
};

#endif // MAP_H