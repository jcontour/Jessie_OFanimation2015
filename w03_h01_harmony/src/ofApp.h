#pragma once

#include "ofMain.h"
#include "arc.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    //ofPath path;
    arc harmony;
    vector<arc> arcs;
		
};
