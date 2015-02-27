//
//  mover.cpp
//  w04_h01_throwing
//
//  Created by CHILAQUILES on 2/26/15.
//
//

#include "mover.h"

void mover::setup(float x, float y){
    
    pos.set(x,y);

}

void mover::resetForces(){
    acc*=0;
}

void mover::force(ofVec2f _force){
    
    acc += _force;
    
}

void mover::applyDamping(float damping){
    
    acc -= vel.getNormalized()*damping;
    
}

void mover::update(){
    
    vel += acc;
    pos += vel;
    
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


void mover::draw(){
    
    ofCircle(pos, 10);
    
}