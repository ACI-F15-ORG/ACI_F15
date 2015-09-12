#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  // we use this fix issues when drawing overlapping objects
  // so that the order in front/behind is correct
    ofEnableDepthTest();
  // windows seemed to need this specified
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    // its better to call update here so that in future
    // position, velocity, etc can be calculated as 
    // elapsed time instead of per frame
    for (int i = 0; i < boxes.size(); i++) {
        boxes[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < boxes.size(); i++) {
        boxes[i].draw();
    }
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

    // using complex constructor and assigning initial 
    // values
    MyBox box = MyBox(ofVec3f(x, y, 0),
                      ofVec3f(ofRandom(-5, 5),
                              ofRandom(-5, 5),
                              ofRandom(-5, 5)),
                      ofVec3f(0));
    
    boxes.push_back(box);
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
