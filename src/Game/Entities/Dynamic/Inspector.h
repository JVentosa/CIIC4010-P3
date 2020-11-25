#pragma once
#include "Client.h"
#include "Burger.h"

class Inspector: public Client{
    private:
        Burger* burger;
        int originalPatience;
        int patience=2000;
        int green = 255;
        int blue = 255;
        int angryLCostumers = 0;
    public:
        Inspector(int, int, int, int, ofImage, Burger*);
        ~Inspector();
        void tick();
        void setAngryColor();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;



};