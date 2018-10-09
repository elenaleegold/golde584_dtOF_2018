#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	ofSetCircleResolution(100);
    // make a grid of "mover" objects
    
	for (int y=0; y< 200; y+=ofRandom(130,150)){         // space the "movers" 20 pixels apart
		for (int x=0; x< 200; x+=ofRandom(130,150)){
			
            // make Mover with position on grid, random mass
            Mover mover = Mover(glm::vec2(x,y), ofRandom(1,5));
			movers.push_back(mover);	
		}
	}
	sun = Mover(glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5), 30, ofColor(255,255,0));

	glm::vec2 pos = glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);  
	ParticleSystem particleSystem = ParticleSystem(pos);
	particleSystems.push_back(particleSystem);

	glm::vec2 center = glm::vec2(ofGetWidth() *.5, ofGetHeight() * .5);	// center screen

}

//--------------------------------------------------------------
void ofApp::update(){

	sun.pos = glm::vec2(ofGetMouseX(), ofGetMouseY()); 
	
	glm::vec2 mousePos = glm::vec2(sun.pos.x, sun.pos.y);

	float time = ofGetElapsedTimef();
	float sinFrequency = 3;
	float sinTime = sin(time * sinFrequency) * 8;
	float cosFrequency = 3;
	float cosTime = cos(time * cosFrequency) * 8;
	
	for (int i = 0; i < movers.size(); i++) {

		movers[i].pos += glm::vec2(cosTime + ofNoise(time), sinTime);
		glm::vec2 attraction, repulsion;

		glm::vec2 dir = mousePos - movers[i].pos;

		float distance = glm::length(dir);

		if (distance > 0) {         // avoid dividing by 0!

			glm::vec2 normalizedDir = dir / distance;      // normalize to get length to 1

			if (distance < 100) {           // repulsion

				repulsion = -normalizedDir;

			}
			else if (distance < 200) {    // attraction

				attraction = normalizedDir;
			}
		}

		movers[i].applyForce(attraction);
		movers[i].applyForce(repulsion);
		movers[i].applyDampingForce(0.05);
		movers[i].update();
		movers[i].bounceWindowEdges();

		sun.applyForce(attraction);
		//sun.applyForce(repulsion);
		sun.applyDampingForce(0.05);
		sun.bounceWindowEdges();
		sun.update();

		for (int i = 0; i < particleSystems.size(); i++) {
			particleSystems[i].update();
		}

	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	for (int i=0; i<movers.size(); i++){
		movers[i].draw();
	}
	sun.draw();

	for (int i = 0; i<particleSystems.size(); i++) {
		particleSystems[i].draw();
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
	for (int i = 0; i < movers.size(); i++) {
		movers[i].applyForce(glm::vec2(0, 100));
	}
	sun.glowEnl += 1;
	sun.setGlow(sun.glowEnl);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	while (sun.glowEnl > 3.5) {
		sun.glowEnl-=5;
		sun.setGlow(sun.glowEnl);
		cout << "YE" << endl;
	}
	if (sun.glowEnl < 3.5) {
		sun.glowEnl = 3.5;
	}
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
