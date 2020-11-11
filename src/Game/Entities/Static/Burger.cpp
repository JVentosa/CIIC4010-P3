//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    
  quantity++;
    ingredients.push_back(item);
}

void Burger::render(){
    ofSetColor(256,256,256);
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x,y-(counter * 10),width,height); // ESTO ANADE LOS INGREDIENTES AL BURGER?
        counter++;
    }
}

void Burger::clear(){
    ingredients.empty();
}

bool Burger::equals(Burger* b){
    bool equals = false;
    if(this->quantity == b->getQuantity()){
        for (int i = 0; i < this->ingredients.size(); i++) {
            for (int j = 0; j < b->getIngredients().size(); j++) {
                if (this->getIngredients().at(i) == b->getIngredients().at(j)){
                    equals = true;
                    break;
                }
                else
                    equals = false;
            }
        }
    }
    return equals;
}

vector<Item*> Burger::getIngredients(){
    return ingredients;
}
int Burger::getQuantity(){
    return quantity;
}