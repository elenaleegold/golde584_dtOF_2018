//
//  Particle.cpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#include "Particle.hpp"

Particle::Particle()
{
    
    // default constructor:
    // Particle particle = Particle();
    
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
	alpha = 255;
	timeAlive = 0;

}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    
    // "overload" constructor, alternative:
    // Particle particle = Particle(pos,vel,acc);
    
    pos = _pos;
    vel = _vel;
    mass = _mass;
	alpha = 255;
	timeAlive = 0;
}

void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
	timeAlive++;
	if (alpha > 0) {
		alpha -= 2;
	}
	else {
		alpha = 0;
	}
}

void Particle::updateAlpha()
{
	vel += acc;
	pos += vel;
	acc *= 0;
	timeAlive++;
	if (alpha > 0) {
		alpha -= 5;
	}
	else {
		alpha = 0;
	}
}

void Particle::draw()
{
    ofPushStyle();
	ofPushMatrix();
	//ofRotateRad(PI/4);
	ofColor colors[3];
	colors[0] = ofColor(255, 0, 0, alpha);
	colors[1] = ofColor(255, 132, 0, alpha);
	colors[2] = ofColor(255, 255, 0, alpha);
    //float hue = ofMap(mass, 0, 5, 0, 255);
    //ofSetColor(ofColor::fromHsb(hue,255,255, alpha));
	ofSetColor(colors[(int)ofRandom(3)]);
    ofDrawCircle(pos, mass * 1.0);
    ofPopStyle();
	ofPopMatrix();
}

void Particle::setAlpha(int a) {
	alpha = a;
}

int Particle::getTime() {
	return timeAlive;
}

void Particle::makeTransp() {
	while (alpha > 0) {
		alpha--;
	}
}
