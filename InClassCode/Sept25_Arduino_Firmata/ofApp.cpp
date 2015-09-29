
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);

	ofBackground(255,0,130);
    
    potValue = "analog pin:";

    // the ttf or otf font in your data directory
	font.loadFont("franklinGothic.otf", 20);

    // replace the string below with the serial port for your Arduino board
    // you can get this from the Arduino application or via command line
    // for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices
    // windows this may be something like COM3, COM4, etc
    // linux can follow OSX directions will likely not have "tty." at start
	ard.connect("/dev/tty.usbmodem1451", 57600);
	
	ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
	bSetupArduino	= false;
}

//--------------------------------------------------------------
void ofApp::update(){

	updateArduino();

}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
	
	ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    
    bSetupArduino = true;
    
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    
    ard.sendDigitalPinMode(11, ARD_PWM);
    
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

//--------------------------------------------------------------
void ofApp::updateArduino(){

	ard.update();
	
	if (bSetupArduino) {
        // fade the led connected to pin D11
		ard.sendPwm(11, (int)(128 + 128 * sin(ofGetElapsedTimef())));   // pwm...
	}

}

//--------------------------------------------------------------
void ofApp::analogPinChanged(const int & pinNum) {
    potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(ard.getAnalog(pinNum));
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableAlphaBlending();
    ofSetColor(0, 0, 0, 127);
    ofRect(510, 15, 275, 150);
    ofDisableAlphaBlending();
    
    ofSetColor(255, 255, 255);
	if (!bSetupArduino){
		font.drawString("arduino not ready...\n", 515, 40);
	} else {
		font.drawString(potValue + "\n" +
						"\nsending pwm: " + ofToString((int)(128 + 128 * sin(ofGetElapsedTimef()))), 515, 40);
        
        ofSetColor(255, 255, 255);

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

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