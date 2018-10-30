#include "Spaghetti.h"

Spaghetti::Spaghetti() {
	xspacing = 3;   
	w = ofGetWidth();
	theta = 0.0;  
	amplitude = 75.0; 
	period = 500.0;   
	w = ofGetWidth(); +xspacing;
	dx = (TWO_PI / period) * xspacing;
	cc = ofColor(255);
	deg = 0;
	size = 100;
	randNum = ofRandom(50);

}

Spaghetti::Spaghetti(int _xspacing, float _theta, float _amplitude, float _period) {
	xspacing = _xspacing;
	theta = _theta;
	amplitude = _amplitude;
	period = _period;
	w = ofGetWidth() * 2 + xspacing;
	dx = (PI / period) * xspacing ;
	cc = ofColor(255);
	deg = 0;
	size = 100;
	randNum = ofRandom(50);
}

void Spaghetti::update() {

}

void Spaghetti::draw() {
	ofPushStyle();
	calcWave();
	renderWave();
	ofPopStyle();
}

void Spaghetti::calcWave() {
	theta += 0.06;

	for (int i = 0; i < w / xspacing; i++) {
		yvalues.push_back(0);
	}

	float x = theta + randNum;
	for (int i = 0; i < w / xspacing; i++) {
		yvalues[i] = sin(x)*amplitude;
		x += dx;
	}
}

void Spaghetti::renderWave() {
	ofSetColor(cc);
	for (int x = 0; x < w / xspacing; x++) {
		ofDrawCircle(x*xspacing, ofGetHeight()/4 + yvalues[x], size);
	}
}

void Spaghetti::setColor(ofColor c) {
	cc = c;
}

void Spaghetti::setDeg(float d) {
	deg = d;
}

float Spaghetti::getDeg() {
	return deg;
}

void Spaghetti::setAmplitude(int a) {
	amplitude = a;
}

int Spaghetti::getAmplitude() {
	return amplitude;
}

void Spaghetti::setSize(int s) {
	size = s;
}

int Spaghetti::getSize() {
	return size;
}