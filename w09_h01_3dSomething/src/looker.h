//
//  looker.h
//  w09_h01_3dSomething
//
//  Created by CHILAQUILES on 4/25/15.
//
//

#pragma once
#include "ofMain.h"

class looker {
public:
    
    void setup(float _x, float _y, float _z);
    void update(ofVec3f _pointAt);
    void draw();
    
private:
    float rotX, rotY, rotZ;
    ofVec3f pos;
    ofVec3f diff;
    
};