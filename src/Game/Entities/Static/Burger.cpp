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
    stackIngredients.push(item);
}

void Burger::removeIngredient(Item *item){

    if(stackIngredients.size() > 0){
        if(quantity>0){
            quantity--;
            stackIngredients.pop();
        }
    }
}

void Burger::render(){
    ofSetColor(256,256,256);
    int counter = 1;

    stack<Item*> tempstack;
    while(!stackIngredients.empty()){
        tempstack.push(stackIngredients.top());
        stackIngredients.pop();
    }
    while (!tempstack.empty())
    {
        tempstack.top()->sprite.draw(x, y - (counter * 10), width, height);
        stackIngredients.push(tempstack.top());
        tempstack.pop();
        counter++;
    }
}

void Burger::clear(){
    while(!stackIngredients.empty()){
        stackIngredients.pop();
    }
}

bool Burger::equals(Burger* b){
    bool found = false;
    stack<Item*> temp;
    stack<Item*> thisCopy = this->stackIngredients;
    stack<Item*> bcopy = b->stackIngredients;
if(this->stackIngredients.size() == b->stackIngredients.size()){
   int thisSize = thisCopy.size();
   for(int i = 0; i < thisSize; i++){
       found = false;
       Item* it = thisCopy.top();
       thisCopy.pop();
       int bsize = bcopy.size();
       for (int j = 0; j < bsize; j++){ 
           Item* it2 = bcopy.top();
           bcopy.pop();
           if (it->name.compare(it2->name) == 0){
               found = true;
               break;
           } else{
               temp.push(it2);
           }
       }
       if(!found){
           return false;
       }
       int tempsize = temp.size();
       for(int j = 0; j<tempsize;j++){
           bcopy.push(temp.top());
           temp.pop();
       }
   }
   return true;
}
else
    return false;
}

stack<Item*> Burger::getIngredients(){
    return stackIngredients;
}
int Burger::getQuantity(){
    return quantity;
}
