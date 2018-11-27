#pragma once

#include "ofMain.h"

class Character : public ofBaseApp
{
public:
	Character();
	Character(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc);
	glm::vec2 pos, vel, acc;

	void update();
	void draw();

	void onGround(int loc);
	bool higherGround(int loc, int locWidth, int nextLoc);

	bool offScreen();

	void setVelocity(glm::vec2 velocity);

	void addForce(glm::vec2 force);

	void jump();

	void checkPos();
	void setToStart(int loc);

	int getSeq(int numBlock);

	glm::vec2 gravity;
	bool isGrounded;
	int radius;


	int windowWidth = 2736;
	int windowHeight = 1824;

};