//
//  mesh.h
//  w09_h02_interactiveMesh
//
//  Created by CHILAQUILES on 4/25/15.
//
//

#pragma once
#include "ofMain.h"

class meshed{
public:
    void setup();
    void update(vector<ofVec2f> points);
    void draw();
    
    ofVec3f getPosition(ofVec2f point);
    
    ofMesh mesh;
    
    ofVec3f direction;
    float thickness;
    ofVec3f leftPoint;
    ofVec3f rightPoint;
    
    
};