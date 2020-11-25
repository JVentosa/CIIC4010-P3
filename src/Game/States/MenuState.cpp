#include "MenuState.h"

MenuState::MenuState() {
	startButton = new Button(0, 0, ofGetWidth(), ofGetHeight(), "Click Anywhere to Start");
	// new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start");
	img1.load("images/GordonRamsaySC.jpg");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetColor(256);
	img1.draw(0,0,ofGetWidth(), ofGetHeight());
	ofSetColor(255,0,0);
	ofDrawBitmapString("e-> picks up ingredients ", ofGetWidth() / 2, ofGetHeight() / 2 + 30);
	ofDrawBitmapString("s-> serve clients ", ofGetWidth() / 2, ofGetHeight() / 2 + 45);
	ofDrawBitmapString("u-> undo last ingredient ", ofGetWidth() / 2, ofGetHeight() / 2 + 60);
	ofDrawBitmapString("The inspector is GordonRamsay", ofGetWidth() / 2, ofGetHeight() / 2 + 75);
	startButton->render();
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}