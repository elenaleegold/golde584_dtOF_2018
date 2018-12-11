#pragma once

#include "ofMain.h"

class Cow : public ofBaseApp {

public:

	Cow();
	Cow(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc, float _radius);
	Cow(glm::vec2 _pos, glm::vec2 vel, glm::vec2 acc);
	Cow(glm::vec2 _pos, glm::vec2 vel, glm::vec2 acc, float radius, string s);
	glm::vec2 pos, vel, acc;
	float radius;
	void update();
	void draw();
	int dirX, dirY;
	float lerp;
	bool isCaught;

	void setPos(glm::vec2 p);
	ofImage cow;

	int deg;
	int rad;
	void setVelocity(glm::vec2 velocity);
	void addForce(glm::vec2 force);

	void setImage(string s);

	ofImage gif[4];
	string dir;

	bool isEaten();

	void setEaten(bool status);


};