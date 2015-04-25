//
//  target.cpp
//  w09_h01_3dSomething
//
//  Created by CHILAQUILES on 4/25/15.
//
//

#include "target.h"

void target::setup(){

}

void target::update(ofVec3f _pos){
    pos.x = _pos.x;
    pos.y = _pos.y;
    pos.z = _pos.z;
}

void target::draw(){
    ofSetColor(255,0,0);
    ofDrawSphere(pos, 10);
}


