#include "EntityManager.h"

void EntityManager::tick(){
    for(unsigned int i=0; i<entities.size(); i++){
        entities[0]->tick();
    }
    if(firstClient != nullptr){
        firstClient->tick();
    }
    removeLeavingClients();
}

void EntityManager::removeLeavingClients(){
    Client* tempClient = nullptr;
    while(firstClient != nullptr && firstClient->isLeaving){
        angryLclients++;
        tempClient = firstClient->nextClient;
        delete firstClient;
        firstClient = tempClient;
    }
}

void EntityManager::render(){
    for(unsigned int i=0; i<entities.size(); i++){
        entities[i]->render();
    }
    if(firstClient != nullptr){
        firstClient->render();
    }
}

void EntityManager::addEntity(Entity *e){
    entities.push_back(e);
}

void EntityManager::addClient(Client* c){ // si el cliente es el primero, fine, si no 
    if(firstClient == nullptr){             // es el primer cliente, moves position +72;
        firstClient = c;
    }else{
        Client* tempClient = firstClient;
        tempClient->setY(tempClient->getY()+72);
        while(tempClient->nextClient!=nullptr){
            tempClient = tempClient->nextClient;
            tempClient->setY(tempClient->getY()+72);

        }
        tempClient->nextClient = c;
    }
}
void EntityManager::removeAllClients(){
    Client *tempclient = nullptr;
    while(firstClient != nullptr){
        tempclient = firstClient->nextClient;
        delete firstClient;
        firstClient = tempclient;
    }
}

int EntityManager::getAngryLClients(){
    return angryLclients;
}

void EntityManager::setAngryLClients(int angryLclients){
    this->angryLclients = angryLclients;
}

