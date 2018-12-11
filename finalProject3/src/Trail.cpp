#include "Trail.h"



Trail::Trail(glm::vec2 _destination, glm::vec2 _pos, float _percent)
{

	destination = _destination;
	hamburger.load("images/hamburger.png");
	pos = _pos;

	percent = _percent;                
}

Trail::Trail(glm::vec2 _destination)
{

	destination = _destination;
	hamburger.load("images/hamburger.png");

	percent = .05;                 
}


void Trail::update() {

	glm::vec2 diff = (destination) - pos;     
	pos += (percent * diff) + glm::vec2(-3,0) ;                  



}

void Trail::draw() {
	hamburger.load("images/hamburger.png");
	hamburger.setAnchorPercent(0.5, 0.5);
	hamburger.draw(pos, 200, 200);

}

void Trail::add() {
	Cow c = Cow(mouse, glm::vec2(0, 0), glm::vec2(0, 0), 200);
	trail.push_back(c);
}

void Trail::popAnim() {
	int count = 0;
	while(count < 10000){
		pos.y ++;
		count++;
	}
}

void Trail::setPercentage(int p) {
	percent = p;
}

