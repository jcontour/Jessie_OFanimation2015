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
    void trigger(int _id);
    
    bool movingUp, atTop, movingDown;
    
    ofVec2f pos;
    
    int counter;
    
    int triggerId;
    
    float height;
    
    ofColor col;
};