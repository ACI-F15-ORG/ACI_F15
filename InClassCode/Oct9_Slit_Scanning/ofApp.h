#pragma once

#include "ofMain.h"

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
		
	//	the object that opens our camera	
    ofVideoGrabber  vidGrabber;
    int             camWidth, camHeight;
    // a drawable "fast" object
    ofTexture       vidTexture;
    // raw pixels that are assigned to the texture
    ofPixels        vidPixels;
    
    int             column = 0;
    
    
};
