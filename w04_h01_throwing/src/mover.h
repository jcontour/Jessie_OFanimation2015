//
//  mover.h
//  w04_h01_throwing
//
//  Created by CHILAQUILES on 2/26/15.
//
//

#pragma once
#include "ofMain.h"

class mover {
public:
    void setup(float x, float y);
    void update();
    void draw();
    
    void force(ofVec2f _force);
    void resetForces();
    void applyDamping(float damping);


    ofVec2f pos, vel, acc;
    
};