#include "ofApp.h"

void ofApp::setup(){
    
    ofBackground(55);
    
    pointAt.setup();
    

    for (int x = -5; x < 5; x++){
        for (int y = -5; y < 5; y++){
            for(int z = -5; z < 5; z++){
                look.setup(x*50,y*50,z*50);
                lookers.push_back(look);
            }
        }
    }
    
    pointPos.set(0,0,0);

}

void ofApp::update(){
    
    pointAt.update(pointPos);

    for (int i = 0; i < lookers.size(); i++){
        lookers[i].update(pointPos);
    }
    
}

void ofApp::draw(){
    
    cam.begin();
    
    pointAt.draw();
    for (int i = 0; i < lookers.size(); i++){
        lookers[i].draw();
    }
    
    cam.end();
    

}

void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'q' | 'Q':
            pointPos.x += 5;
            break;
        case 'a' | 'A' :
            pointPos.x -= 5;
            break;
        case 'w' | 'W' :
            pointPos.y += 5;
            break;
        case 's' | 'S' :
            pointPos.y -= 5;
            break;
        case 'e' | 'E' :
            pointPos.z += 5;
            break;
        case 'd' | 'D' :
            pointPos.z -= 5;
            break;
        default:
            break;
    }
    
}
