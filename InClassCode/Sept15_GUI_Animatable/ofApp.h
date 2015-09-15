#pragma once

#include "ofMain.h"
#include "ofxAnimatable.h"
#include "ofxAnimatableOfPoint.h"
#include "ofxGui.h"

// don't forget to use the project generator to
// add the addons. GUI is shipped with OF. 
// Animatable you'll need to download.

// there is also animatable float and color 

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	// this was to test
    ofxAnimatableOfPoint point;

    // build a queue of locations we can animate to
    queue<ofPoint> points;
    
    // both objects from ofxGUI
    ofxPanel gui;
    ofxColorSlider color;
};








