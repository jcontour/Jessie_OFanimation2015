//
//  bounce.cpp
//  02_gaussianPop
//
//  Created by CHILAQUILES on 2/13/15.
//
//

#include "bounce.h"

void bounce::setup(float _vel){

    vel = _vel;
    xPos = 0;
    radius = ofMap(vel, 0, 20, 15, 2, true);
    
    col.r = ofMap(vel, 0, 20, 0, 255, true);
    col.g = 0;
    col.b = ofMap(vel, 0, 20, 255, 0, true);
    
    
}

void bounce::update(){

    xPos += vel;
    
    if (xPos > ofGetWindowHeight() || xPos < 0){
        vel = -vel;
    };
    
    //cout << vel;
}

void bounce::draw(float _y){
    
    ofSetColor(col);
    ofCircle(yPos, xPos, radius);
    yPos = _y;
    
    
    
}