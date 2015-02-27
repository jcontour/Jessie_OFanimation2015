#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    move.setup(ofGetMouseX(),ofGetMouseY());
    
    grav.set(0,0.2);
    
    isthrown = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (isthrown){
        move.force(grav + throwVec);
        move.applyDamping(0.02);
    } else {
        move.setup(ofGetMouseX(),ofGetMouseY());
        move.resetForces();
    }
    
    move.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    move.draw();
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    move.pos.set(ofGetMouseX(), ofGetMouseY());
    
    isthrown = false;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    prevPos.set(ofGetPreviousMouseX(), ofGetPreviousMouseY());
    releasePos.set(ofGetMouseX(), ofGetMouseY());
    ofLine(prevPos, releasePos);
    throwVec = prevPos - releasePos;

    isthrown = true;
}
