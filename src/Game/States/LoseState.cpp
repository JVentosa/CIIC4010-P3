#include "LoseState.h"

LoseState::LoseState() {
	RestartButton = new Button(0, 0, ofGetWidth(), ofGetHeight(), "Click Anywhere to Restart");
	// new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start");
    Loser.load("images/LoserImage.jpg");

}
void LoseState::tick() {
	RestartButton->tick();
	if(RestartButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}
void LoseState::render() {
	ofSetColor(256);
	Loser.draw(0,0,ofGetWidth(), ofGetHeight());
	RestartButton->render();
}

void LoseState::keyPressed(int key){
	
}

void LoseState::mousePressed(int x, int y, int button){
	RestartButton->mousePressed(x, y);
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
	RestartButton->reset();
}