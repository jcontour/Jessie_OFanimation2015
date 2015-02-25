//
//  follow.h
//  interp_click
//
//  Created by CHILAQUILES on 2/12/15.
//
//

#pragma once
#include "ofMain.h"


class follow {
public:
    
    void setup();
    void update(ofVec2f _dest);
    void draw();
    
    ofVec2f followPos;
    
    float followCol;


};