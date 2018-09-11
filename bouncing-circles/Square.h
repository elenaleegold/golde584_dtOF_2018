#pragma once
#include "ofMain.h"

class Square {
public:
    void setup(float posX, float posY, float width, float height);
    void update();
    void draw();
    
    // some extra "utility" functions -
    // return the center coordinates
    float getCenterX();
    float getCenterY();

	ofColor color1;
	ofColor color2;
	ofColor color3;
	ofColor color4;

	int randInd1;
	int randInd2;

	vector<ofColor> colors;
    
    float x, y, w, h;
    float dirX, dirY;
    
};

