//
//  arc.cpp
//  03_harmony
//
//  Created by CHILAQUILES on 2/21/15.
//
//

#include "arc.h"


void arc::setup(float _radius, float _angleStart, float _angleEnd){
    
    radius = _radius;
    angleStart = _angleStart;
    angleEnd = _angleEnd;
    posX = ofGetWindowWidth()/2;
    posY = ofGetWindowHeight()/2;

    makeArc.setColor(ofColor(0,0,0,255));
    makeArc.setStrokeColor(ofColor (255, 255, 255, 50));
    makeArc.setStrokeWidth(5);
    makeArc.setCircleResolution(50);
    makeArc.arc(posX, posY, _radius, _radius, angleStart, angleEnd);
    
}

void arc::update(float _offset){
    
    ofVec2f center;
    center.set(posX,posY);
    makeArc.rotate(_offset, center);
    
}

void arc::draw(){
    
    makeArc.draw();
}