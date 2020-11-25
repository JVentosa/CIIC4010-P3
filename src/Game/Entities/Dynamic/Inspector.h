#pragma once
#include "Client.h"
#include "Burger.h"

class Inspector: public Client{
    private:
        Burger* burger;
    public:
        Inspector(int, int, int, int, ofImage, Burger*);
        ~Inspector();
    



};