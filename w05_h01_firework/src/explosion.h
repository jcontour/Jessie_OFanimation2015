//
//  explosion.h
//  w05_h01_firework
//
//  Created by CHILAQUILES on 3/8/15.
//
//

#pragma once
#include "ofMain.h"

class Explosion {
    
public:
    void setup(ofVec2f _pos);
    void update();
    void draw();
    void resetforces();
    void applyforces();
    
    ofVec2f gravity;
    ofVec2f pos, vel, acc;
    float alpha;

};