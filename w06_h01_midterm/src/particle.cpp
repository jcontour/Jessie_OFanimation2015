//
//  particle.cpp
//  w06_h01_midterm
//
//  Created by CHILAQUILES on 3/13/15.
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

void Particle::update() {
    vel += acc;
    pos += vel;
}

void Particle::draw() {

    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(pos);
//    ofRotate(rot);
    ofBeginShape(); {
        ofVertex(0, 5);
        ofVertex(2.5, 0);
        ofVertex(-2.5, 0);
    } ofEndShape(true);
    ofPopMatrix();
    
}