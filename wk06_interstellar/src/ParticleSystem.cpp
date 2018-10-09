//
//  ParticleSystem.cpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem()
{
	pos = glm::vec2(0, 0);       // default value
}

ParticleSystem::ParticleSystem(glm::vec2 _pos)
{
	pos = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));                 // assigned value
}

void ParticleSystem::applyForce(glm::vec2 force)
{
	// add the force to all particles

	for (int i = 0; i<particles.size(); i++)
	{
		particles[i].applyForce(force);
	}
}

void ParticleSystem::update(int numNewParticles, int maxParticles)
{

	// create new particles:
	float time = ofGetElapsedTimef();

	for (int i = 0; i<numNewParticles; i++)
	{
			glm::vec2 vel = glm::vec2(ofRandom(-1, 1), ofRandom(0, 0));   // move up
			float mass = ofRandom(0.1, 2);
			pos = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
			Particle particle = Particle(pos, vel, mass);     // start at system's position
			particles.push_back(particle);
	}

	// update particles:

	for (int i = 0; i<particles.size(); i++)
	{
		particles[i].update();
	}

	// erase old particles:

	while (particles.size() > maxParticles)     // keep the number of particles under a limit
	{
	   particles.erase(particles.begin());     // erase the oldest particle
	}

}

void ParticleSystem::draw()
{
	float time = ofGetElapsedTimef();
	for (int i = 0; i<particles.size(); i++)
	{
			particles[i].draw();
	}


}

