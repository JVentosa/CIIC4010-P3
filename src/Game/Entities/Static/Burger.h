//
// Created by joshu on 11/4/2020.
//

#ifndef APGAMEENGINE_BURGER_H
#define APGAMEENGINE_BURGER_H

#include "Item.h"
#include "stack"
#include "Entity.h"

class Burger
{
private:
    int x, y, width, height;
    // vector<Item *> ingredients;
    int quantity = 0;
    stack<Item *> stackIngredients;
  


public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void removeIngredient(Item *item);
    void render();
    void clear();
    void setY(int y)
    {
        this->y = y;
    }
    // vector<Item*> getIngredients();
    stack<Item*> getIngredients();
    int getQuantity();

    bool equals(Burger *b);
};

#endif //APGAMEENGINE_BURGER_H

