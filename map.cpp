#include "map.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Map::Map(int w, int h){
    // TODO: Инициализировать переменные width и height, изменить размер вектора grid под размеры карты
    width = w;
    height = h;
    grid.resize(height, vector<char>(width, '.'));
}

void Map::generateProceduralDungeon(){
    // TODO: Заполнить двумерный массив grid символами:
    
    // 1. По краям (когда x == 0, y == 0 и т.д.) поставить стены '#'
    // 2. Внутри заполнить полом '.'
    // 3. Случайно раскидать несколько внутренних стен '#' и несколько сундуков 'C'
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(x == 0 || y == 0 || x == width - 1 || y == height - 1){
                grid[y][x] = '#';
            }
            else{
                grid[y][x] = '.';
            }
        }
    }
    int walls = width * height / 12;
    for(int i = 0; i < walls; i++){
        int x = rand() % (width - 2) + 1;
        int y = rand() % (height - 2) + 1;
        if(!(x == 1 && y == 1)){
            grid[y][x] = '#';
        }
    }
    int chests = 5;
    for(int i = 0; i < chests; i++){
        int x = rand() % (width - 2) + 1;
        int y = rand() % (height - 2) + 1;
        if(grid[y][x] == '.' && !(x == 1 && y == 1)){
            grid[y][x] = 'C';
        }
    }
}

bool Map::isWalkable(Point p) const{
    // TODO: Проверить, находится ли точка внутри границ карты (0 <= x < width) и (0 <= y < height).
    // Проверить, что символ в этой ячейке в grid НЕ равен стенке '#'. Если ходить можно — вернуть true.

    if(p.x < 0 || p.y < 0 || p.x >= width || p.y >= height){
        return false;
    }
    return grid[p.y][p.x] != '#'; 
}

char Map::getCell(Point p) const{
    // TODO: Вернуть символ из grid по координатам точки p
    if(p.x < 0 || p.y < 0 || p.x >= width || p.y >= height){
        return '#';
    }
    return grid[p.y][p.x];
}

void Map::setCell(Point p, char c){
    // TODO: Записать символ c в grid по координатам точки p
    if(p.x < 0 || p.y < 0 || p.x >= width || p.y >= height){
        return;
    }
    grid[p.y][p.x] = c;
}

void Map::draw(const Player& player, const vector<shared_ptr<Enemy>>& enemies){
    // TODO: 1. Очистить консоль (system("cls") или system("clear")).
    // TODO: 2. Создать копию grid, чтобы не портить оригинальную карту.
    // TODO: 3. В копию карты записать символ '@' на позицию игрока.
    // TODO: 4. В копию карты записать символ 'G' или 'D' на позиции живых врагов из вектора.
    // TODO: 5. Двойным циклом вывести эту копию карты в консоль.
    cout << "\033[2J\033[1;1H";
    vector<vector<char>> copyGrid = grid;
    Point playerPosition = player.getPosition();
    int playerX = playerPosition.x;
    int playerY = playerPosition.y;
    if(playerX >= 0 && playerY >= 0 && playerX < width && playerY < height){
        copyGrid[playerY][playerX] = '@';
    }
    for(int i = 0; i < static_cast<int>(enemies.size()); i++){
        if(enemies[i]->isAlive()){
            Point enemyPosition = enemies[i]->getPosition();
            if(enemyPosition.x >= 0 && enemyPosition.y >= 0 && enemyPosition.x < width && enemyPosition.y < height){
                if(enemies[i]->getName() == "Красный Дракон"){
                    copyGrid[enemyPosition.y][enemyPosition.x] = 'D';
                }
                else{
                    copyGrid[enemyPosition.y][enemyPosition.x] = 'G';
                }
            }
        }
    }
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cout << copyGrid[y][x];
        }
        cout << endl;
    }
}
