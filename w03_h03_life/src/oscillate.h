//
//  oscillate.h
//  03_life_a
//
//  Created by CHILAQUILES on 2/24/15.
//
//

#pragma once
#include "ofMain.h"

class oscillate {
public:
    void setup();
    void update(float _oscOffset);
    void draw(float _radius);
    
    float circPosY;
    float sinOT;
    
    
};