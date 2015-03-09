//
//  explosion.cpp
//  w05_h01_firework
//
//  Created by CHILAQUILES on 3/8/15.
//
//

#include "explosion.h"

void Explosion::setup(ofVec2f _pos){
    pos = _pos;
    
    vel.x = ofRandom(-2,2);
    vel.y = ofRandom(-1, -5);
    
    gravity.set(0, 0.1);
    alpha = 255;

}

void Explosion::resetforces(){
    acc *= 0;
}

void Explosion::applyforces(){
    acc += gravity;
}

void Explosion::update(){
    vel += acc;
    pos += vel;
    
    alpha -= 3;
    
}

void Explosion::draw(){
    
    ofSetColor(255, 0, 0, alpha);
    ofCircle(pos, 2);
    
    
}