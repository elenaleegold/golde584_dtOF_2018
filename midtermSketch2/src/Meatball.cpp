#include "Meatball.h"


Meatball::Meatball()
{
	pos = glm::vec2(0,0);
	vel = glm::vec2(0, 0);
	acc = glm::vec2(0, 0);
	radius = meatball.getWidth();
	dir = "images/meatball.png";
	meatball.load(dir);
	deg = 0;
	dirX = 0;
	dirY = 0;
}

Meatball::Meatball(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc) {
	pos = _pos;
	vel = _vel;
	acc = _acc;
	dir = "images/meatball.png";
	meatball.load(dir);
	radius = 200;
	rad = ofRandom(100, 300);
	deg = 0;
	dirX = 0;
	dirY = 0;
}

Meatball::Meatball(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc, float _radius) {
	pos = _pos;
	vel = _vel;
	acc = _acc;
	dir = "images/meatball.png";
	meatball.load(dir);
	radius = 100;
	rad = ofRandom(200, 300);
	deg = 0;
	dirX = 0;
	dirY = 0;
}

void Meatball::update() {
	vel += acc;     
	pos += vel;     
	acc *= 0;      
}

void Meatball::setVelocity(glm::vec2 velocity) {
	vel = velocity;
}

void Meatball::addForce(glm::vec2 force) {
	acc += force;       
}

void Meatball::draw() {
	ofPushMatrix();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPopMatrix();
	ofSetRectMode(OF_RECTMODE_CORNER);
	meatball.draw(pos, rad, rad);
	radius = 125;
	pos.y += ofSignedNoise(10)*10;
}

void Meatball::setPos(glm::vec2 p) {

	pos = p;
	acc = glm::vec2(0,0);
	vel = glm::vec2(0, 0);

}

void Meatball::setImage(string s) {
	dir = s;
	meatball.load(s);
}

void Meatball::startBallDraw() {
	meatball.draw(pos, radius, radius);

	pos.x += dirX;
	pos.y += dirY;

	if (pos.x > ofGetWidth() - radius) {
	
		pos.x = ofGetWidth() - radius;       
		dirX = dirX * -1;        

	}
	else if (pos.x < 0) {

		pos.x = 0;
		dirX = dirX * -1;
	}


	if (pos.y > ofGetHeight() - radius) {

		pos.y = ofGetHeight() - radius;
		dirY = dirY * -1;
	}
	else if (pos.y < 0) {

		pos.y = 0;
		dirY = dirY * -1;
	}
}

void Meatball::setDir(int x, int y) {
	dirX = x;
	dirY = y;
}

void Meatball::setRad(int r) {
	radius = 200 + r;
}