#pragma once

#include "ofMain.h"
#include "rocket.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        void mouseReleased(int x, int y, int button);

        
//    Rocket rocket;
    vector<Rocket> rockets;

};
