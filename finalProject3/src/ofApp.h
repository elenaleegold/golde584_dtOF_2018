#pragma once

#include "ofMain.h"
#include "Cow.h"
#include "Butcher.h"
#include "Trail.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		ofImage startScreen, endScreen;
		bool free, debug, start, end;
		int timer, score;

		Cow cowtest;

		int prob;
		ofTrueTypeFont myBigFont;
		ofTrueTypeFont myBiggerFont;
		Butcher mainChar;
		ofSoundPlayer track;

		vector<Trail> trailLine;
		vector<Cow> cowLine;
		vector<Cow> vegLine;

		ofImage bg1, bg2;
		int bg1X, bg1Y;
		int bg2X, bg2Y;

		void clearTrail(vector<Trail> vec);
		void endGame();
		
};
