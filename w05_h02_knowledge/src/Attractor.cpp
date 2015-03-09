//
//  Attractor.cpp
//  w05_h02_knowledge
//
//  Created by CHILAQUILES on 3/6/15.
//
//

#include "Attractor.h"

Attractor::Attractor(ofVec2f _pos){
    pos = _pos;
    
    angle = 0.0;
    radius = 50.0;
    center = pos;
    
}

void Attractor::update(){
    
    float x = cos(ofDegToRad(angle))*radius;
    float y = sin(ofDegToRad(angle))*radius;
    
    rot.set(center.x + x, center.y + y);
    
    angle -= 5;
    
}

void Attractor::draw(ofColor _col){
    
    ofSetColor(_col);
    ofCircle(rot, 10);
    
    
}