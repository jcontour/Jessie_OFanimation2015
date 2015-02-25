#pragma once

#include "ofMain.h"
#include "landscape.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    landscape land;

};
