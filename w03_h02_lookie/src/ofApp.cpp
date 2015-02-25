#include "ofApp.h"

void ofApp::setup(){
    
    ofBackground(55);

    for (int i = 1; i < 30; i++){
        for (int j = 1; j < 30; j++){
            looker.setup(i*20, j*20);
            lookers.push_back(looker);
        }
    }


}

void ofApp::update(){
    
    for (int i = 0; i < lookers.size(); i++){
        lookers[i].update(ofGetMouseX(), ofGetMouseY());
    }
}

void ofApp::draw(){
    
    for (int i = 0; i < lookers.size(); i++){
        lookers[i].draw();
    }
    

}