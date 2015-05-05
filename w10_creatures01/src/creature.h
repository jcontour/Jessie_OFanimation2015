//
//  creature.h
//  creatures01
//
//  Created by CHILAQUILES on 5/3/15.
//
//

#pragma once
#include "ofMain.h"

class creature {
public:
    void setup(float _x);
    void update();
    void draw();
    
    void turnBlue();
    void turnRed();
    void halfRed();
    void quarterRed();
    
    bool touched;
    int timer1;
    int timer2;
    int timer3;
    
    ofVec2f pos;
    float posy;
    ofColor col;
    
};