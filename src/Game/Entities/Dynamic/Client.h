#pragma once
#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    private:
        Burger* burger;
        int originalPatience;
        int patience=2000;
        int green = 255;
        int blue = 255;
        int angryLCostumers = 0;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        virtual void tick();
        virtual void setAngryColor();
        virtual void render();
        virtual int serve(Burger*);
        virtual int getPatience();
        Client* nextClient=nullptr;
        bool isLeaving=false;



};