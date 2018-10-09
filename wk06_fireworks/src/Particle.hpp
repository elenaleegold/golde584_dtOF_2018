//
//  Particle.hpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void applyForce(glm::vec2 force);
	void setAlpha(int a);
    void update();
	int getTime();
    void draw();
	void makeTransp();
	void updateAlpha();
	ofColor colors[3];
    
    glm::vec2 pos, vel, acc;
    float mass;
	int alpha;
	int timeAlive;

    
};
