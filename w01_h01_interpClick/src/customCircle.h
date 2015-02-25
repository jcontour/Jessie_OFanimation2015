//
//  customCircle.h
//  interp_click
//
//  Created by CHILAQUILES on 2/12/15.
//
//

#pragma once
#include "ofMain.h"
#include "follow.h"

class customCircle {
public:
    
    void setup(ofVec2f _aPos, ofVec2f _bPos);
    void update(float _speed);
    void draw();
    void updatePath(ofVec2f _mousePos);
    
    
    ofVec2f aPos;
    ofVec2f bPos;
    ofVec2f pos;
    
    float pct;
    int click;
    
    float col;
    
    
};