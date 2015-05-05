#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    for (int i = 0; i < 15; i++){
        lilguy.setup(45 + 65 * i);
        creatures.push_back(lilguy);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < creatures.size(); i++){
        creatures[i].update();
    
        if (creatures[i].touched == true) {
            creatures[i+1].halfRed();
            creatures[i-1].halfRed();
            creatures[i+2].quarterRed();
            creatures[i-2].quarterRed();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < creatures.size(); i++){
        creatures[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    for (int i = 0; i < creatures.size(); i ++) {
        ofVec2f mouse;
        mouse.set(x, y);
        ofVec2f ball;
        ball.set(creatures[i].pos);
        
        ofVec2f distVec = ball - mouse;
        float dist = distVec.length();
        
        
        if (dist < 30) {
                creatures[i].touched = true;
        }
    }
}

