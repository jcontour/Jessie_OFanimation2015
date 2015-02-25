#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    land.setup(ofVec2f(0,10));
    
    ofSetBackgroundAuto(true);
    ofSetVerticalSync(true);

}

//--------------------------------------------------------------
void ofApp::update(){

    land.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    land.draw();


}