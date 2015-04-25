//
//  mesh.cpp
//  w09_h02_interactiveMesh
//
//  Created by CHILAQUILES on 4/25/15.
//
//

#include "mesh.h"

void meshed::setup(){

    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

}

void meshed::update(vector<ofVec2f> points){
    
    if (points.size() > 2){
        
        ofVec3f thisPoint = points[points.size()-2];
        ofVec3f nextPoint = points[points.size()-1];
        
        direction = (nextPoint - thisPoint);
        
        float distance = direction.length();
        
        ofVec3f unitDirection = direction.normalized();
        
        ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
        ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
        
        thickness = ofMap(distance, 0, 60, 0, 30, true);
        
        leftPoint = thisPoint+toTheLeft*thickness;
        rightPoint = thisPoint+toTheRight*thickness;
        
        mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, 0));
        mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, 0));
    }
    
}

void meshed::draw(){
    
    ofSetColor(255);
    mesh.drawWireframe();
    
}