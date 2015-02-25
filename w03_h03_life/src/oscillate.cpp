//
//  oscillate.cpp
//  03_life_a
//
//  Created by CHILAQUILES on 2/24/15.
//
//

#include "oscillate.h"

void oscillate::setup(){
    
    circPosY = 0;
}


void oscillate::update(float _oscOffset){
    
    sinOT = sin(ofGetElapsedTimef()* _oscOffset/2)*_oscOffset;
    circPosY = sinOT;
    
}

void oscillate::draw(float _radius){
    
    ofColor col;
    col.set(90, 200, 35);
    ofSetColor(col);
    ofCircle(0, circPosY, _radius);
}