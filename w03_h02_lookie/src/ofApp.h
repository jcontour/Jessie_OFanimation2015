#pragma once

#include "ofMain.h"
#include "look.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    look looker;
    vector<look> lookers;
		
};
