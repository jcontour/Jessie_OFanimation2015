//
//  follow.cpp
//  03_life_a
//
//  Created by CHILAQUILES on 2/24/15.
//
//

#include "follow.h"

void follow::setup(){
    
    pos.set(0,0);
    
}

void follow::update(ofVec2f _dest){
    
    pos = pos * 0.9 + _dest * 0.1;
    
}

void follow::draw(float _radius){
    
    radius = _radius;
    ofColor col;
    col.set(90, 200, 35);
    ofSetColor(col);
    ofCircle(pos, radius);
    
}