#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include <stdlib.h>
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
    // TODO: Написать конструктор
    Creature(string n,int h,int d,Point p):name(n),hp(h),damage(d),position(p){};
    virtual ~Creature() = default;

    // TODO: Написать геттеры и сеттеры (getPosition, setPosition, getName, getHp)
    Point getPosition(){
        return position;
    };
    void setPosition(Point newPosition){
        position = newPosition;
    };
    string getName(){
        return name;
    };
    int getHp(){
        return hp;
    };

    // TODO: Написать метод bool isAlive() (возвращает true, если hp > 0)
    bool isAlive(){
        return hp > 0;
    }
    // TODO: Написать метод void takeDamage(int amount) (уменьшает hp на amount, не уходя в минус)
    void takeDamage(int amount){
        hp -= amount;
        if(hp < 0){
            hp = 0;
        }
    }

    // Виртуальный метод атаки. Переопределяется у игрока для учета оружия
    virtual void attack(Creature& target);
    // virtual void attack(Creature& target){
    //     target.takeDamage(damage);
    // }

    // Чисто виртуальный метод для логики хода (ИИ врагов или пустая заглушка у игрока)
    virtual void takeTurn() = 0;
};

// Класс Игрока
class Player : public Creature {
private:
    int gold;
    int exp;
    
    // Инвентарь на умных указателях
    vector<shared_ptr<Item>> inventory;
    
    // Ячейки под текущую экипировку (изначально nullptr)
    shared_ptr<Weapon> equippedWeapon;
    shared_ptr<Armor> equippedArmor;

public:
    // TODO: Написать конструктор (задать начальное ХП, урон, позицию, обнулить золото и опыт)
    Player(Point p):Creature("Player",100,0,p),gold(0),exp(0),equippedWeapon(nullptr),equippedArmor(nullptr){
        gold = 0;
        exp = 0;
    };

    // TODO: Написать методы addGold(int), addExp(int)
    void addGold(int number){
        gold += number;
    };
    void addExp(int number){
        exp += number;
    }
    // TODO: Написать метод addToInventory(shared_ptr<Item>)
    void addToInventory(shared_ptr<Item> item){
        inventory.push_back(item);
    };

    void showInventory() const;
    void useItem(int index); 
    
    // void attack(Creature& target) override;
    void attack(Creature& target) override{
        int totalDamage = damage;
        if(equippedWeapon){
            totalDamage += equippedWeapon->getDamage();
        }
        target.takeDamage(totalDamage);
    }
    void takeTurn() override; // Можно оставить пустым, так как игрок ходит через Game
};

// Базовый класс для всех монстров
class Enemy : public Creature {
public:
    // TODO: Написать конструктор
    Enemy(string n,int h,int d,Point p):Creature(n,h,d,p){};
    void takeTurn() override;
};

// Конкретный монстр: Гоблин
class Goblin : public Enemy {
public:
    // TODO: Написать конструктор (задать дефолтные ХП и урон для Гоблина)
    Goblin(string n, int h = 100,int d = 40,Point p):Enemy("goblin",30,5,p){};
    // Разрешено переопределить attack() для уникальных критических ударов гоблина
    void attack(Creature& target) override;
    // void attack(Creature& target) override{
    //     int totalDamage = damage;
    //     if(rand() % 100 < 20){
    //         totalDamage *= 2;
    //     }
    //     target.takeDamage(totalDamage);
    // }
};

// Конкретный монстр: Дракон (Босс)
class Dragon : public Enemy {
    private:
        int cooldown;
    public:

        // TODO: Написать конструктор
        Dragon(Point p):Enemy("dragon",100,15,p),cooldown(0){};
        // Разрешено добавить механику супер-удара (например, дыхание огнем раз в 3 хода)
        void attack(Creature& target) override;
        // void attack(Creature& target) override{
        //     static int turnCounter = 0;
        //     turnCounter++;
        //     int totalDamage = damage;
        //     if(turnCounter % 3 == 0){
        //         totalDamage += 20;
        //     }
        //     target.takeDamage(totalDamage);
        // };
};

#endif // CREATURE_H