#pragma once

#include "ofMain.h"

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

	glm::vec2 p1, p2, p3;
	glm::vec2 p1b, p2b, p3b;
	float count;
	int circY, glowX, flip, glowSize, smokeSize, smokeX, smokeX2, circYB;
	bool smokeAnim;
	ofColor light, glow, glowInner, white;

};