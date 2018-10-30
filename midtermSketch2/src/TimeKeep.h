#pragma once

#include "ofMain.h"

class TimeKeep
{
public:
	TimeKeep();
	void setTimeInterv();
	void draw();
	void update();
	void stall();
	int getCurTime();
	float getInterv();
	bool isItOn();
	void keyReleased(int key);

	float curTime;
	float timeInterv;
	float userTime;
	float interv;
	float intervTime;

	bool isOn;

	vector <int> stdTimes;

	ofImage fork;





};

