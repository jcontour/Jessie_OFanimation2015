//
//  follow.h
//  03_life_a
//
//  Created by CHILAQUILES on 2/24/15.
//
//

#pragma once
#include "ofMain.h"

class follow {
public:
    
    void setup();
    void update(ofVec2f _dest);
    void draw(float _radius);
    void sinwave(ofVec2f _prevPos, ofVec2f _pos);
    
    ofVec2f pos;
    float radius;
    
};