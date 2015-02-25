#pragma once

#include "ofMain.h"
#include "follow.h"
#include "oscillate.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    follow head;
    vector<follow> snakePositions;
    
    ofVec2f snakePos;
    ofVec2f snakeMove;
    
    int minSpeed, maxSpeed;
    
    oscillate body;
    vector<oscillate> snake;
    
    ofVec2f pos;
    float rot;

		
};
