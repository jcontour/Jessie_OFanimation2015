#include "ofApp.h"

void ofApp::setup(){
    
    ofBackground(0);
    
}

void ofApp::update(){
    
    for (int i = 0; i < rockets.size(); i ++){
        rockets[i].update();
    }
    
    
}

void ofApp::draw(){
    
    for (int i = 0; i < rockets.size(); i ++){
        rockets[i].draw();
    }

}

void ofApp::mouseReleased(int x, int y, int button){

    ofVec2f mouse;
    mouse.set(x,y);
    rocket.setup(mouse);
    rockets.push_back(rocket);
    
}
