//
//  rocket.h
//  w05_h01_firework
//
//  Created by CHILAQUILES on 3/8/15.
//
//

#pragma once
#include "ofMain.h"
#include "explosion.h"

class Rocket {
    
public:
    void setup(ofVec2f _pos);
    void update();
    void draw();
    
    ofVec2f startpos, pos, finalpos;
    float pct;
    
    Explosion explosion;
    vector<Explosion> explosions;
    
    
};