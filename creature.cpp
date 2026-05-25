#include "creature.h"
#include <iostream>
using namespace std;


// --- Реализация класса Creature ---
// TODO: Написать конструктор, геттеры/сеттеры, isAlive() и takeDamage()
void Creature::attack(Creature& target) {
    // TODO: Базовая логика: нанести базовый damage в target через метод takeDamage
    target.takeDamage(damage);
};

// --- Реализация класса Player ---
// TODO: Написать конструктор и методы изменения золота/опыта/инвентаря

void Player::showInventory() const {
    // TODO: Циклом обойти вектор inventory. Вывести номера 1, 2, 3... и вызвать printInfo() каждого предмета.
    for(int i = 0; i < inventory.size(); i++){
        cout << i + 1 <<", ";
        inventory[i]->printInfo();
    }
    // Если инвентарь пуст — вывести сообщение об этом.
};

void Player::useItem(int index) {
    // TODO: Реализовать использование предмета из вектора по индексу:
    // 1. Если это Potion -> восстановить ХП игроку, удалить зелье из вектора inventory.
    // 2. Если это Weapon -> положить текущее equippedWeapon назад в инвентарь (если оно было),
    //    а новое оружие установить в ячейку equippedWeapon и убрать из вектора.
    // 3. Если это Armor -> аналогично экипировать броню.

    if(index < 1 || index > inventory.size()){
        cout << "Invalid index" << endl;
        return;
    }
};

void Player::attack(Creature& target) {
    // TODO: Рассчитать полный урон = базовый damage + урон от equippedWeapon (если оно есть).
    // Вызвать target.takeDamage с этим полным уроном.


};

void Player::takeTurn() {
    // Оставляем пустым
};

// --- Реализация класса Enemy и его потомков ---
void Enemy::takeTurn() {
    // TODO: Написать простейший ИИ. 
    // Монстр должен случайным образом изменить свою координату position на +1 или -1 по X или Y.
    // *Дополнительно на оценку выше*: сделать движение в сторону координат Игрока.
}