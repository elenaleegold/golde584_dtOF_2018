#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetCircleResolution(100);
	gamePressRhythm = 0.5;
	time = ofGetElapsedTimef();
	count = 0;
	stateCounter = 0;
	lastInterv = 0;
	interval = 8; //fastest interval
	cc = 0;

}

//--------------------------------------------------------------
void ofApp::update() {

	//gamePressRhythm += 0.01;

	gamePressRhythm = ofMap(ofGetElapsedTimef(), 0, 1, 0.5, 0.6, false);



}

//--------------------------------------------------------------
void ofApp::draw() {
	time = ofGetElapsedTimeMillis()/100;

	ofDrawCircle(ofGetWidth()*0.5, ofGetHeight()*0.5, 200);
	timeKeep(time, interval);

	ofSetColor(cc, stateCounter);
	if (stateCounter > 0) {
		stateCounter -= 10;
	}

	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

		lastUserPress = time;
		float userDiff = lastInterv - lastUserPress;

		float error = abs(userDiff);

		if (error != 0 && error != 1) {
			animationPace = 0;
			cc = ofColor(255, 0, 0,100);
			stateCounter = 255;
		}
		else {
			cc = ofColor(0, 255, 0,100);
			stateCounter = 255;
		}

		std::cout << lastInterv << " , " << lastUserPress << endl;


	//}




}

void ofApp::timeKeep(float t, float interv) {
	if (fmod(t,interv) == 0 || count != 255) {
		ofSetColor(255, count);
		ofDrawCircle(ofGetWidth()*0.5, ofGetHeight()*0.5, 100);
		count-=10;
		if (count < 0) {
			count = 255;
			cc = 0;
		}	
		lastInterv = t;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
