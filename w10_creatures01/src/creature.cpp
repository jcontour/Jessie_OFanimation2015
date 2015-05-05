//
//  creature.cpp
//  creatures01
//
//  Created by CHILAQUILES on 5/3/15.
//
//

#include "creature.h"

void creature::setup(float _x){
    
    touched = false;
    
    timer1 = 0;
    timer2 = 0;
    timer3 = 0;

    posy = 0;
    pos.set(_x, ofGetWindowHeight()/2);
    col.set(0,0,255);
    
}

void creature::update(){
    
    if (touched){
        timer1 ++;
        turnRed();
    }
    
    if (timer1 > 100){
        touched = false;
        turnBlue();
    }
    
}

void creature::draw(){
    ofSetColor(col);
    ofCircle(pos,30);

}

void creature::turnRed(){
    col.set(255,0,0);
    pos.y = ofGetWindowHeight()/2 - 30;
}

void creature::halfRed(){
    col.set(150,0,150);
    pos.y = ofGetWindowHeight()/2 - 15;
}

void creature::quarterRed(){
    col.set(50,0,200);
    pos.y = ofGetWindowHeight()/2 - 5;
    
}

void creature::turnBlue(){
    col.set(0,0,255);
    pos.y = ofGetWindowHeight()/2;
    timer1 = 0;
}

