//
//  flowField.h
//  w09_h02_interactiveMesh
//
//  Created by CHILAQUILES on 4/25/15.
//
//

#pragma once
#include "ofMain.h"

class flowField {
public:
    
    flowField();
    void setup(float w, float h, float res);
    void setRandom(float scale);
    void setNoise();
    void draw();
    
    ofVec2f getForceAt(float x, float y);
    
    vector<ofVec2f> field;
    
    int width, height;
    int internalWidth, internalHeight;
    float resolution;
    int fieldSize;
    
};