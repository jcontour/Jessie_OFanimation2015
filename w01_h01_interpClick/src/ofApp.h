#pragma once

#include "ofMain.h"
#include "customCircle.h"
#include "follow.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseReleased(int x, int y, int button);
    
    customCircle circle;
    
    follow lemming;
    vector<follow> lemmings;
    
private:
    float loc;
    float speed;
		
};
