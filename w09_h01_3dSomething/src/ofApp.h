#pragma once

#include "ofMain.h"
#include "looker.h"
#include "target.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);

    looker look;
    vector<looker> lookers;
    
    target pointAt;
    ofVec3f pointPos;
    
    ofEasyCam cam;
		
};
