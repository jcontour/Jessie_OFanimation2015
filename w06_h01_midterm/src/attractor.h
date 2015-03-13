//
//  attractor.h
//  w06_h01_midterm
//
//  Created by CHILAQUILES on 3/13/15.
//
//

#pragma once
#include "ofMain.h"

class Attractor{
public:
    
    Attractor(ofVec2f _pos);
    void update();
    void draw();
    
    ofVec2f pos;
    int state;
    ofColor col;
    
};