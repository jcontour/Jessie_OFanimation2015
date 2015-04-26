#pragma once

#include "ofMain.h"
#include "looker.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);

    looker look;
    vector<looker> lookers;
    
    ofVec3f pointAt;
    
    ofEasyCam cam;
		
};
