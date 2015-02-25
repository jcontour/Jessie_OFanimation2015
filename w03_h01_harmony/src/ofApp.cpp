#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);

    ofSetBackgroundAuto(true);
    
    for (int i = 0; i < 5; i++) {
        harmony.setup(i * 50, 0, 45);
        arcs.push_back(harmony);
    }
}

//--------------------------------------------------------------
void ofApp::update(){


    for (int i = 0; i < arcs.size(); i++) {
        float sinoftime = sin(ofGetElapsedTimef()*i);
        float rot = ofMap(sinoftime, -1, 1, 0, i);
        arcs[i].update(rot);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i = 0; i < arcs.size(); i++) {
        arcs[i].draw();
    }
    
}
