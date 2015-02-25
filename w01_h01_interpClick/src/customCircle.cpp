//
//  customCircle.cpp
//  interp_click
//
//  Created by CHILAQUILES on 2/12/15.
//
//

#include "customCircle.h"

void customCircle::setup(ofVec2f _aPos, ofVec2f _bPos) {
    aPos = _aPos;
    bPos = _bPos;
    click = 1;
}

void customCircle::update(float _pct){
    
    pct = _pct;
    pos = (aPos * (1 - pct) + bPos * pct);
    col = ofMap(pct, 0, 1, 0, 255);
    
}

void customCircle::draw(){
    
    ofSetColor(255);
    ofCircle(aPos, 5);
    ofCircle(bPos, 5);
    ofLine(aPos, bPos);
    
    ofSetColor(col, 255, 0);
    ofCircle(pos, 10);
    
}

void customCircle::updatePath(ofVec2f _mousePos){

    ofVec2f tempPos = aPos;
    
    aPos = bPos;
    bPos = _mousePos;
    
}

