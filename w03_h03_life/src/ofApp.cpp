#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(100);
    
    for (int i = 0; i < 10; i++){
        head.setup();
        snakePositions.push_back(head);
    }
    
    for (int i = 0; i < snakePositions.size()-1; i++){
        body.setup();
        snake.push_back(body);
    }
    
    snakePos.x = 0;
    snakePos.y = 0;
    
    minSpeed = 1;
    maxSpeed = 2;
    
    snakeMove.x = ofRandom(minSpeed, maxSpeed);
    snakeMove.y = ofRandom(minSpeed, maxSpeed);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (snakePos.x > ofGetWindowWidth()){
        snakeMove.x = -ofRandom(minSpeed, maxSpeed);
    };
    if (snakePos.x < 0){
        snakeMove.x = ofRandom(minSpeed, maxSpeed);
    };
    if (snakePos.y > ofGetWindowHeight()){
        snakeMove.y = -ofRandom(minSpeed, maxSpeed);
    };
    if (snakePos.y < 0){
        snakeMove.y = ofRandom(minSpeed, maxSpeed);
    };
    
    snakePositions[0].update(snakePos);
    
    //follow the circle in front of them
    for (int i = 1; i < snakePositions.size(); i++) {
        snakePositions[i].update(snakePositions[i-1].pos);
    };
    
    //update head position
    snakePos.x += snakeMove.x;
    snakePos.y += snakeMove.y;
    
    
    //update oscillating points
    for (int i = 0; i < snake.size()-1; i++){
    snake[i].update(8-i);
    
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    for (int i = 0; i < 5; i++){
//        snakePositions[i].draw(10 -i);
//    }
    
    snakePositions[0].draw(snakePositions.size());
    
    for (int i = 0; i < snake.size(); i ++){
        //finding direction of movement
        ofVec2f diff;
        diff = snakePositions[i + 1].pos - snakePositions[i].pos;
        rot = atan2(diff.y, diff.x);
        rot = ofRadToDeg(rot);
        
        ofPushMatrix();
        ofTranslate(snakePositions[i+1].pos);
        ofRotate(rot);
        snake[i].draw((snakePositions.size()-1)-i);
        ofPopMatrix();
    }
    
    //how to draw line between oscillating points?
    //how to make tapering line based on radius of each point?
    
}

//--------------------------------------------------------------
