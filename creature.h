#ifndef CREATURE_H
// #define CREATURE_H
#include <string>
#include <vector>
#include <memory>
#include "Point.h"
#include "Item.h"

using namespace std;
// Абстрактный класс для всех живых существ в игре
class Creature {
protected:
    string name;
    int hp;
    int maxHp;
    int damage;
    Point position;

public:
    // Конструктор базового класса
    Creature(string name, int hp, int damage, Point pos)
        : name(name), hp(hp), maxHp(hp), damage(damage), position(pos) {}

    virtual ~Creature() = default;

    // Геттеры и сеттеры
    Point getPosition() const { return position; }
    void setPosition(Point pos) { position = pos; }
    string getName() const { return name; }
    int getHp() const { return hp; }
    int getMaxHp() const { return maxHp; }
    int getDamage() const { return damage; }
    
    // Проверка, жива ли сущность
    bool isAlive() const { return hp > 0; }

    // Получение урона (с ограничением нижней границы нуля)
    void takeDamage(int amount) {
        hp -= amount;
        if (hp < 0) {
            hp = 0;
        }
    }

    // Виртуальный метод атаки
    virtual void attack(Creature& target);

    // Чисто виртуальный метод для логики хода
    virtual void takeTurn() = 0;
};

// Класс Игрока
class Player : public Creature {
private:
    int gold;
    int exp;
    
    // Инвентарь на умных указателях
    vector<shared_ptr<Item>> inventory;
    
    // Ячейки под текущую экипировку
    shared_ptr<Weapon> equippedWeapon;
    shared_ptr<Armor> equippedArmor;

public:
    // Конструктор игрока
    Player(Point pos) : Creature("Герой", 100, 10, pos), gold(0), exp(0), equippedWeapon(nullptr), equippedArmor(nullptr) {}
    
    // Методы изменения ресурсов персонажа
    void addGold(int amount) { gold += amount; }
    void addExp(int amount) { exp += amount; }
    
    int getGold() const { return gold; }
    int getExp() const { return exp; }

    // Добавление предмета в вектор рюкзака
    void addToInventory(shared_ptr<Item> item) { inventory.push_back(item); }

    void showInventory() const;
    void useItem(int index); 
    
    void attack(Creature& target) override;
    void takeTurn() override; // Управляется внешним вводом в Game.cpp
};

// Базовый класс для всех монстров
class Enemy : public Creature {
public:
    // Конструктор монстра
    Enemy(string name, int hp, int damage, Point pos) 
        : Creature(name, hp, damage, pos) {}

    void takeTurn() override;
};

// Конкретный монстр: Гоблин
class Goblin : public Enemy {
public:
    Goblin(Point pos) : Enemy("Гоблин", 30, 6, pos) {}
};

// Конкретный монстр: Дракон (Босс)
class Dragon : public Enemy {
public:
    Dragon(Point pos) : Enemy("Красный Дракон", 200, 25, pos) {}
};

#endif // CREATURE_H