//
//  landscape.h
//  02_landscape
//
//  Created by CHILAQUILES on 2/12/15.
//
//

#pragma once
#include "ofMain.h"

class landscape {
    
public:
    
    void setup(ofVec2f _pos);
    void update();
    void draw();
    
    ofVec2f pos;
    ofColor col;
    vector<ofVec2f> points;
    vector<ofVec2f> lines;
    
    float mult;
    
};