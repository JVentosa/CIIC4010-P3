//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() {
    return player;
}

void Restaurant::setPlayer(Player *player) {
    this->player = player;
}

Restaurant::Restaurant() {
    floor.load("images/floor.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager); 
    gordonRamsay.load("images/GordonRamsay.png");
    plant.load("images/plant.png");
    tableDec.load("images/table.png");
    hell.load("images/hellkitch.png");
    gordlogo.load("images/gordonlogo.jpg");
    piano.load("images/piano.png");
    gordonRamsay.cropFrom(gordonRamsay, 277, 35, 250, 394);
    tableDec.cropFrom(tableDec, 36, 29, 146, 161);
    plant.cropFrom(plant, 269, 45, 318, 767);

    initItems();
    initCounters();
    initClients();
    generateClient();

}
void Restaurant::initItems(){ // Initializes the items
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));
}
void Restaurant::initClients(){// creates the clients images
    ofImage temp;
    temp.load("images/People/megaman.png");
    people.push_back(temp);
    temp.load("images/People/LONK.png");
    people.push_back(temp);
    temp.load("images/People/Luigi.png");
    people.push_back(temp);
    temp.load("images/People/MAGICMAN.png");
    people.push_back(temp);
    temp.load("images/People/TOAST.png");
    people.push_back(temp);
    temp.load("images/People/FatDinosaur.png");
    people.push_back(temp);
    temp.load("images/People/crash.png");
    people.push_back(temp);
    temp.load("images/People/deadpool.png");
    people.push_back(temp);
    temp.load("images/People/TOASTV2.png");
    people.push_back(temp);
    temp.load("images/GordonRamsay.png");
    people.push_back(temp);
}
void Restaurant::tick() {
    ticks++;
    if(ticks % 400 == 0){
        generateClient();
    }
    player->tick();
    entityManager->tick();

}
int Restaurant::getMoney(){
    return money;
}

void Restaurant::setMoney(int money){
    this->money = money;
}

void Restaurant::generateClient(){
    int ingredientstotal = 3;
    int randomPeople = ofRandom(11);
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);
    for(int i = 0; i < ingredientstotal; i++){
        int random = ofRandom(4);
        switch(random){
            case 0:
                b->addIngredient(burger);
                break;
            case 1:
                b->addIngredient(cheese);
                break;
            case 2:
                b->addIngredient(tomato);
                break;
            case 3:
                b->addIngredient(lettuce);
                break;
        }
       
    }
    b->addIngredient(topBread);
    //   entityManager->addClient(new Client(0, 50, 64, 72, people[ofRandom(9)], b));
    if (randomPeople < 8){
        // inspector would be people[10]
        entityManager->addClient(new Client(0, 50, 64, 72, people[ofRandom(9)], b));
    }
    else
        entityManager->addClient(new Inspector(0, 50, 64, 72, people[9], b));
}
void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    gordonRamsay.draw(400, ofGetHeight()-100, 100,100);
    tableDec.draw(ofGetWidth()/2 - 215, ofGetHeight()/2 - 200, 200, 200);
    //plant.draw(ofGetWidth()-65, ofGetHeight()/2, 85,85);
    hell.draw(400, 0, 150, 150);
    piano.draw(ofGetWidth() - 175, 50, 250, 250);
    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth()/2, 10);
    ofSetColor(256, 256, 256);

}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        money += entityManager->firstClient->serve(player->getBurger());
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    }
}
EntityManager* Restaurant::getem(){
    return this->entityManager;
}
