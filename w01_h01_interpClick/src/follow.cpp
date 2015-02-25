//
//  follow.cpp
//  interp_click
//
//  Created by CHILAQUILES on 2/12/15.
//
//

#include "follow.h"

void follow::setup(){
    
    followPos.set(0,0);
    
}

void follow::update(ofVec2f _dest){
    
    followPos = followPos + ((_dest-followPos) * 0.01);
    
    followCol = ofMap((followPos.distance(_dest)), 0, sqrt((ofGetWindowHeight()+ofGetWindowWidth())/2), 0, 255);
}

void follow::draw(){
    
    
    ofSetColor(150, followCol, 200);
    ofCircle(followPos, 2);
    
    
}