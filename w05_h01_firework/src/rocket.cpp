//
//  rocket.cpp
//  w05_h01_firework
//
//  Created by CHILAQUILES on 3/8/15.
//
//

#include "rocket.h"

void Rocket::setup(ofVec2f _pos){
    
    finalpos = _pos;
    
    startpos.set(ofGetWidth()/2, ofGetHeight());
    
    pct = 0;
    
    for (int i = 0; i < 100; i++){
        explosion.setup(finalpos);
        explosions.push_back(explosion);
    }
    
}


void Rocket::update(){
    
    pos = startpos * (1 - pct) + finalpos * pct;
    
    if (pct < 1){
        pct += .01;
    } else {
        pct = 1;
        for (int i = 0; i < explosions.size(); i++) {
            explosions[i].resetforces();
            explosions[i].applyforces();
            explosions[i].update();

        }
    }
    
    
    
    
}

void Rocket::draw(){
    
    ofSetColor(255,0,0);
    ofCircle(pos, 5);
    
    if (pct == 1){
        for (int i = 0; i < explosions.size(); i++) {
            explosions[i].draw();
        }
    }
    
    
}