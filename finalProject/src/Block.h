#pragma once

#include "ofMain.h"

class Block : public ofBaseApp {

public:
	Block();
	Block(glm::vec2 pos, int _width, int _height);
	void draw();
	void update();

	glm::vec2 pos; 
	int width;
	int height;

	int getWidth();
	int getHeight();
	glm::vec2 getPos();

	ofColor c;

	void setColor(int a, int b, int q, int d);

	int getX();
	int getY();

};