#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <map>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include "item.h"
using namespace std;

// game project, у нас будет матрица и это типо игровое поле, игрок отображается как "P" и там будут всякие еще стены итд, пользователь будет управлять игроком через консоль вписывая wasd, 
// типо нажал w и "P" поднялся на 1 клетку вверх в матрице итд
// --- Реализация класса Item ---
// TODO: Реализовать базовый конструктор и геттеры

// --- Реализация класса Weapon ---
// TODO: Реализовать конструктор
// TODO: Реализовать printInfo() -> выводить красивую строку, например: "[Меч] Урон: 15, Цена: 50"
// TODO: Реализовать serialize() -> записывать в файл тип предмета, имя, цену и урон

// --- Реализация класса Armor ---
// TODO: Реализовать конструктор
// TODO: Реализовать printInfo() -> выводить строку, например: "[Щит] Защита: 5, Цена: 30"
// TODO: Реализовать serialize()

// --- Реализация класса Potion ---
// TODO: Реализовать constructor
// TODO: Реализовать printInfo() -> выводить строку, например: "[Зелье ХП] Лечение: 20, Цена: 10"
// TODO: Реализовать serialize()

// hw
void Weapon::printInfo() const {
    cout << "[" << name << "] " << "Урон: " << damage << ", Цена: " << value << endl;
}
// TODO: Реализовать serialize() -> записывать в файл тип предмета, имя, цену и урон
void Weapon::serialize(ofstream& out) const{
    if(out.is_open()){
        out << "Weapon" << endl;
        out << name << endl;
        out << value << endl;
        out << damage << endl;
    }
}
void Armor::printInfo() const {
    cout << "[" << name << "] " << "Лечение: " << defense << ", Цена: " << value << endl;
}
void Potion::printInfo() const{
    cout << "[" << name << "] " << "Защита: " << healAmount << ", Цена: " << value << endl;
}