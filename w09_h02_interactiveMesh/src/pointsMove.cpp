//
//  pointsMove.cpp
//  w09_h02_interactiveMesh
//
//  Created by CHILAQUILES on 4/25/15.
//
//

#include "pointsMove.h"

void pointsMove::setup(float _x, float _y) {
    pos.x = _x;
    pos.y = _y;
}

void pointsMove::resetForces() {
    acc *= 0;
}

void pointsMove::applyForce(ofVec2f force) {
    acc += force;
}

void pointsMove::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void pointsMove::update() {
    
    if (pos.x < 0) { pos.x = ofGetWidth(); }
    if (pos.x > ofGetWidth()) { pos.x = 0; }
    if (pos.y < 0) { pos.y = ofGetHeight(); }
    if (pos.y > ofGetHeight()) { pos.y = 0; }
    
    vel += acc;
    pos += vel;
    
}

void pointsMove::draw() {
    ofSetColor(255, 0, 0);
    ofCircle(pos, 1);
}