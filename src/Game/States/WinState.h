#pragma once

#include "State.h"
#include "Button.h"

class WinState : public State {
private:
	ofImage YouWin;
	Button *RestartButton;

public:
	WinState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
