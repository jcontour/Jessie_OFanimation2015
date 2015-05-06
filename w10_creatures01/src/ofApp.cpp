#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    for (int i = 0; i < 15; i++){
        ball.setup(45 + 65 * i);
        creatures.push_back(ball);
    }
    
    sinceLastTrigger = 0;
    randomLengthOfTime = int(ofRandom(180, 300));

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < creatures.size(); i++){
        creatures[i].update();
        
        
        if (creatures[i].movingUp && creatures[i].triggerId == 1) {
            creatures[i+1].trigger(2);
            creatures[i-1].trigger(2);
            creatures[i+2].trigger(3);
            creatures[i-2].trigger(3);
        }
        
    }
    if (sinceLastTrigger < randomLengthOfTime) {
        sinceLastTrigger++;
    } else {
        creatures[int(ofRandom(0, 16))].trigger(1);
        sinceLastTrigger = 0;
        randomLengthOfTime = int(ofRandom(100, 200));
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
            creatures[i].trigger(1);
            sinceLastTrigger = 0;
            randomLengthOfTime = int(ofRandom(300, 500));
        }
    }
    
    
}

