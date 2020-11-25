#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : BaseCounter(x, y, width, height,item, sprite){
    this->item = item;
    counter = 0;
}

Item *StoveCounter::getItem()
{
    if (cook) {
        counter = 0;
        cook = false;
        startcountng = false;
        return item;
    } else{
        startcountng = true;
        return nullptr;
    }
}

void StoveCounter::showItem()
{
    if (cook) {
        ofSetColor(255);
        if (item != nullptr){
            item->sprite.draw(x + width / 2 - 25, y - 30, 50, 30);
        }
    } else {
        ofSetColor(255,127,127);
           item->sprite.draw(x + width / 2 - 25, y - 30, 50, 30);
    }
}

void StoveCounter::tick(){
    if(startcountng){
    counter ++;
    }
    if(counter >= 180){
        cook = true;
    }
}
// bool StoveCounter::isCooked(){
//     return cook;
// }