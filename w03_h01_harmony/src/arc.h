//
//  arc.h
//  03_harmony
//
//  Created by CHILAQUILES on 2/21/15.
//
//

#pragma once
#include "ofMain.h"
#include "ofPath.h"


class arc {
public:
    void setup(float _radius, float _angleStart, float _angleEnd);
    void update(float _offset);
    void draw();
    
    ofPath makeArc;
    ofPath path;
    
    float posX, posY;
    float radius;
    float angleStart, angleEnd;
    float offset;
    ofColor col;
};