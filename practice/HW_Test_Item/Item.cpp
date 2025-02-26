#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
class Item {
protected:
    string name;
    string description;
public:
    virtual void interact(Player& player) = 0;
    virtual ~Item() = default;
};

class Treasure : public Item {
private:
    int weight;
    int value;
public:
    void interact(Player& player) override {
    }
};

class Food : public Item {
private:
    int healthValue;
public:
    void interact(Player& player) override {
    }
};

class Demon : public Item {
private:
    int damageValue;
public:
    void interact(Player& player) override {
    }
};

class Room {
private:
    string description;
    map<string, Room*> exits;
    vector<Item*> items;
public:
    void addItem(Item* item);
    void removeItem(Item* item);
    void look();
};

class Player {
private:
    int health;
    int maxBagWeight;
    vector<Item*> inventory;
public:
    void take(Item* item);
    void drop(Item* item);
    void what();
};
