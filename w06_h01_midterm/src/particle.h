//
//  particle.h
//  w06_h01_midterm
//
//  Created by CHILAQUILES on 3/13/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    Particle(ofVec2f _pos);
    
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDamping(float damping);
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    
    ofColor col;
    int goal;
    int lifespan;
    
    float rotation;

};