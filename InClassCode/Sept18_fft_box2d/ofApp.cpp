#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    
    box2d.init();
    // remember top left of our window is 0,0
    // so positive numbers will move our objects down
    box2d.setGravity(0, 20);
    box2d.createBounds();
    // normal box2d we would pass in frame delta-time
    // for time based animation
    box2d.setFPS(60);
    
    fftLive.setMirrorData(false);
    fftLive.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
    
    // the fft runs a much larger bin (frequency space)
    // we're asking for a simplified version
    float * audioData   = new float[8];
    fftLive.getFftPeakData(audioData, 8);
    
    for (int i = 0; i<8; i++) {
        // if intensity in the particular frequency space is 
        // high, then add a new circle to the physics world
        if( audioData[i] > .9) {
            circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
            circles.back().get()->setPhysics(3.0, 0.53, .1);
            circles.back().get()->setMassFromShape = true;
            circles.back().get()->setup(box2d.getWorld(),
                                        ofRandom(ofGetWidth()),
                                        0,
                                        10-i);
        }
    }
    
    fftLive.update();
    
    delete[] audioData;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // if you want to see the fft
    fftLive.draw();
    
    for (int i = 0; i<circles.size(); i++) {
        circles[i].get()->draw();
    }
    
    box2d.drawGround();
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
    circles.back().get()->setPhysics(3.0, 0.53, .1);
    circles.back().get()->setMassFromShape = true;
    circles.back().get()->setup(box2d.getWorld(), x, y, 10);
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
