#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetCircleResolution(100);

	//Initialize the Start screen meatballs
	for (int i = 0; i < 10; i++) {
		startPos = glm::vec2(ofRandom(ofGetWidth() - 200), ofRandom(ofGetHeight() - 200));
		Meatball startBall = Meatball(startPos, glm::vec2(5, 8), glm::vec2(0, 0));
		startBall.setDir(ofRandom(-5,5), ofRandom(-7,7));
		stArr[i] = startBall;
	}

	//Add colors to color vector
	colors.push_back(ofColor::fromHex(0xf1d152));
	colors.push_back(ofColor::fromHex(0xab0000));
	colors.push_back(ofColor::fromHex(0xf8ff85));
	colors.push_back(ofColor::fromHex(0xf2f178));
	colors.push_back(ofColor::fromHex(0xffeda7));
	colors.push_back(ofColor::fromHex(0xf6d72b));
	colors.push_back(ofColor::fromHex(0xffe169));

	//load up sounds and play
	amore.load("amore.mp3");
	squish.load("squish3.mp3");
	amore.play();
	amore.setVolume(0.2);

	//initial variables for startScreen 
	meatballCount = 0;
	startPos = glm::vec2(ofGetWidth()*0.5, 100);
	y = -1200;
	score = 0;
	dirX = 5;
	dirY = 5;

	int count = 0;
	//Initialize gamescreen spaghetti 
	for(int i = 0; i < 15; i++) {
		ofPushMatrix();
		spArr.push_back(Spaghetti(10, ofRandom(0,30), ofRandom(50,100), (i*10) + 100));
		if (count < colors.size()) {
			spArr[i].setColor(colors[count]);
			count++;
		}
		else {
			count = 0;
		}

		spArr[i].setDeg((i*10)*0.25);
		ofPopMatrix();
	}


	//Initialize tutorial variables
	tutorialOn = false;

	//Initialize fork image
	fork.load("images/fork.png");

	//Initialize first meatball
	m = Meatball(glm::vec2(ofGetWidth(), 600), glm::vec2(0, 0), glm::vec2(-7,0));

	//activate stick is set to true when there is a collision 
	activateStick = false;
	//start is set to true when the user passes the start screen
	start = false;

	//load fonts
	myFont.load("8-bit pusab.ttf", 20);
	myBigFont.load("8-bit pusab.ttf", 42);

	squishSound = false;
	squishCount = 0;

}

//--------------------------------------------------------------
void ofApp::update(){
	m.update();
	//checking for collision
	if (((y+(fork.getHeight())) + (m.radius*0.5) > m.pos.y+80) && ((m.pos.x +80 <= (ofGetWidth() * 0.5) + (m.radius) && (m.pos.x + 80 >= (ofGetWidth() * 0.5) - (m.radius))))) {
		cout << "Collision detected!" << endl;
		activateStick = true;
		squishSound = true;
		
	}
	// if collision, change positioning of meatball to align with fork 
	if (activateStick) {
		m.setPos(glm::vec2(ofGetWidth()*0.5-(m.radius), y + fork.getHeight()-(m.radius*0.5)));

	}

	if (squishSound == true) {
		squish.setSpeed(0.6);
		squish.setVolume(1);
		squish.setLoop(false);
		if (squishCount < 1) {
			squish.play();
			squishCount++;
		}
		else {
			squishCount = 0;
			squishSound = false;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//if user is past start screen
	if(start){
		
		// Meatball score UI
		char scoreString[40];
		sprintf(scoreString, "Meatballs\neaten: %i", score);
		myFont.drawString(scoreString, 80, 80);

		//draw meatballs and give each one unique, random properties 
	for (int i = 0; i < spArr.size(); i++) {
		ofPushMatrix();
		spArr[i].setAmplitude((i*2)+30);
		spArr[i].setSize((i*5)+30);
		ofTranslate(0, i*60);
		spArr[i].draw();
		ofPopMatrix();
	}
		//Change fork to draw from the center
		ofPushMatrix();
		fork.setAnchorPoint(fork.getWidth() / 2, 0);
		ofRotateDeg(ofSignedNoise(ofGetElapsedTimef())*5);
		fork.draw(ofGetWidth()*0.5, y);
		ofPopMatrix();

		// Add tutorial messaging if the user has not yet interacted
		if (tutorialOn == true) {
			ofPushStyle();
			ofSetColor(0);
			myFont.drawString("Press 'm' to spear a meatball!", ofGetWidth()*0.5 - 350, ofGetHeight()*0.5 + 400);
			if (fishPress) {
				tutorialOn = false;
			}
			ofPopStyle();
		}
		// Fish press is activated on key press, and sends the fork down and up
		if (fishPress) {
			y+=60;
		}

		if (fishPress == false && y > -1200) {
			y -= 60;
		}

		// Collision sequence 
	if (activateStick && tutorialOn == false) {
		squish.stop();
		m.setImage("images/meatballScared.png");
		ofPushMatrix();
		// Draw meatball to wobble with the fork 
		ofRotateDeg(ofSignedNoise(ofGetElapsedTimef()) * 5);
		m.draw();
		ofPopMatrix();
		
		// Check if the meatball has reached the top (via the fork) if so, change the meatball properties on the screen
		if (m.pos.y < 425 || m.pos.x < 0 || m.pos.x > ofGetWidth()) {
			score++;
			int rand = ofRandom(0, 10);
			glm::vec2 newPos, newVel;
			if (rand < 5) {
				newPos = glm::vec2(0, (ofRandom(600, ofGetHeight()-m.radius)));
				newVel = glm::vec2(ofRandom(30, 50),0);
			}
			else {
				newPos = glm::vec2(ofGetWidth(), (ofRandom(600, ofGetHeight() - m.radius)));
				newVel = glm::vec2(ofRandom(-30, -50), 0);
			}
			m = Meatball(newPos, glm::vec2(0,0), newVel,ofRandom(40,100));
			activateStick = false;
			m.setImage("images/meatball.png");
		}
	}
	// if the user misses and the meatball runs off the screen, still change the properties
	else {
		m.draw();
		if (m.pos.x < 0 || m.pos.x > ofGetWidth()) {
			int rand = ofRandom(0, 10);
			glm::vec2 newPos, newVel;
			if (rand < 5) {
				newPos = glm::vec2(0, (ofRandom(600, ofGetHeight() - m.radius)));
				newVel = glm::vec2(ofRandom(10, 50), 0);
			}
			else {
				newPos = glm::vec2(ofGetWidth(), (ofRandom(600, ofGetHeight() - m.radius)));
				newVel = glm::vec2(ofRandom(-10, -50), 0);
			}
			m = Meatball(newPos, glm::vec2(0, 0), newVel, ofRandom(150,300));
		}
	}
	}
	else {
		//if the user is seeing the game for the first time and hasn't clicked, play the start screen
		startScreen();
	}


}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'c') {
		keyPress = true;
	}
	else if (key == 'm') {
		fishPress = true;
	}
}
void ofApp::startScreen() {
	//Draw start screen images
	ofPushStyle();
	ofSetColor(0);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofSetColor(255);
	// draw bouncing meatballs
	for (int i = 0; i < stArr.size(); i++) {
		stArr[i].setRad(ofRandom(0, 5));
		stArr[i].startBallDraw();
	}
	// Draw title screen text
	string s = "  Imagine the\nPastabilities!";
	string q = "Press 'c' to start!";
	myBigFont.drawString(s, ofGetWidth()*0.5-325, ofGetHeight()*0.5-100);
	myFont.drawString(q, ofGetWidth()*0.5 - 225, ofGetHeight()*0.5 + 100);
	if (keyPress) {
		start = true;
		tutorialOn = true;
	}
	
	ofPopStyle();


}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	keyPress = false;
	fishPress = false;
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
