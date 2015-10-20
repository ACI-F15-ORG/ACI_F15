#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //this is especially for windows
    ofSetFrameRate(60);
    
    threshold = 10;
    vidWidth = 320;
    vidHeight = 240;
    
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(vidWidth, vidHeight);
    
    haarFinder.setup("haarcascade_frontalface_default.xml");

    /////start part two//////
    colorImg.allocate(vidWidth, vidHeight);
    hueImg.allocate(vidWidth, vidHeight);
    satImg.allocate(vidWidth, vidHeight);
    valImg.allocate(vidWidth, vidHeight);
    finalImg.allocate(vidWidth, vidHeight);
    
    colorPicker.setSize(60 + vidWidth *2,20, 150, 240);
    /////end part two/////
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(ofColor::whiteSmoke);
    
    vidGrabber.update();
    
    /////start part two//////
    colorPicker.update();
    /////end part two/////
    
    if (vidGrabber.isFrameNew()) {
        haarFinder.findHaarObjects(vidGrabber.getPixelsRef());
        
        /////start part two//////
        colorImg.setFromPixels(vidGrabber.getPixels(), vidWidth, vidHeight);
        
        colorImg.convertRgbToHsv();
        colorImg.convertToGrayscalePlanarImages(hueImg, satImg, valImg);
        
        //because images are passed in above
        hueImg.flagImageChanged();
        satImg.flagImageChanged();
        valImg.flagImageChanged();
        
        int hue = colorPicker.getColorAngle() * 255;
        
        for (int i = 0; i < vidWidth*vidHeight; i++) {
            if( ofInRange(hueImg.getPixels()[i], hue - threshold, hue + threshold)) {
                finalImg.getPixels()[i] = 255;
            } else {
                finalImg.getPixels()[i] = 0;
            }
        }
     
        finalImg.flagImageChanged();
      
        contourFinder.findContours(finalImg, //image
                                   100, //min pixel size
                                   (vidWidth*vidHeight)/2, //max pixel size
                                   10, //max blobs to find
                                   true); //find holes
        /////end part two/////
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(ofColor::white);
    
    ofNoFill();
    
    ofPushMatrix();
    ofTranslate(20, 20);
    vidGrabber.draw(0, 0);
    
    for (int i = 0; i < haarFinder.blobs.size(); i++) {
        ofRect(haarFinder.blobs[i].boundingRect);
    }
    ofPopMatrix();

    /////start part two//////
    ofPushMatrix();
    ofTranslate(40+vidWidth, 20);
    finalImg.draw(0,0);
    ofColor c = colorPicker.getColor();
    for (int i = 0; i < contourFinder.blobs.size(); i++) {
        contourFinder.blobs[i].draw(0,0);
    }
    ofPopMatrix();

    colorPicker.draw();
    ofSetColor(ofColor::black);
    ofDrawBitmapString("threshold\n"+ofToString(threshold), 240 + vidWidth*2, 40);
    
    ofSetColor(ofColor::white);
    
    ofTranslate(20, 40+vidHeight);
    hueImg.draw(0, 0);
    
    ofTranslate(20+vidWidth, 0);
    satImg.draw(0, 0);
    
    ofTranslate(20+vidWidth, 0);
    valImg.draw(0, 0);
    /////end part two/////
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    /////start part two//////
    if (key == 'q') {
        if (threshold < 255)
            threshold += 1;
    } else if (key == 'a') {
        if (threshold > 0)
            threshold -= 1;
    }
    /////end part two/////
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
