#pragma once

#include "ofMain.h"
#include "creature.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);

    creature lilguy;
    
    vector<creature> creatures;
		
};
