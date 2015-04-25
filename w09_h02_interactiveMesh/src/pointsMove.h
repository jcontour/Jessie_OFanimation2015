//
//  pointsMove.h
//  w09_h02_interactiveMesh
//
//  Created by CHILAQUILES on 4/25/15.
//
//

#pragma once
#include "ofMain.h"

class pointsMove {
public:
    
    void setup(float _x, float _y);
    
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    
};