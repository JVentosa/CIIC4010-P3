#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : BaseCounter(x, y, width, height,item, sprite){
    this->item = item;
    counter = 0;
}

Item* StoveCounter::getItem(){
    return item;
}

void StoveCounter::showItem()
{
    if (cook) {
        if (item != nullptr){
            item->sprite.draw(x + width / 2 - 25, y - 30, 50, 30);
        }
    }
}

void StoveCounter::tick(){
    counter ++;
    if(counter >= 180){
        cook = true;
    }
}
bool StoveCounter::isCooked(){
    return cook;
}