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
    goal = 0;
    lifespan = 1000;
    
    
    
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
    
    ofVec2f prevPoint;
    prevPoint.set(pos);
    pos += vel;
    
    ofVec2f difference;
    difference = prevPoint - pos;
    rotation = atan2(difference.y, difference.x);
    rotation = ofRadToDeg(rotation);

    
    lifespan -= ofRandom(-1, 1);

}

void Particle::draw() {
    
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(rotation);
    ofBeginShape(); {
        ofVertex(0, 7);
        ofVertex(-15, 0);
        ofVertex(0, -7);
        ofVertex(-5, 0);
    } ofEndShape(true);
    ofPopMatrix();
    
}