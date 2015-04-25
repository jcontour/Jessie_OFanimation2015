#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    flowField.setup(ofGetWidth(), ofGetHeight(), 20.0);
    flowField.setNoise();
    meshed.setup();

}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < points.size(); i++){
        
        points[i].resetForces();
        
        //get the force of the flowfield at the particle position
        ofVec2f frc = flowField.getForceAt(points[i].pos.x, points[i].pos.y);
        
        //apply force to the particle
        points[i].applyForce(frc);
        points[i].applyDampingForce(0.01);
        points[i].update();
        pointPos.push_back(points[i].pos);
    }
    
    meshed.update(pointPos);

}

//--------------------------------------------------------------
void ofApp::draw(){

    flowField.draw();
    meshed.draw();
    for (int i = 0; i < points.size(); i++){
        points[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    pointsMove point;
    point.setup(x, y);
    points.push_back(point);

}
