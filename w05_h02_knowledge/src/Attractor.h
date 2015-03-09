//
//  Attractor.h
//  w05_h02_knowledge
//
//  Created by CHILAQUILES on 3/6/15.
//
//

#pragma once
#include "ofMain.h"

class Attractor{
public:
    
    Attractor(ofVec2f _pos);
    void update();
    void draw(ofColor _col);
    
    ofVec2f pos;
    
    float angle;
    float radius;
    
    ofVec2f center;
    ofVec2f rot;
    
    
};