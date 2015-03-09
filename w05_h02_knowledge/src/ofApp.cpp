#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    
    for (int y = 0; y < ofGetWidth(); y+=25) {
        for (int x = 0; x < ofGetWidth(); x+=25) {
            ofVec2f pos;
            pos.set(x, y);
            Particle particle(pos);
            particles.push_back(particle);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //cout << shift;
    
    for (int i = 0; i < particles.size(); i++) {
        particles[i].resetForces();
        
        for (int j = 0; j < attractors.size(); j++){
            ofVec2f attraction;
            
            ofVec2f diff = attractors[j].rot - particles[i].pos;
        
            float dist = diff.length();
        
            //if (dist < 200) {
                attraction.set(diff.getNormalized()* 0.05);
            //}
        
            particles[i].applyForce(attraction);
        }
        
        for (int k = 0; k < repulsors.size(); k ++){
            ofVec2f repulsion;
            
            ofVec2f diff = repulsors[k].rot - particles[i].pos;
            
            float dist = diff.length();
            
            //if (dist < 200) {
                repulsion.set(diff.getNormalized()* -0.05);
            //}
            
            particles[i].applyForce(repulsion);
        }
        
        particles[i].applyDamping(0.01);
        particles[i].checkEdges();
        particles[i].update();
    }
    
    for (int i = 0; i < attractors.size(); i ++){
        attractors[i].update();
    }
    
    for (int i = 0; i < repulsors.size(); i ++){
        repulsors[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
    for (int j = 0; j < attractors.size(); j++){
        ofColor attCol;
        attCol.set(255,0,0);
        attractors[j].draw(attCol);
    }
    for (int k = 0; k < repulsors.size(); k++){
        ofColor repCol;
        repCol.set(0,0,255);
        repulsors[k].draw(repCol);
    }


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    ofVec2f pos;
    pos.set(x,y);
    
    if (shift) {
        Attractor repulsor(pos);
        repulsors.push_back(repulsor);
        shift = false;
    } else {
        Attractor attractor(pos);
        attractors.push_back(attractor);
        shift = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'q'){
        shift = true;
    }
}

