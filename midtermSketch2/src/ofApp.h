#pragma once

#include "ofMain.h"
#include "Spaghetti.h"
#include "Meatball.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void startScreen();

	int dirX, dirY;

	glm::vec2(startPos);
	Spaghetti sp;
	vector <Spaghetti> spArr;
	std::array<Meatball, 10> stArr;

	vector <ofColor> colors;

	ofImage fork;
	bool keyPress, activateStick, start, tutorialOn, fishPress, squishSound;
	int y, score, meatballCount, squishCount; 

	ofSoundPlayer amore, squish;

	ofTrueTypeFont myFont, myBigFont;

	Meatball m;

};
