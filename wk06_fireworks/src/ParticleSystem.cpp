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
	pos = _pos;                 // assigned value
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
		if (time < 2) {
			float mass = ofRandom(.01, 5);
			glm::vec2 vel2 = glm::vec2(ofRandom(0, 1), ofRandom(-3, 3));
			Particle particle2 = Particle(glm::vec2(pos.x, pos.y--), vel2, mass);
			particleStem.push_back(particle2);
		}
		else if (time >= 2 && time < 2.5) {
			glm::vec2 vel = glm::vec2(ofRandom(-3, 3), ofRandom(-3, 3));   // move up
			float mass = ofRandom(.01, 5);
			Particle particle = Particle(pos, vel, mass);     // start at system's position
			particles.push_back(particle);
		}
		cout << particles.size() << endl;
		cout << particleStem.size() << endl;
	}

	// update particles:

	for (int i = 0; i<particles.size(); i++)
	{
		particles[i].update();
	}

	for (int i = 0; i < particleStem.size(); i++) {
		particleStem[i].updateAlpha();
	}

	// erase old particles:

	while (particles.size() > maxParticles)     // keep the number of particles under a limit
	{
	   particles.erase(particles.begin());     // erase the oldest particle
	}

	while (particleStem.size() > maxParticles)     // keep the number of particles under a limit
	{
		particles.erase(particles.begin());     // erase the oldest particle
	}

}

void ParticleSystem::draw()
{
	float time = ofGetElapsedTimef();
	for (int i = 0; i<particles.size(); i++)
	{
		if (time > 2) {
			particles[i].draw();
		}
	}

	for (int i = 0; i<particleStem.size(); i++)
	{
			particleStem[i].draw();
	}


}

