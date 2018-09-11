#include "Square.h"

// --------------------------------------------------------
void Square::setup(float posX, float posY, float width, float height){
    
    // setup position and size
    
    x = posX;
    y = posY;
    w = width;
    h = height;
    
    // default to no movement yet - we can set it later
    
    dirX = 0;
    dirY = 0;


	randInd1 = 1;
	randInd2 = 3;

	ofColor color1(82, 70, 76);
	ofColor color2(207, 71, 71);
	ofColor color3(166, 196, 188);
	ofColor color4(234, 122, 88);

	colors = { color1, color2, color3, color4 };


}

// --------------------------------------------------------
void Square::update(){

    
    // move: update position x and y
    
    x += dirX;
    y += dirY;


    
    // bounce:
    
    // check if we moved out of window frame
    
    if(x > ofGetWidth()){
        // if we're too far right...

		randInd1 = ofRandom(0, 3);
		randInd2 = ofRandom(0, 3);
        // bounce
        x = ofGetWidth();        // put back in window
        dirX = dirX * -1;        // flip x movement
        
    }
    else if (x < 0){
        // bounce off left edge

		randInd1 = ofRandom(0, 3);
		randInd2 = ofRandom(0, 3);

        x = 0;
        dirX = dirX * -1;
    }
    
    
    if(y > ofGetHeight()){
        // bounce bottom edge

		randInd1 = ofRandom(0,3);
		randInd2 = ofRandom(0, 3);


        y = ofGetHeight();
        dirY = dirY * -1;
    }
    else if (y < 0){
        // or bounce top edge

		randInd1 = ofRandom(0, 3);
		randInd2 = ofRandom(0, 3);

        y = 0;
        dirY = dirY * -1;
    }

}

// --------------------------------------------------------
void Square::draw(){
	ofBackgroundGradient(colors[randInd1], colors[randInd2], OF_GRADIENT_LINEAR);
	ofSetColor(0, 0, 0,255);
	ofFill();
    ofDrawCircle(x,y,w);

	ofSetColor(0, 0, 0, 100);
	ofFill();
	ofDrawCircle(y, x, w);
    // draw a simple rectangle on screen
}

// --------------------------------------------------------
float Square::getCenterX(){
    return x + (w * 0.5);   // origin plus half the width
}
float Square::getCenterY(){
    return y + (h * 0.5);
}
