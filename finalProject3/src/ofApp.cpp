#include "ofApp.h"
#include "Cow.h"
#include "Butcher.h"
#include "Trail.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(51);
	mainChar = Butcher(glm::vec2(mouseX, mouseY), glm::vec2(0, 0), glm::vec2(0, 0), 200);
	trailLine.push_back(Trail(glm::vec2(mouseX, mouseY)));	
	free = false;
	myBigFont.load("8-bit pusab.ttf", 42);
	myBiggerFont.load("8-bit pusab.ttf", 100);
	bg1.load("images/bg1.png");
	bg2.load("images/bg2.png");
	startScreen.load("images/StartScreen.png");
	endScreen.load("images/endScreen.png");
	start = false;
	end = false;
	bg1X = 0;
	bg1Y = 0;
	bg2X = bg1.getWidth() + 1795;
	bg2Y = 0;
	timer = 0;

	//initialize sounds
	track.load("track1.mp3");
	track.play();
	track.setVolume(0.2);
}

//--------------------------------------------------------------
void ofApp::update(){

	if (start == false) {
		// start condition to pause updating
	}
	else{
	if(timer < 30 && end == false){
		// if the timer isn't up yet
		timer = ofGetElapsedTimef();
		prob = ofRandom(1000);
		mainChar.setPos(glm::vec2(mouseX, mouseY));
		trailLine[0].destination = glm::vec2(mouseX, mouseY);


	mainChar.update();

	//probability to generate frequency of veg and cows
	if (prob > 970) {
		glm::vec2 pos = glm::vec2(2736, (int)ofRandom(1824));
		Cow c = Cow(pos, glm::vec2(ofRandom(-12,-20),0), glm::vec2(0, 0), 300);
		cowLine.push_back(c);
		glm::vec2 pos2 = glm::vec2(2736, (int)ofRandom(1824));
		Cow v = Cow(pos2, glm::vec2(ofRandom(-12, -20), 0), glm::vec2(0, 0), 200, "images/broccoli.png");
		vegLine.push_back(v);
	}
	

	for (int i = 0; i < cowLine.size(); i++) {
		cowLine[i].update();

	}

	for (int i = 0; i < vegLine.size(); i++) {
		vegLine[i].update();
	}
	// Setting each trailLine's destination to that of trail before it
	for (int i = 0; i < trailLine.size(); i++) {
		for (int i = 0; i < trailLine.size(); i++) {
			if (i != 0) {
				trailLine[i].destination = trailLine[i - 1].pos;
			}
			trailLine[i].update();
		}
	}
	// check if the trail's bounding box intersected with the veg's bounding box
		for (int i = 0; i < trailLine.size(); i++) {
			for (int j = 0; j < vegLine.size(); j++) {
				ofRectangle trailBox(trailLine[i].pos.x - 100, trailLine[i].pos.y - 100, 200, 200);
				ofRectangle vegBox(vegLine[i].pos.x + 40, vegLine[i].pos.y, vegLine[i].rad + 40, vegLine[i].rad);
				if (trailBox.intersects(vegBox) && vegLine[j].isEaten() == false) {
					while (trailLine.size() > 1) {
						trailLine.pop_back();
					}
					vegLine[j].setEaten(true);
					vegLine.erase(vegLine.begin() + j);
				}
			}
		}
	}
	else {
		end = true;
	}
	}


}

//--------------------------------------------------------------;
void ofApp::draw() {


	if (start == false) {
		startScreen.draw(glm::vec2(0, 0), 2750, 1824);
		//draw start screen
	}
	else {
		//background scoll
		bg1.draw(bg1X, bg1Y, 3592, 1824);
		bg1X -= 10;
		bg2.draw(bg2X, bg2Y, 3592, 1824);
		bg2X -= 10;

		if (bg1X < -1 * 3592) {
			bg1X = bg1.getWidth() + 1785;

		}
		if (bg2X < -1 * 3592) {
			bg2X = bg1.getWidth() + 1785;
		}


		// Print score UI in the top 
		score = trailLine.size();
		char scoreString[100];
		ofPushStyle();
		ofSetColor(ofColor(0, 0, 0));
		sprintf(scoreString, "Hamburgers \ncollected: %i", score);
		myBigFont.drawString(scoreString, 150, 150);
		ofPopStyle();

		for (int i = 0; i < trailLine.size(); i++) {
			trailLine[i].draw();
		}

		// generate bounding box for the main farmer character
		ofRectangle boundingBox(mainChar.pos.x - (150 / 2), mainChar.pos.y - (363 / 2), 150, 363);
		//debug - Show Bounding box
		//ofRect(mainChar.pos.x - (150 / 2), mainChar.pos.y - (363 / 2), 150, 363);
		mainChar.draw();

		// generate bounding box for the cows on the screen
		for (int i = 0; i < cowLine.size(); i++) {
			cowLine[i].draw();
			ofRectangle cowBox(cowLine[i].pos.x, cowLine[i].pos.y, cowLine[i].rad + 130, cowLine[i].rad);
			ofPushStyle();
			ofColor(255, 0, 0);
			ofNoFill();
			//Debug - Show Bounding box
			//ofRect(cowLine[i].pos.x, cowLine[i].pos.y, cowLine[i].rad + 130, cowLine[i].rad);
			ofPopStyle();
			//if the cow bounding box intersects with that of the farmer, shrink the cow and add another trail
			if (boundingBox.intersects(cowBox) && cowLine[i].isEaten() == false) {
				Trail last = trailLine[trailLine.size() - 1];
				trailLine.push_back(Trail(last.pos, glm::vec2(last.pos.x - 10, last.pos.y), 0.05 - (0.0050)));
				cowLine[i].setEaten(true);
				cowLine[i].rad = 0;
				//cowLine.erase(cowLine.begin() + i);
			}
		}

		// Generate bounding box for the Veggies
		for (int i = 0; i < vegLine.size(); i++) {
			vegLine[i].draw();
			ofRectangle vegBox(vegLine[i].pos.x+40, vegLine[i].pos.y, vegLine[i].rad +40, vegLine[i].rad);
			ofPushStyle();
			ofColor(255, 0, 0);
			ofNoFill();
			//debug - Show Bounding box
			//ofRect(vegLine[i].pos.x+40, vegLine[i].pos.y, vegLine[i].rad+40, vegLine[i].rad);
			ofPopStyle();
			//if the veg bounding box intersects with that of the farmer, shrink the veg and add another trail
			if (boundingBox.intersects(vegBox) && vegLine[i].isEaten() == false && trailLine.size() > 1) {
				while (trailLine.size() > 1) {
					trailLine.pop_back();
				}
				vegLine[i].setEaten(true);
				vegLine[i].rad = 0;
			}
		}

		// for debug purposes to show the bounding box of the trail 
		for (int i = 0; i < trailLine.size(); i++) {
			ofPushStyle();
			ofColor(255, 0, 0);
			ofNoFill();
			//debug - Show Bounding Box
			//ofRect(trailLine[i].pos.x - 100, trailLine[i].pos.y - 100, 200, 200);
			ofPopStyle();
		}
	}
	// conditional to check if the time is up and then show the end screen
	if (timer >= 30 && end == true) {
		endScreen.draw(glm::vec2(0, 0), 2750, 1824);
		char scoreString[100];
		ofPushStyle();
		ofSetColor(ofColor(255, 255, 255));
		sprintf(scoreString, "%i hamburgers", score);
		myBiggerFont.drawString(scoreString, ofGetWidth()/2-800, ofGetHeight()/2);
		ofPopStyle();
	}
}

// clear the trail
void ofApp::clearTrail(vector<Trail> vec) {
	for (int i = 0; i < vec.size(); i++) {
		vec.erase(vec.begin() + i);
	}

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

void ofApp::endGame() {
	if (end == true) {

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
	start = true;

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
