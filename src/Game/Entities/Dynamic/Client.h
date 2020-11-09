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
        ~Client();
        void tick();
        void setAngryColor();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;



};