#include "TimeKeep.h"


TimeKeep::TimeKeep()
{
	curTime = 0;
	userTime = 0;
	interv = 1000;
	intervTime = 500;

}


void TimeKeep::update() {
	curTime = ofGetElapsedTimeMillis();
}

void TimeKeep::draw() {
	ofSetCircleResolution(100);
	if (curTime > intervTime && curTime < intervTime + 500) {
		ofDrawCircle(ofGetWidth()*0.5, 100, 100);
		isOn = true;
	}
	else if (curTime > intervTime){
		intervTime += ofRandom(500,10000);
		isOn = false;
	}
}


void TimeKeep::setTimeInterv() {}

void TimeKeep::stall() {}

int TimeKeep::getCurTime() {
	return intervTime;
}

float TimeKeep::getInterv() {
	return interv;
}

bool TimeKeep::isItOn() {
	return isOn;
}
