#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground (0);
    for (int i = 0; i < 100; i ++) {
        ofVec2f pos;
        pos.set(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
        Particle particle(pos);
        particles.push_back(particle);
    }
    
    inCircle = false;
    goal = 0;

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (attractors.size() > 0){
    for (int i = 0; i < particles.size(); i++) {
        particles[i].resetForces();
        
        ofVec2f attraction ;
        attraction.set(0,0);
        
        ofVec2f diff = attractors[goal].pos - particles[i].pos;
        float distance = diff.length();
        
        attraction.set(diff.getNormalized()* 0.1);
        
        particles[i].applyForce(attraction);
        particles[i].applyDamping(0.05);
        particles[i].update();
        
        if (distance < 5){
            goal ++;
            if (goal > attractors.size()){
                goal = 0;
            }
        }
    }
    }
    
    
    for (int i = 0; i < attractors.size(); i ++){
        attractors[i].update();
    }
    
//    if (particles.size() < 100) {
//        ofVec2f pos;
//        pos.set(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
//        Particle particle(pos);
//        particles.push_back(particle);
//    }
    
}
    

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < particles.size(); i ++){
        particles[i].draw();
    }
    for (int i = 0; i < attractors.size(); i ++){
        attractors[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofVec2f pos;
    pos.set(x,y);
    Attractor attractor(pos);
    attractors.push_back(attractor);
}

