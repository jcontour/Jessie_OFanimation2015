#pragma once

#include "ofMain.h"
#include "particle.h"
#include "attractor.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	    void mouseReleased(int x, int y, int button);
    
    
    vector<Particle> particles;
    vector<Attractor> attractors;
    bool inCircle;
    int goal;
		
};
