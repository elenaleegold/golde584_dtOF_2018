#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	circY = 100;
	circYB = 80;
	glowX = ofGetWidth();
	flip = 1;
	glow = ofColor::fromHex(0xffffae);
	glowInner = ofColor::fromHex(0xffdd63);
	glowSize = 300;
	white = ofColor(255);
	smokeSize = 10;
	smokeX = ofGetHeight()*0.5;
	smokeX2 = ofGetHeight()*0.5;
	smokeAnim = false;



}

//--------------------------------------------------------------
void ofApp::update(){



}

//--------------------------------------------------------------
void ofApp::draw() {
	float time = ofGetElapsedTimef();
	float rand = ofSignedNoise(time);
	ofEnableSmoothing();
	p1 = glm::vec2(ofGetWidth()*0.5 - 50, ofGetHeight() *0.5);
	p2 = glm::vec2(ofGetWidth()*0.5 + 50, ofGetHeight() *0.5);
	p3 = glm::vec2(ofGetWidth()*0.5, ofGetHeight() *0.5 - 150);

	p1b = glm::vec2(ofGetWidth()*0.5 - 40, ofGetHeight() *0.5);
	p2b = glm::vec2(ofGetWidth()*0.5 + 40, ofGetHeight() *0.5);
	p3b = glm::vec2(ofGetWidth()*0.5, ofGetHeight() *0.5 - 100);

	p3.x += rand * 50;
	p3.y += rand * 30;

	p3b.x += rand * 40;
	p3b.y += rand * 20;

	if (p3.x > 520) {
		circY = ofMap(p3.x, 520, 555, 110, 70);
	}
	else if (p3.x <= 520) {
		circY = ofMap(p3.x, 520, 490, 110, 70);
	}

	if (p3b.x > 500) {
		circYB = ofMap(p3b.x, 500, 520, 80, 70);
	}
	else if (p3b.x <= 500) {
		circYB = ofMap(p3b.x, 500, 490, 80, 70);
	}

	cout << p3b.x << endl;

	//candlebase
	ofPushStyle();
	ofColor candleBase = ofColor::fromHex(0xe5e6ad);
	ofSetColor(candleBase);
	ofDrawRectangle(glm::vec2(p1.x-50, p1.y + 75), (p2.x - p1.x)+100, 300);
	ofPopStyle();

	ofPushStyle();
	ofSetColor(0);
	ofDrawRectangle(ofGetWidth()*0.5 - 5, ofGetHeight()*0.5 + 35, 10, 30);
	ofPopStyle();


	//candle ellipse
	ofPushStyle();
	ofSetColor(255);
	ofDrawEllipse(ofGetWidth()*0.5, ofGetHeight()*0.5 + 75, (p2.x - p1.x)+100, 30);
	ofPopStyle();

	ofPushStyle();
	ofSetColor(0);
	ofDrawRectangle(ofGetWidth()*0.5 - 5, ofGetHeight()*0.5 + 40, 10, 30);
	ofPopStyle();

	//flame
	ofPushStyle();
	ofSetColor(glow);
	ofDrawEllipse(ofGetWidth()*0.5, ofGetHeight()*0.5 + 7, 100, circY);
	ofDrawTriangle(p1, p2, p3);
	ofPopStyle();

	//flame inner
	ofPushStyle();
	ofSetColor(white);
	ofDrawEllipse(ofGetWidth()*0.5, ofGetHeight()*0.5 + 7, 80, circYB);
	ofDrawTriangle(p1b, p2b, p3b);
	ofPopStyle();

	//flame bottom
	ofPushStyle();
	ofSetColor(glowInner,200);
	ofDrawEllipse(ofGetWidth()*0.5, ofGetHeight()*0.5 + 17, 80, circYB);
	//ofDrawTriangle(p1b, p2b, p3b);
	ofPopStyle();

	//flame bottom
	ofPushStyle();
	ofSetColor(0,25);
	ofDrawEllipse(ofGetWidth()*0.5, ofGetHeight()*0.5 + 30, 60, circYB);
	//ofDrawTriangle(p1b, p2b, p3b);
	ofPopStyle();

	//dim
	ofPushStyle();
	ofSetColor(0,25);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofPopStyle();

	//glow
	glowX = ofMap(p3.x, 520, 555, 500, 535);
	ofPushStyle();
	ofSetColor(glow, 80);
	ofDrawEllipse(glowX, ofGetHeight()*0.5 - 50, glowSize, glowSize);
	ofPopStyle();

	if (smokeAnim == true) {
		ofSetColor(0,100);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

		ofSetColor(255,50);
		ofDrawEllipse(ofGetWidth()*0.5, smokeX, smokeSize, smokeSize);
		ofDrawEllipse(ofGetWidth()*0.5 - 25 +(smokeX/5), smokeX -20, smokeSize +5, smokeSize + 5);
		ofDrawEllipse(ofGetWidth()*0.5-20, smokeX+10, smokeSize+20, smokeSize+20);

		ofDrawEllipse(ofGetWidth()*0.5, smokeX2, smokeSize, smokeSize);
		ofDrawEllipse(ofGetWidth()*0.5 + 25, smokeX2 - 20, smokeSize + 5, smokeSize + 5);
		ofDrawEllipse(ofGetWidth()*0.5 +5, smokeX2 + 10, smokeSize + 20, smokeSize + 20);


		smokeX2 -= 7;
		smokeX-=5;
		smokeSize+=2;


	}





	



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'd') {
		glow = ofColor(0);
		glowSize = 0;
		glowInner = ofColor(0);
		glowSize = 0;
		white = ofColor(0);
		smokeAnim = true;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
