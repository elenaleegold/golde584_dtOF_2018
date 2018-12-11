#include "Cow.h"


Cow::Cow()
{
	pos = glm::vec2(0, 0);
	vel = glm::vec2(0, 0);
	acc = glm::vec2(0, 0);
	radius = cow.getWidth();
	dir = "images/cow.gif";
	cow.load(dir);       
	deg = 0;
	dirX = 0;
	dirY = 0;
	isCaught = false;
}

Cow::Cow(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc) {
	pos = _pos;
	vel = _vel;
	acc = _acc;
	dir = "images/cow.png";
	cow.load(dir);
	radius = 200;
	rad = ofRandom(100, 300);
	deg = 0;
	dirX = 0;
	dirY = 0;
	isCaught = false;
}

Cow::Cow(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc, float _radius) {
	pos = _pos;
	vel = _vel;
	acc = _acc;
	dir = "images/cow.png";
	cow.load(dir);
	radius = 100;
	rad = ofRandom(200, 300);
	deg = 0;
	dirX = 0;
	dirY = 0;
	isCaught = false;
}

Cow::Cow(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc, float _radius, string s) {
	pos = _pos;
	vel = _vel;
	acc = _acc;
	dir = s;
	cow.load(dir);
	radius = 100;
	rad = ofRandom(200, 300);
	deg = 0;
	dirX = 0;
	dirY = 0;
	isCaught = false;
}

void Cow::update() {
	vel += acc;
	pos += vel;
	acc *= 0;
}

void Cow::setVelocity(glm::vec2 velocity) {
	vel = velocity;
}

void Cow::addForce(glm::vec2 force) {
	acc += force;
}

void Cow::draw() {
	cow.draw(pos, rad+130, rad);
}

void Cow::setPos(glm::vec2 p) {

	pos = p;
	acc = glm::vec2(0, 0);
	vel = glm::vec2(0, 0);

}

bool Cow::isEaten() {
	return isCaught;
}

void Cow::setEaten(bool status) {
	isCaught = status;
}

