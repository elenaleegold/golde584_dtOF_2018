#pragma once

#include "ofMain.h"
#include "TimeKeep.h"

class Spaghetti : public ofBaseApp {

public:
	Spaghetti();
	Spaghetti(int _xspacing, float _theta, float _amplitude, float _period);
	void draw();
	void update();
	int xspacing; 
	int w, size;

	float theta; 
	float amplitude; 
	float period;  
	float deg;
	float dx;  
	vector <float> yvalues;

	void calcWave();
	void renderWave();
	void setColor(ofColor c);
	void setDeg(float d);
	float getDeg();
	
	void setSize(int s);
	int getSize();
	void setAmplitude(int a);
	int getAmplitude();

	int randNum;





	ofColor cc;
};