#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetBackgroundAuto(false);
    ofBackground(ofColor::wheat);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetFrameRate(1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetColor(ofColor::lavender);
    ofTriangle(0, ofGetHeight(),
               ofGetWidth(), ofGetHeight(),
               ofGetWidth()/2, ofGetHeight()/3);
    
    ofSetLineWidth(3.0);
    ofNoFill();
    ofSetColor(ofColor::tomato);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2 - 120, 50);
    
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 22; j++) {
            ofPushMatrix();
            ofTranslate(i * 20, j * 20);
            ofTranslate(ofRandom(j),
                        ofRandom(j));
            ofRotate(ofRandom(j * -5, j * 5));

            ofRect(0, // x * distribution
                   0, // y * distribution
                   20,     // width
                   20);    // height
            ofPopMatrix();
        }
    }
    ofPopMatrix();

    //how variation
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
