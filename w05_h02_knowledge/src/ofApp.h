#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "Attractor.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mouseReleased(int x, int y, int button);
        void keyPressed(int key);
    
    vector<Particle> particles;
    vector<Attractor> attractors;
    vector<Attractor> repulsors;
    
    bool shift;
    
		
};
