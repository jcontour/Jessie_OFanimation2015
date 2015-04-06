#pragma once

#include "ofMain.h"
#include "flowField.h"
#include "Particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

    
    flowField flowField;
    vector <Particle> particles;
    bool bDrawField;
    bool bDrawBackground;
		
};
