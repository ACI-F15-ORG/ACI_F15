#pragma once

#include "ofMain.h"

//this example requires ofxOpenCV, ofxMSAInteractiveObject, and the included ofxColorPicker


#include "ofxOpenCv.h"
#include "ofxColorPicker.h"

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
		
    ofVideoGrabber      vidGrabber;
    
    ofxCvColorImage     colorImg;
    ofxCvGrayscaleImage hueImg, satImg, valImg, finalImg;
    
    ofxCvContourFinder  contourFinder;
    ofxCvHaarFinder     haarFinder;
    
    ofxColorPicker      colorPicker;
    
    int                 threshold, vidWidth, vidHeight;
    
};
