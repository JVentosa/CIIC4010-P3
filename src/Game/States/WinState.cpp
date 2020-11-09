#include "WinState.h"

WinState::WinState() {
	RestartButton = new Button(0, 0, ofGetWidth(), ofGetHeight(), "Click Anywhere to Restart");
	// new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start");
	YouWin.load("images/youwin.jpg");
	
}
void WinState::tick() {
	RestartButton->tick();
	if(RestartButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}
void WinState::render() {
	ofSetColor(256);
	YouWin.draw(0,0,ofGetWidth(), ofGetHeight());

	RestartButton->render();
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
	RestartButton->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	RestartButton->reset();
}