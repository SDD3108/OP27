#include "creature.h"
#include <iostream>
#include <cstdlib>
using namespace std;


// --- Реализация класса Creature ---
// TODO: Написать конструктор, геттеры/сеттеры, isAlive() и takeDamage()
void Creature::attack(Creature& target){
    // TODO: Базовая логика: нанести базовый damage в target через метод takeDamage
    target.takeDamage(damage);
};

// --- Реализация класса Player ---
// TODO: Написать конструктор и методы изменения золота/опыта/инвентаря

void Player::showInventory() const{
    // TODO: Циклом обойти вектор inventory. Вывести номера 1, 2, 3... и вызвать printInfo() каждого предмета.
    if(inventory.empty()){
        cout << "Inventory is empty" << endl;
        return;
    }
    for(int i = 0; i < static_cast<int>(inventory.size()); i++){
        cout << i + 1 << ", ";
        inventory[i]->printInfo();
    }
    // Если инвентарь пуст — вывести сообщение об этом.
};

void Player::useItem(int index){
    // TODO: Реализовать использование предмета из вектора по индексу:
    // 1. Если это Potion -> восстановить ХП игроку, удалить зелье из вектора inventory.
    // 2. Если это Weapon -> положить текущее equippedWeapon назад в инвентарь (если оно было),
    //    а новое оружие установить в ячейку equippedWeapon и убрать из вектора.
    // 3. Если это Armor -> аналогично экипировать броню.

    if(index < 1 || index > static_cast<int>(inventory.size())){
        cout << "Invalid index" << endl;
        return;
    }
    shared_ptr<Item> item = inventory[index - 1];
    shared_ptr<Potion> potion = dynamic_pointer_cast<Potion>(item);
    shared_ptr<Weapon> weapon = dynamic_pointer_cast<Weapon>(item);
    shared_ptr<Armor> armor = dynamic_pointer_cast<Armor>(item);
    if(potion != nullptr){
        hp += potion->getHealAmount();
        if(hp > maxHp){
            hp = maxHp;
        }
        inventory.erase(inventory.begin() + index - 1);
        cout << "Potion used" << endl;
        return;
    }
    if(weapon != nullptr){
        inventory.erase(inventory.begin() + index - 1);
        if(equippedWeapon != nullptr){
            inventory.push_back(equippedWeapon);
        }
        equippedWeapon = weapon;
        cout << "Weapon equipped" << endl;
        return;
    }
    if(armor != nullptr){
        inventory.erase(inventory.begin() + index - 1);
        if(equippedArmor != nullptr){
            inventory.push_back(equippedArmor);
        }
        equippedArmor = armor;
        cout << "Armor equipped" << endl;
        return;
    }
};

void Player::attack(Creature& target){
    // TODO: Рассчитать полный урон = базовый damage + урон от equippedWeapon (если оно есть).
    // Вызвать target.takeDamage с этим полным уроном.

    int fullDamage = damage;
    if(equippedWeapon != nullptr){
        fullDamage += equippedWeapon->getDamage();
    }
    target.takeDamage(fullDamage);
    cout << name << " attacked " << target.getName() << " for " << fullDamage << " damage" << endl;
};

void Player::takeTurn(){
// Оставляем пустым
};

// --- Реализация класса Enemy и его потомков ---
void Enemy::takeTurn(){
    // TODO: Написать простейший ИИ. 
    // Монстр должен случайным образом изменить свою координату position на +1 или -1 по X или Y.
    // *Дополнительно на оценку выше*: сделать движение в сторону координат Игрока.
    int direction = rand() % 4;
    if(direction == 0){
        position.y--;
    }
    else if(direction == 1){
        position.y++;
    }
    else if(direction == 2){
        position.x--;
    }
    else{
        position.x++;
    }
}
