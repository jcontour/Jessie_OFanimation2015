//
//  Particle.h
//  w05_h02_knowledge
//
//  Created by CHILAQUILES on 3/6/15.
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
    void checkEdges();
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    
    float radius;
    ofColor col;
    
};