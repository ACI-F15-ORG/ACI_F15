#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 320;
    camHeight = 240;
    
    vidGrabber.setVerbose(true);
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    vidPixels.allocate(camWidth, camHeight, OF_PIXELS_RGB);
    vidTexture.allocate(vidPixels);
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    if(vidGrabber.isFrameNew()){
        ofPixelsRef pixelRef = vidGrabber.getPixelsRef();
        column  = (column + 1) % camWidth;
        for (int i = 0; i < camHeight; i++) {
            vidPixels.setColor(column,
                               i,
                               pixelRef.getColor(column, i));
        }
        vidTexture.loadData(vidPixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::white);
    vidGrabber.draw(20, 20);
    
    vidTexture.draw(40+camWidth, 20);
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

//for (int i = 0; i < camHeight; i++) {
//    vidPixels.setColor(column,
//                       i,
//                       pixelRef.getColor(160, i));
//}