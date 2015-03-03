#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    move.setup(ofGetMouseX(),ofGetMouseY());
    
    grav.set(0,0.5);
    
    isthrown = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    move.resetForces();
    move.force(grav);
    move.applyDamping(0.05);
    move.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    move.draw();
    
    if (ofGetMousePressed()) {
        ofLine(throwBegin.x, throwBegin.y, ofGetMouseX(), ofGetMouseY());
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if (!isthrown) {
        throwBegin.set(ofGetMouseX(), ofGetMouseY());
        isthrown = true;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    move.pos.set(ofGetMouseX(), ofGetMouseY());
    ofVec2f throwVec;
    
    throwVec.x = ofGetMouseX() - throwBegin.x;
    throwVec.y = ofGetMouseY() - throwBegin.y;
    
    move.vel = throwVec*0.1;
    isthrown = false;
    
}