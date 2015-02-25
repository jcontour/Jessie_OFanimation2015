//
//  look.cpp
//  03_lookie
//
//  Created by CHILAQUILES on 2/21/15.
//
//

#include "look.h"

void look::setup(float _x, float _y){
    
    pos.set(_x, _y);
}

void look::update(float _x, float _y){
    
    ofVec2f pointAt;
    pointAt.set(_x, _y);
    
    diff = pointAt - pos;
    rot = atan2(diff.y, diff.x);
    rot = ofRadToDeg(rot);
    
}

void look::draw(){
    
    float distance = ofDist(pos.x, pos.y, ofGetMouseX(), ofGetMouseY());
    float size = ofMap(distance, 0, 500, 25, 5, true);
    
    float x1 = 0;
    float y1 = size;
    float x2 = -size/2;
    float y2 = 0;
    float x3 = size/2;
    float y3 = 0;
    
    float alpha = ofMap(distance, 0, 350, 255, 50, true);
    ofSetColor(255, alpha);
    
    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(rot);
    ofBeginShape(); {
        ofVertex(x1, y1);
        ofVertex(x2, y2);
        ofVertex(x3, y3);
    } ofEndShape(true);
    ofPopMatrix();
    
}