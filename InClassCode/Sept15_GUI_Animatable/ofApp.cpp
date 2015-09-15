#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    point.reset();
    point.setDuration(2);
    point.setCurve(SWIFT_GOOGLE);
    
    gui.setup();
    gui.add(color.setup("backgroundColor",
                        ofColor::lemonChiffon,
                        ofColor(0,0),
                        ofColor(255, 255)));
}

//--------------------------------------------------------------
void ofApp::update(){
    // this returns how much time has passed since
    // the last frame rendered
    double dt = ofGetLastFrameTime();
    point.update(dt);

    // manage the queue of points
    if( point.hasFinishedAnimating() && !points.empty()) {
        point.animateTo(points.front());
        points.pop();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    // the multi-slider returns the proper color 
    // when called like this
    ofBackground(color);
    ofCircle(point.getCurrentPosition(), 20);
    
    // ofxgui doesn't have a show/hide toggle 
    // you'll need to build your own
    gui.draw();
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
// swap commenting here to change to single or
// queue of points.
//    point.animateTo(ofPoint(x, y, 0));
    points.push(ofPoint(x, y, 0));
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
