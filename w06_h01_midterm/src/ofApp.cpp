#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground (0);
    ofSetBackgroundAuto(false);
    for (int i = 0; i < 50; i ++) {
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
            
            ofVec2f diff = attractors[particles[i].goal].pos - particles[i].pos;
            float distance = diff.length();
            
            attraction.set(diff.getNormalized()* 0.1);
            
            particles[i].applyForce(attraction);
            particles[i].applyDamping(0.05);
            particles[i].update();
            
            if (distance < 30){
                particles[i].goal ++;
                if (particles[i].goal >= attractors.size()){
                    particles[i].goal = 0;
                }
            }
            
            if (particles[i].lifespan <= 0){
                particles.erase(particles.begin() + i);
            }
        }
    }
    
    
    for (int i = 0; i < attractors.size(); i ++){
        attractors[i].update();
    }
    
        if (particles.size() < 50) {
            ofVec2f pos;
            pos.set(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
            Particle particle(pos);
            particles.push_back(particle);
        }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0, 150);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i = 0; i < particles.size(); i ++){
        for (int j = 0; j < particles.size(); j++){
            ofVec2f particleDiff = particles[i].pos - particles[j].pos;
            float particleDistance = particleDiff.length();
            
            if (particleDistance < 100) {
                float mapCol = ofMap(particleDistance, 0, 100, 255, 0);
                ofSetColor(mapCol, 50);
                ofLine(particles[i].pos, particles[j].pos);
            }
        }
        particles[i].draw();
    }
    
    for (int i = 0; i < attractors.size(); i ++){
        attractors[i].draw();
        for (int j = 0; j <particles.size(); j++){
            ofVec2f attractDiff = attractors[i].pos - particles[j].pos;
            float attractDist = attractDiff.length();
            
            if (attractDist < 50) {
                ofSetColor(255, 0, 0);
                ofLine (attractors[i].pos, particles[j].pos);
            }
            
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofVec2f pos;
    pos.set(x,y);
    Attractor attractor(pos, attractors.size());
    attractors.push_back(attractor);
}

