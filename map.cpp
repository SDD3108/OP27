#include "map.h"
#include <iostream>

Map::Map(int w, int h) {
    // TODO: Инициализировать переменные width и height, изменить размер вектора grid под размеры карты
    width = w;
    height = h;
    grid.resize(height, vector<char>(width, '.'));
}

void Map::generateProceduralDungeon() {
    // TODO: Заполнить двумерный массив grid символами:
    
    // 1. По краям (когда x == 0, y == 0 и т.д.) поставить стены '#'
    // 2. Внутри заполнить полом '.'
    // 3. Случайно раскидать несколько внутренних стен '#' и несколько сундуков 'C'
}

bool Map::isWalkable(Point p) const {
    // TODO: Проверить, находится ли точка внутри границ карты (0 <= x < width) и (0 <= y < height).
    // Проверить, что символ в этой ячейке в grid НЕ равен стенке '#'. Если ходить можно — вернуть true.

    return false; 
}

char Map::getCell(Point p) const {
    // TODO: Вернуть символ из grid по координатам точки p
    return grid[p.y][p.x] == ' ';
}

void Map::setCell(Point p, char c) {
    // TODO: Записать символ c в grid по координатам точки p
    grid[p.y][p.x] = c;
}

void Map::draw(const Player& player, const std::vector<std::shared_ptr<Enemy>>& enemies) {
    // TODO: 1. Очистить консоль (system("cls") или system("clear")).
    // TODO: 2. Создать копию grid, чтобы не портить оригинальную карту.
    // TODO: 3. В копию карты записать символ '@' на позицию игрока.
    // TODO: 4. В копию карты записать символ 'G' или 'D' на позиции живых врагов из вектора.
    // TODO: 5. Двойным циклом вывести эту копию карты в консоль.
    system("clear");
    vector<vector<char>> copyGrid = grid;
    Point playerPosition = player.getPosition();
    int playerX = playerPosition.x;
    int playerY = playerPosition.y;

}
