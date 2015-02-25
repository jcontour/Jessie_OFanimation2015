//
//  look.h
//  03_lookie
//
//  Created by CHILAQUILES on 2/21/15.
//
//

#pragma once
#include "ofMain.h"

class look {
public:
    
    void setup(float _x, float _y);
    void update(float _x, float _y);
    void draw();

private:
    float rot;
    ofVec2f pos;
    ofVec2f diff;
    
};