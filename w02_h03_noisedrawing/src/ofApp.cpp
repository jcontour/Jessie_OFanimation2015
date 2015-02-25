#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetColor(255);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    stanDev = 30;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    float numX = ofxGaussian();
    float numY = ofxGaussian();
    
    float meanX = ofGetMouseX();
    float meanY = ofGetMouseY();
    x = (stanDev * numX) + meanX;
    y = (stanDev * numY) + meanY;
    
    ofVec2f p1 = ofVec2f(x,y);
    ofVec2f p2 = ofVec2f(ofGetMouseX(), ofGetMouseY());
    
    dist = p1.distance( p2 );
    radius = ofMap(dist, 0, stanDev*2, 10, 0, true);
    
    if (stanDev > 100){
        stanDev = 100;
    } else if (stanDev < 0) {
        stanDev = 0;
    };

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofCircle(x, y, radius);
    
}


//--------------------------------------------------------------

bool haveNextNextGaussian = false;
float nextNextGaussian;

float ofApp::ofxGaussian() {
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        
        return v1 * multiplier;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    
    if (key == 'r'){
        ofSetColor(255,0,0);
    } else if (key == 'g'){
        ofSetColor(0, 255, 0);
    } else if (key == 'b'){
        ofSetColor(0,0,255);
    } else if (key == 'p'){
        stanDev += 10;
    } else if (key == 'o'){
        stanDev -= 10;
    };

}

