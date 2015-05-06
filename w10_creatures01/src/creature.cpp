//
//  creature.cpp
//  creatures01
//
//  Created by CHILAQUILES on 5/3/15.
//
//

#include "creature.h"

void creature::setup(float _x){
    
    movingUp = false;
    atTop = false;
    movingDown = false;
    
    
    col.set(0,0,255);
    
    pos.set(_x, ofGetWindowHeight()/2);
    
}

void creature::update(){
    

    if (movingUp) {
        counter = 0;
        if ( pos.y > ofGetWindowHeight()/2 - height ) {
            pos.y -= 5;
        } else {
            movingUp = false;
            atTop = true;
        }
    }
    
    if (atTop) {
        counter ++;
        if (counter > 60) {
            atTop = false;
            movingDown = true;
        }
    }
    
    if (movingDown) {
        if ( pos.y < ofGetWindowHeight()/2) {
            pos.y += 2;
        } else {
            movingDown = false;
        }
    }
    
}

void creature::draw(){
    float colorMap = ofMap(pos.y, ofGetWindowHeight()/2-100,
                           ofGetWindowHeight()/2, 0, 255, true);
    col.set(255-colorMap, 0, colorMap);
    ofSetColor(col);
    ofCircle(pos,30);
}

void creature::trigger(int _id) {
    
    triggerId = _id;
    
    if (_id == 1) {
        height = 150;
    }
    
    if (_id == 2) {
        height = 75;
    }
    
    if (_id == 3){
        height = 25;
    }
    
    movingUp = true;
    
}




