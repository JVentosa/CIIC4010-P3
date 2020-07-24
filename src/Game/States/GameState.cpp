#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	entityManager = new EntityManager();
	ofImage blockImage, basePlayerImage;
	blockImage.load("test.png");
	basePlayerImage.load("basic_player_transparent.png");
	Entity *block = new Entity(ofGetWidth()/2, ofGetHeight()/2, 64, 64, blockImage);
	entityManager->entities.push_back(*block);
	player = new Player(ofGetWidth()/2, ofGetHeight()/2, 64, 64, basePlayerImage);

}
void GameState::tick() {
	player->tick();
	entityManager->tick();
}
void GameState::render() {
	ofSetBackgroundColor(69, 123, 157);
	player->render();
	entityManager->render();
}

void GameState::keyPressed(int key){
	player->keyPressed(key);
	if(key == 'm'){
        setFinished(true);
        setNextState("Menu");
    }
}

void GameState::mousePressed(int x, int y, int button){
	player->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	player->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}