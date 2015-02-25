//
//  bounce.h
//  02_gaussianPop
//
//  Created by CHILAQUILES on 2/13/15.
//
//

#pragma once
#include "ofMain.h"

class bounce {

public:
    
    void setup(float _vel);
    void update();
    void draw(float _y);
    
    float xPos, yPos;
    float radius;
    ofColor col;
    
private:
    float vel;
    
};
