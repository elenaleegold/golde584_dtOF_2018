#pragma once

#include "ofMain.h"

class Meatball
{
public:
	Meatball();
	Meatball::Meatball(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc, float _radius);
	Meatball(glm::vec2 _pos, glm::vec2 vel, glm::vec2 acc);
	glm::vec2 pos, vel, acc;
	float radius;
	void update();
	void draw();
	int dirX, dirY;

	void setPos(glm::vec2 p);
	ofImage meatball;

	string dir;
	int deg;
	int rad;
	void setVelocity(glm::vec2 velocity);
	void addForce(glm::vec2 force);

	void setImage(string s);

	void startBallDraw();
	void setRad(int r);
	void setDir(int x, int y);

};
