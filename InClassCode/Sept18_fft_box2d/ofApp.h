#pragma once

#include "ofMain.h"

// don't forget to use the project generator to these in
// Jalupy's fft that we converted back to OF 8.3 compatible
#include "ofxFFTLive.h"
// Vanderlin's box2d
#include "ofxBox2d.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxFFTLive fftLive;

    ofxBox2d box2d;
    // sneaky pointer that references the objects inside the
    // box2d world
    vector<shared_ptr<ofxBox2dCircle> > circles;
   
};
