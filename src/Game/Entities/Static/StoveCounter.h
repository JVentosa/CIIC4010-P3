 //
// Created by joshu on 11/3/2020.
//

#ifndef APGAMEENGINE_STOVECOUNTER_H
#define APGAMEENGINE_STOVECOUNTER_H
#include "Item.h"
#include "BaseCounter.h"

class StoveCounter: public BaseCounter{

 private:
        Item *item;
        int counter;
        bool cook = false;
        bool startcountng = false;
    public:
        StoveCounter(int x, int y, int width, int height, Item *item, ofImage sprite);
        virtual Item *getItem();
        void tick();
        virtual void showItem();
        bool isCooked();
};
#endif //APGAMEENGINE_BASECOUNTER_H