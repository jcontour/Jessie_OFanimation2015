//
//  attractor.cpp
//  w06_h01_midterm
//
//  Created by CHILAQUILES on 3/13/15.
//
//

#include "attractor.h"

Attractor::Attractor(ofVec2f _pos, int _offset){
    
    pos = _pos;
    offset = _offset;

}

void Attractor::update(){
    
    float sinOfTime = sin(ofGetElapsedTimef()*3+offset);
    radius = ofMap(sinOfTime, -1, 1, 5 , 10);
    
    
}

void Attractor::draw(){

    ofSetColor(255, 0, 0);
    ofCircle(pos, radius);
    
}

