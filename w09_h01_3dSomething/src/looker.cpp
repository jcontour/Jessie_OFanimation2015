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
    rot = pointAt.angle(pos);
//    rotX = atan2( diff.y, diff.z);
//    rotY = atan2( diff.x * cos(rotX), diff.z);
//    rotZ = atan2( cos(rotX), sin(rotX) * sin(rotY));
}

void looker::draw(){
    
    ofSetColor(255);
    
    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(rot);
//    ofRotateX(ofRadToDeg(rotX));
//    ofRotateY(ofRadToDeg(rotY));
//    ofRotateZ(ofRadToDeg(rotZ));
    ofDrawCone(0,0,0,3,12);
    ofPopMatrix();
    
}