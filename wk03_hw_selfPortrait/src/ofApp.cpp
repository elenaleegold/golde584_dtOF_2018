#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	colors[0] = ofColor(167, 219, 249);
	colors[1] = ofColor(242, 65, 82);
	colors[2] = ofColor(231, 116, 196);
	colors[3] = ofColor(48, 48, 48);

	for (int i = 0; i < 30; i++) {

		squares[i].setup(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()), ofRandom(20, 100),(int)ofRandom(3));
		float area = squares[i].w * squares[i].w;

		int dir = 1; 
		if (ofRandom(1) < 0.5) {
			dir *= -1;
		}


		float speed = ofMap(area, (50 * 50), (20 * 20), 2, 10);
		squares[i].vel.x = speed * dir;
		squares[i].vel.y = speed * dir;

		//float hue = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
		squares[i].color = ofColor(ofRandom(5));
		squares[i].acc.x = 0.01;
		squares[i].acc.y = 0;
	}



}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < 30; i++) {
		float time = ofGetElapsedTimef();
		//squares[i].acc.x = time * 0.1;
		//cout << "acc is " << time * 0.1 << endl;
		squares[i].update();
	}
	ofSetFrameRate(60);
	ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < 30; i++) {
		int hue = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, ofRandom(4));
		float alpha = ofMap(ofGetMouseY(), 0, ofGetHeight(), 100, 255);
		squares[i].color = ofColor(colors[hue], alpha);
		squares[i].draw();
	}

	ofDrawBitmapStringHighlight("Move cursor to the left to clear, move the cursor to the right to add a new color!", (ofGetWidth() * 0.5) - 350, 100);
	ofDrawBitmapStringHighlight("Move your cursor down to increase the alpha, up to reduce it.", (ofGetWidth() * 0.5) - 275, 125);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '+') {
		for (int i = 0; i < 30; i++) {
			squares[i].w++;
		}
	}
	else if (key == '-') {
		for (int i = 0; i < 30; i++) {
			squares[i].w--;
		}
	}
	else if (key == 'r') {
		for (int i = 0; i < 30; i++) {
			squares[i].pos.x++;
		}
	}
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
