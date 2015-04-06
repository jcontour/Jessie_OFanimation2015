#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    flowField.setup(ofGetWidth(), ofGetHeight(), 20.0);
    //flowField.setRandom(2.0);
    flowField.setNoise();
    
    for (int i = 0; i < 1000; i++) {
        Particle myParticle;
        myParticle.setup();
        particles.push_back(myParticle);
    }
    
    bDrawField = false;
    bDrawBackground = true;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].resetForces();
        
        //get the force of the flowfield at the particle position
        ofVec2f frc = flowField.getForceAt(particles[i].pos.x, particles[i].pos.y);
        
        //apply force to the particle
        particles[i].applyForce(frc);
        particles[i].applyDampingForce(0.01);
        particles[i].update();
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofSetColor(255, 0, 0);
    
    if(bDrawBackground) ofBackground(0);
    if (bDrawField) flowField.draw();
    
    ofSetColor(255);
    for (int i = 0; i < particles.size(); i++){
        for (int j = 0; j < particles.size(); j++){
            ofVec2f particlediff = particles[i].pos - particles[j].pos;
            float diff = particlediff.length();
            
            float col = ofMap(diff, 0, 50, 255, 50);
            
            if (diff < 50) {
                ofSetColor(col);
                ofLine (particles[i].pos, particles[j].pos);
            }
        }
        //particles[i].draw();
    }
    
    stringstream buf;
    
    buf << "Press 'f' to toggle flowfield draw" << endl <<
    "Press 'b' to toggle background draw" << endl;
    
    ofDrawBitmapString(buf.str(), 20, 20);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'f' | 'F':
            bDrawField = !bDrawField;
            break;
        case 'b' | 'B' :
            bDrawBackground = !bDrawBackground;
            break;
            
        default:
            break;
    }

}


