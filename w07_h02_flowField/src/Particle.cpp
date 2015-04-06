//
//  Particle.cpp
//  03_flowField
//
//  Created by Bernardo Santos Schorr on 3/31/15.
//
//

#include "Particle.h"

void Particle::setup() {
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Particle::update() {
    
    if (pos.x < 0) { pos.x = ofGetWidth(); }
    if (pos.x > ofGetWidth()) { pos.x = 0; }
    if (pos.y < 0) { pos.y = ofGetHeight(); }
    if (pos.y > ofGetHeight()) { pos.y = 0; }
    
    vel += acc;
    pos += vel;
    
}

void Particle::draw() {
    //ofCircle(pos, 1);
}
