#pragma once
#include "ofMain.h"

class Square {
public:
	void setup(float posX, float posY, float width);
	void update();
	void draw();

	// some extra "utility" functions -
	// return the center coordinates
	/*float getCenterX();
	float getCenterY();*/
	glm::vec2 getCenter();



	float w;
	glm::vec2 pos; 
	glm::vec2 vel; //glm stands for gl math
	glm::vec2 acc;
	ofColor color;
	float dirX, dirY;

};