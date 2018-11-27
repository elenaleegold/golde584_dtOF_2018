#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	main = Character(glm::vec2(200, windowWidth*0.75-100), glm::vec2(0, 8), glm::vec2(0, 0));
	s = Sequence(ofRandom(1, 10));
	stopMotion = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	s.update();
	main.update();
	calcCurBlock();
	if (main.offScreen()) {
		s = Sequence(ofRandom(1, 10));
		main.setToStart(calcCurBlock());
	}
	//if (!(main.higherGround(calcCurBlock(), calcCurWidth(), calcNextBlock()))) {
		main.onGround(calcCurBlock() - main.radius);
	//}
	//else {
	//	stopMotion = true;
	//}

	//main.onGround(s.getBlock(calcCurBlock()).getY());
}

//--------------------------------------------------------------
void ofApp::draw(){
	s.draw();
	main.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_LEFT) {
		main.setVelocity(glm::vec2(-15, 10));
	}

	if (key == OF_KEY_RIGHT && stopMotion == false) {
		main.setVelocity(glm::vec2(15, 10));
	}

	if (key == OF_KEY_UP) {
		main.jump();
	}



}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(main.vel.y > -40){
	main.setVelocity(glm::vec2(0, 0));
	}
}

int ofApp::calcCurBlock() {
	for(int i = 0; i < s.blocks.size(); i++){
		if (main.pos.x > s.getBlock(i).getX() && main.pos.x  < s.getBlock(i).getX() + s.getBlock(i).getWidth()) {
			return s.getBlock(i).getY();
		}
	}
}

int ofApp::calcCurWidth() {
	for (int i = 0; i < s.blocks.size(); i++) {
		if (main.pos.x > s.getBlock(i).getX() && main.pos.x < s.getBlock(i).getX() + s.getBlock(i).getWidth()) {
			return s.getBlock(i).getWidth();
		}
	}
}

int ofApp::calcNextBlock() {
	for (int i = 0; i < s.blocks.size(); i++) {
		if (main.pos.x > s.getBlock(i).getX() && main.pos.x < s.getBlock(i).getX() + s.getBlock(i).getWidth()) {
			if (i+1 > s.blocks.size()) {
				return 0;
			}
			else{
				return s.getBlock(i+1).getY();
			}
		}
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
