#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 320;
    camHeight = 240;
    
    // setup properties for our camera
    vidGrabber.setVerbose(true);
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    //allocate memory for our output image
    vidPixels.allocate(camWidth, camHeight, OF_PIXELS_RGB);
    //tell the texture how to allocate based on our pixel information
    vidTexture.allocate(vidPixels);

    //if you're on windows you may need to specify the OF framerate
}

//--------------------------------------------------------------
void ofApp::update(){
    //must update the video camera
    vidGrabber.update();
    
    //if we don't check for is frame new, then because our OF framerate
    //doesn't match our camera framerate, then the drawn columns look 
    //wide
    if(vidGrabber.isFrameNew()){
        //get a handle to the raw pixels from the camera
        ofPixelsRef pixelRef = vidGrabber.getPixelsRef();
        //make sure we loop around the width of the image
        column  = (column + 1) % camWidth;
        for (int i = 0; i < camHeight; i++) {
            vidPixels.setColor(column,
                               i,
                               pixelRef.getColor(column, i));
                                //swap column for 160 to change style of 
                                //slit scanning

        }
        //tell texture to update with our newest pixel data
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