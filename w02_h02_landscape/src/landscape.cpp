//
//  landscape.cpp
//  02_landscape
//
//  Created by CHILAQUILES on 2/12/15.
//
//

#include "landscape.h"

void landscape::setup(ofVec2f _pos){
    pos.x = _pos.x;
    pos.y = _pos.y;
    mult = 0;
    
}

void landscape::update(){
    
    //making random walk
    
    int choice = ofRandom(7);
    if (choice == 0) pos.y+=5;
    if (choice == 1) pos.y+=5;
    if (choice == 2) pos.y-=5;
    if (choice == 3) pos.x-=15;
    if (choice >= 4) pos.x+=20;
    
    //looping around screen edges
    
    if (pos.x > ofGetWindowWidth()) pos.x = 0;
    if (pos.y > ofGetWindowHeight()) pos.y = 0;
    
    //adding positions to vector of points
    
    points.push_back(pos);
    lines.push_back(pos);
    
    //trying to add movement to y points by multiplying them by perline noise?
    
    for (int i = 0; i < points.size(); i++){
        float noise = ofNoise(points[i].x, points[i].y, mult);
        float offset = ofMap(noise, 0, 1, -25, 25);
        points[i].y = points[i].y + offset;
    }
    
    mult += 0.001;
    
    //mapping color to height
    
    float r = ofMap(pos.y, 0, ofGetScreenHeight(), 51, 102);
    float g = ofMap(pos.y, 0, ofGetScreenHeight(), 153, 51);
    
    col.set(r,g,0);
    
}

void landscape::draw(){
    
    
    for (int i = 1; i < points.size(); i++) {
        ofSetColor(col, 100);
        ofSetLineWidth(0.5);
        ofLine(lines[i].x, lines[i].y, lines[i].x, ofGetWindowHeight());
        ofCircle(lines[i].x, lines[i].y, 5, 5);
        
        ofSetColor(255, 100);
        ofCircle(points[i].x, points[i].y, 3, 3);
    }
    
}