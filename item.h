#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <fstream>
using namespace std;
// Абстрактный базовый класс для всех предметов
class Item {
protected:
    string name;
    int value; // Стоимость предмета в золоте

public:
    // Конструктор базового класса
    Item(string name, int value) : name(name), value(value) {}
    
    virtual ~Item() = default;

    // Геттеры для полей
    string getName() const { return name; }
    int getValue() const { return value; }

    // Чисто виртуальная функция для вывода характеристик предмета в консоль
    virtual void printInfo() const = 0;

    // Виртуальная функция для сохранения предмета в файл
    virtual void serialize(ofstream& out) const = 0;
};

// Класс Оружия
class Weapon : public Item {
private:
    int damage;

public:
    // Конструктор: передает параметры базовому классу и инициализирует урон
    Weapon(string name, int value, int damage) 
        : Item(name, value), damage(damage) {}
    
    int getDamage() const { return damage; }
    
    void printInfo() const override;
    void serialize(ofstream& out) const override;
};

// Класс Брони
class Armor : public Item {
private:
    int defense;

public:
    // Конструктор
    Armor(string name, int value, int defense) 
        : Item(name, value), defense(defense) {}
    
    int getDefense() const { return defense; }

    void printInfo() const override;
    void serialize(ofstream& out) const override;
};

// Класс Зелья лечения
class Potion : public Item {
private:
    int healAmount;

public:
    // Конструктор
    Potion(string name, int value, int healAmount) 
        : Item(name, value), healAmount(healAmount) {}
    
    int getHealAmount() const { return healAmount; }

    void printInfo() const override;
    void serialize(ofstream& out) const override;
};

#endif // ITEM_H