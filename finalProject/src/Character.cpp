#include "Character.h"
# include "Sequence.h"

Character::Character()
{
	pos = glm::vec2(100, ofGetWidth()*0.75);
	vel = glm::vec2(0, 0);
	acc = glm::vec2(0, 0);
	gravity = glm::vec2(0, 10);
	isGrounded = true;
	radius = 100;
}

Character::Character(glm::vec2 _pos, glm::vec2 _vel, glm::vec2 _acc) {
	pos = _pos;
	vel = _vel;
	acc = _acc;
	gravity = glm::vec2(0, 10);
	radius = 100;
	isGrounded = true;
}

void Character::update() {
	vel += acc;
	pos += vel;
	acc *= 0;
    addForce(gravity);
}

void Character::setVelocity(glm::vec2 velocity) {
	vel = velocity;
}

void Character::addForce(glm::vec2 force) {
	acc += force;
}

void Character::draw() {
	ofDrawCircle(pos, radius);
}

void Character::onGround(int loc) {
	if (pos.y >= loc) {
		pos.y = loc;
		isGrounded = true;
	}
	else{
	isGrounded = false;
	}
}

bool Character::higherGround(int loc, int locWidth, int nextLoc) {
	if (nextLoc > pos.y && pos.x >= loc + locWidth) {
		return true;	
	}
	else {
		return false;
	}
}

bool Character::offScreen() {
	if (pos.x > windowWidth) {
		return true;
	}
	else {
		return false;
	}
}

void Character::jump() {
	if (isGrounded) {
		vel.y = -75.0;
	}
}

void Character::setToStart(int loc) {
	pos.x = 100;
	pos.y = loc;
	vel = glm::vec2(0, 0);
}

int Character::getSeq(int numBlock) {
	return 1;
}