#pragma once
#include "ofMain.h"

class Square {
public:
	void setup(float posX, float posY, float width, float height);
	void update();
	void draw();

	float x;
	float y;
	float width;
	float height;

	float dirX;
	float dirY;

};
