#pragma once

#include "ofMain.h"
#include "Block.h"

class Sequence
{
public:
	Sequence();
	Sequence(int _numBlocks);
	void draw();
	void update();
	int numBlocks;
	void drawGround();
	vector <int> randVals;

	vector <Block> blocks;

	Block getBlock(int i);

	int windowWidth = 2736;
	int windowHeight = 1824;


};
