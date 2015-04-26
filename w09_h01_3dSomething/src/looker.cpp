//
//  looker.cpp
//  w09_h01_3dSomething
//
//  Created by CHILAQUILES on 4/25/15.
//
//

#include "looker.h"

void looker::setup(float _x, float _y, float _z){
    
    pos.set(_x, _y, _z);
}

void looker::update(ofVec3f _pointAt){
    
    ofVec3f pointAt;
    pointAt.set(_pointAt.x, _pointAt.y, _pointAt.z);
    
    diff = pointAt - pos;
    ofVec3f norm = diff.normalize();
    rotX = atan2(norm.y, sqrt(1 - norm.y * norm.y));
    rotY = atan2(diff.x, diff.z);
}

void looker::draw(){
    
    ofNoFill();
    
    ofPushMatrix();
    ofTranslate(pos);
    ofRotateX(rotX);
    ofRotateY(rotY);
    ofDrawBox(pos, 10);
    ofPopMatrix();
    
}