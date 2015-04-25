//
//  target.h
//  w09_h01_3dSomething
//
//  Created by CHILAQUILES on 4/25/15.
//
//

#pragma once
#include "ofMain.h"

class target {
 
public:
    void setup();
    void update(ofVec3f _pos);
    void draw();
    
    ofVec3f pos;
    
};
