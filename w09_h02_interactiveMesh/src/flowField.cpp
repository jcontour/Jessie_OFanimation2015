//
//  flowField.cpp
//  w09_h02_interactiveMesh
//
//  Created by CHILAQUILES on 4/25/15.
//
//

#include "flowField.h"

flowField::flowField(){
    
}

void flowField::setup(float w, float h, float res){
    width = w;
    height = h;
    resolution = res;
    
    internalWidth = ceil(width/resolution);
    internalHeight = ceil(height/resolution);
    
    fieldSize = internalWidth * internalHeight;
    
    for (int i = 0; i < fieldSize; i ++){
        ofVec2f flow;
        flow.set(0.0, 0.0);
        field.push_back(flow);
    }
}

void flowField::setRandom(float scale){
    
    for (int i = 0; i < fieldSize; i ++) {
        float x = ofRandom(-1, 1) * scale;
        float y = ofRandom(-1, 1) * scale;
        
        field[i].set(x, y);
    }
}

void flowField::setNoise(){
    for (int y = 0; y < internalHeight; y++) {
        for (int x = 0; x < internalHeight; x++) {
            int index = y * internalWidth + x;
            
            float noise = ofNoise(x*0.05, y*0.05);
            noise = ofMap(noise, 0, 1, 0, TWO_PI);
            
            field[index].set(ofVec2f(cos(noise)*2.0, sin(noise)*2.0));
            
        }
    }
}

void flowField::draw(){
    for (int y = 0; y < internalHeight; y++) {
        for (int x = 0; x < internalHeight; x++) {
            int index = (y * internalWidth) + x;
            
            float px = x*resolution;
            float py = y*resolution;
            float px2 = px + field[index].x * 5;
            float py2 = py + field[index].y * 5;
            
            ofSetColor(100);
            ofLine(px, py, px2, py2);
            ofCircle(px, py, 2);
        }
    }
}

ofVec2f flowField::getForceAt(float x, float y) {
    
    ofVec2f frc;
    frc.set(0, 0);
    
    if (x < 0 || x > ofGetScreenWidth() || y < 0 || y > ofGetScreenHeight()) {
        return frc;
    }
    
    int xIndex = ceil (ofMap (x, 0, ofGetWidth(), 0, width));
    float yIndex = ceil (ofMap (y, 0, ofGetHeight(), 0, height));
    
    int index = (yIndex * width) + xIndex;
    
    frc.set(field[index].x * 0.01, field[index].y * 0.01);
    
    return frc;
    
}