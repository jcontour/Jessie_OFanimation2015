#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    //ofSetColor(255);
    //ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    for (int i = 0; i < 1000; i++){
        
        float gausVel = ofxGaussian();
        float stanDevVel = 2;
        float meanVel = 10;
        vel = (stanDevVel * gausVel) + meanVel;
        
            ball.setup(vel);
            balls.push_back(ball);
        
    }
    

}

//--------------------------------------------------------------
void ofApp::update(){

    
    for (int i = 0; i < balls.size(); i++){
        
        balls[i].update();
    
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i = 0; i < balls.size(); i++){
        balls[i].draw(i);
    }
    
}

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
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
