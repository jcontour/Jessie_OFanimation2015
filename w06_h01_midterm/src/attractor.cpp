//
//  attractor.cpp
//  w06_h01_midterm
//
//  Created by CHILAQUILES on 3/13/15.
//
//

#include "attractor.h"

Attractor::Attractor(ofVec2f _pos){
    
    pos = _pos;
    state = 1;

}

void Attractor::update(){
    
    if (state == 1) {    col.set(255,0,0);   }
    if (state == 2) {    col.set(0,0,255);   }
    if (state == 3) {    col.set(0);         }
    
}

void Attractor::draw(){

    ofSetColor(col);
    ofCircle(pos, 10);
    
}

