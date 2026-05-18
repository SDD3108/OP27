#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Item {
    protected:
        string name;
        int value;
    public:
        Item(string n,int v):name(n),value(v){
            // что такое обстрактный класс? 
        };
        string getName() const {return name;}
        int getValue() const {return value;}
        virtual ~Item() = default;
        virtual void printInfo() const = 0;
        virtual void serialize(ofstream& out) const = 0;
};

class Weapon : public Item{
    private:
        int damage;
    public:
        Weapon(string n,int v,int d):Item(n,v),damage(d){};
        int getDamage() const {return damage;}
        void printInfo() const override;
        void serialize(ofstream& out) const override;
};

class Armor : public Item{
    private:
        int defence;
    public:
        Armor(string n,int v,int d):Item(n,v),defence(d){};
        int getDefence() const {return defence;}
        void printInfo() const override;
        void serialize(ofstream& out) const override;
};

class Potion : public Item{
    private:
        int healAmount;
    public:
        Potion(string n,int v,int h):Item(n,v),healAmount(h){};
        int getHealAmount() const {return healAmount;}
        void printInfo() const override;
        void serialize(ofstream& out) const override;
};

#endif // ITEM_H
