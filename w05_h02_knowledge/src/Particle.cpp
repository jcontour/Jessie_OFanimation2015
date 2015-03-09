//
//  Particle.cpp
//  w05_h02_knowledge
//
//  Created by CHILAQUILES on 3/6/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos) {
    pos.set(_pos);
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::applyDamping(float damping){
    acc -= vel.getNormalized() * damping;
}

void Particle::checkEdges() {
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
}

void Particle::draw() {
    ofSetColor(255);
    ofCircle(pos, 1);
}