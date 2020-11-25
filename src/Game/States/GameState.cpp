#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {


	if (restaurant->getMoney() == 100){
		restaurant->setMoney(0);
		restaurant->getPlayer()->setX(600);
		restaurant->getem()->removeAllClients();
		restaurant->getem()->setAngryLClients(0);
		setNextState("WinState");
		setFinished(true);
	}
	else if (restaurant->getem()->getAngryLClients() == 10){
		// set angry clients to 0;
		restaurant->setMoney(0);
		restaurant->getem()->setAngryLClients(0);
		restaurant->getPlayer()->setX(600);
		restaurant->getem()->removeAllClients();
		setNextState("Loser");
		setFinished(true);
	}
	restaurant->tick();
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}