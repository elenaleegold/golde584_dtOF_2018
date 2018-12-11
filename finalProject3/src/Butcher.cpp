#include "Butcher.h"



Butcher::Butcher()
{
	pos = glm::vec2(0, 0);
	vel = glm::vec2(0, 0);
	acc = glm::vec2(0, 0);
	radius = butcher.getWidth();
	dir = "images/butcher.png";
	butcher.load(dir);
	deg = 0;
	dirX = 0;
	dirY = 0;
}

Butcher::Butcher(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc) {
	pos = _pos;
	vel = _vel;
	acc = _acc;
	dir = "images/butcher.png";
	butcher.load(dir);
	radius = 200;
	rad = ofRandom(100, 300);
	deg = 0;
	dirX = 0;
	dirY = 0;
}

Butcher::Butcher(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc, float _radius) {
	pos = _pos;
	vel = _vel;
	acc = _acc;
	dir = "images/butcher.png";
	butcher.load(dir);
	radius = 100;
	rad = ofRandom(200, 300);
	deg = 0;
	dirX = 0;
	dirY = 0;
}

void Butcher::update() {
	vel += acc;
	pos += vel;
	acc *= 0;
}

void Butcher::setVelocity(glm::vec2 velocity) {
	vel = velocity;
}

void Butcher::addForce(glm::vec2 force) {
	acc += force;
}

void Butcher::draw() {
	butcher.setAnchorPercent(0.5, 0.5);
	butcher.draw(pos, 150, 363);
	butcher.bind();
	ofPushStyle();
	ofSetColor(255);
	ofRectangle boundingBox(pos.x, pos.y, 150, 363);
	ofPopStyle();
	butcher.unbind();
}

void Butcher::setPos(glm::vec2 p) {

	pos = p;
	acc = glm::vec2(0, 0);
	vel = glm::vec2(0, 0);

}