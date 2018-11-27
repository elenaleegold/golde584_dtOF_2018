#include "Sequence.h"
#include "Character.h"
#include "Block.h"

Sequence::Sequence()
{

}

Sequence::Sequence(int _numBlocks) {
	numBlocks = _numBlocks;
	for (int i = 0; i < numBlocks; i++) {
		randVals.push_back(ofRandom(300));
	}
}

void Sequence::update() {
}

void Sequence::draw() {
	drawGround();
	for (int i = 0; i < blocks.size(); i++) {
		blocks[i].draw();
	}
}

void Sequence::drawGround() {
	ofPushStyle();
;	for (int i = 0; i < numBlocks; i++) {
		Block b = Block(glm::vec2(i * (windowWidth / numBlocks), windowHeight * 0.75 + randVals[i]), (windowWidth / numBlocks), windowHeight * 0.25);
		b.setColor(0, 255 - (i * 25), 0, 255);
		blocks.push_back(b);
	}
	ofPopStyle();
}

Block Sequence::getBlock(int i) {
	return blocks[i];
}

