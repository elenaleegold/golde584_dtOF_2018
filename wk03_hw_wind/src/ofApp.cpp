#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	for (int i = 0; i < 30; i++) {

		squares[i].setup(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()), ofRandom(20, 100));
		float area = squares[i].w * squares[i].w;

		int dir = 1; 
		if (ofRandom(1) < 0.5) {
			dir *= -1;
		}


		float speed = ofMap(area, (50 * 50), (20 * 20), 2, 10);
		squares[i].vel.x = speed * dir;
		squares[i].vel.y = speed * dir;

		//float hue = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
		squares[i].color = ofColor(ofRandom(255));
		squares[i].acc.x = 0.01;
		squares[i].acc.y = 0;
	}



}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < 30; i++) {
		float time = ofGetElapsedTimef();
		squares[i].acc.x = time * 0.1;
		cout << "acc is " << time * 0.1 << endl;
		squares[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < 30; i++) {
		float hue = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, ofRandom(200,255));
		float alpha = ofMap(ofGetMouseY(), 0, ofGetWidth(), 20, 255);
		squares[i].color = ofColor::fromHsb(hue, 255, 255,alpha);
		squares[i].draw();
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
