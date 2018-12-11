#pragma once

#include "ofMain.h"
#include "Cow.h"
class Trail {
public:
	Trail(glm::vec2 _destination);
	Trail(glm::vec2 _destination, glm::vec2 _pos, float _percent);
	float radius;
	ofColor color;
	float lerp, percent;     // amount to interpolate when moving
					// (percentage of distance to target)
	void draw();
	void update();
	
	ofImage hamburger;

	vector <Cow> trail;
	glm::vec2 mouse, destination, pos;

	void add();
	void popAnim();
	void setPercentage(int p);
};
