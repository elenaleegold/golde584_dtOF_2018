#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);

	float meshWidth = 500;
	float meshHeight = 500;
	float  meshDepth = 500;
	int rows = 50;
	int cols = 50;
	int depth = 50;

	ofSetSmoothLighting(true);

	material.setShininess(120);
	material.setSpecularColor(ofColor(255, 255, 255, 255));
	pointLight.setPosition(ofGetWidth() / 2, ofGetHeight(), 500);
	noise = 200;
	noiseAmp = 10;
	noiseScale = glm::vec2(5, 5);
	for (int r = 0; r < 80; r++) {
		for (int c = 0; c < 80; c++) {
				glm::vec3 p;
				p.x = ofMap(r, 0, rows - 1, meshWidth * -0.5 - ofRandom(100), meshWidth * 0.5 + ofRandom(100));
				p.y = ofMap(c, 0, cols - 1, meshHeight * 0.5 + ofRandom(100), meshHeight * -0.5 - ofRandom(100));
				p.z = 6;
				mesh.addColor(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
				mesh.addVertex(p);


				if (c < cols - 1 && r < rows - 1) {
					int index = r * cols + c;

					mesh.addIndex(index);
					mesh.addIndex(index + 1);
					mesh.addIndex(index + cols);

					mesh.addIndex(index + 1);
					mesh.addIndex(index + 1 + cols);
					mesh.addIndex(index + cols);
				}
		}
	}


}
	


//--------------------------------------------------------------
void ofApp::update(){
	int ind = ofMap(mouseX, 0, ofGetWidth(), 0, mesh.getVertices().size());
		glm::vec3& vertex = mesh.getVertices()[ind];
		float noise = ofSignedNoise(vertex.x * noiseScale.x, vertex.y * noiseScale.y, ofGetElapsedTimef() * 50);
		vertex.z = noise * noiseAmp ++;


}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();
	ofEnableLighting();
	pointLight.enable();
	pointLight.setSpotConcentration(mouseX*10);
	mesh.draw();

	cam.end();


	



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
