#pragma once

#include "ofMain.h"
#include "flowField.h"
#include "mesh.h"
#include "pointsMove.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseMoved(int x, int y );
    
    flowField flowField;
    meshed meshed;
    vector<pointsMove> points;
    vector<ofVec2f> pointPos;
    
};
