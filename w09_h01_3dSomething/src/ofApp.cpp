#include "ofApp.h"

void ofApp::setup(){
    
    ofBackground(55);
    
    for (int x = -3; x < 3; x++){
        for (int y = -3; y < 3; y++){
            for(int z = -3; z < 3; z++){
                look.setup(x*60,y*60,z*60);
                lookers.push_back(look);
            }
        }
    }
    
    pointAt.set(0,0,0);

}

void ofApp::update(){
    
    for (int i = 0; i < lookers.size(); i++){
        lookers[i].update(pointAt);
    }
    
}

void ofApp::draw(){
    
    cam.begin();
    
    ofDrawAxis(100);
    
    ofSetColor(255, 0, 0);
    ofDrawSphere(pointAt, 5);
    
    for (int i = 0; i < lookers.size(); i++){
        lookers[i].draw();
    }
    
    cam.end();
    

}

void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'q' | 'Q':
            pointAt.x += 5;
            break;
        case 'a' | 'A' :
            pointAt.x -= 5;
            break;
        case 'w' | 'W' :
            pointAt.y += 5;
            break;
        case 's' | 'S' :
            pointAt.y -= 5;
            break;
        case 'e' | 'E' :
            pointAt.z += 5;
            break;
        case 'd' | 'D' :
            pointAt.z -= 5;
            break;
        default:
            break;
    }
    
}
