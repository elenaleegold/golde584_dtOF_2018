#include "Block.h"
# include "Character.h"

Block::Block()
{
	pos = glm::vec2(0, 0);
}

Block::Block(glm::vec2 _pos, int _width, int _height) {
	pos = _pos;
	width = _width;
	height = _height;
	c = ofColor(255);
}

void Block::update() {

}

void Block::draw() {

	ofPushStyle();
	ofSetColor(c);
	ofRect(pos.x, pos.y, width, height);
	//ofRectangle myRect;
	//myRect.x = pos.x;
	//myRect.y = pos.x;
	//myRect.width = width;
	//myRect.height = height;
	//ofDrawRectRounded(myRect, 10);
	ofPopStyle();
}

int Block::getWidth() {
	return width;
}

int Block::getHeight() {
	return height;
}

glm::vec2 Block::getPos() {
	return pos;
}

int Block::getX() {
	return pos.x;
}

int Block::getY() {
	return pos.y;
}


void Block::setColor(int a, int b, int q, int d) {
	c = ofColor(a, b, q, d);
}