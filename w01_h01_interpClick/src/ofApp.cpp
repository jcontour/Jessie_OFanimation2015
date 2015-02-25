#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    circle.setup(ofVec2f(10, 500), ofVec2f(ofGetWindowWidth() - 10, 500));
    
    for (int i = 0; i < 2; i++){
        lemming.setup();
        lemmings.push_back(lemming);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    loc+=0.01;
    
    circle.update(loc);
    
    lemmings[0].update(circle.pos);
    for (int i = 1; i < lemmings.size(); i++) {
        lemmings[i].update(lemmings[i-1].followPos);
        ofSetColor(255, 100);
        ofLine(lemmings[i].followPos, lemmings[i-1].followPos);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    circle.draw();
    
    for (int i = 0; i < 2; i++){
        lemmings[i].draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    float tempLoc = loc;
    loc = 1 - tempLoc;
    circle.updatePath(ofVec2f(x,y));
    

}
