//
//  MyBox.cpp
//  gilgamesh_and_floods
//
//  Created by Shawn Lawson on 9/11/15.
//
//

#include "MyBox.h"

MyBox::MyBox()
{
    position = ofVec3f(ofGetWidth()/2,
                       ofGetHeight()/2,
                       0);
    
    velocity = ofVec3f(ofRandom(-5, 5),
                       ofRandom(-5, 5),
                       ofRandom(-5, 5));
    
    acceleration = ofVec3f(0);
    rotationAngle = ofVec3f(ofRandomf(), ofRandomf(), ofRandomf());
    rotationSpeed = ofRandom(10);
    
    mesh = ofMesh::box(100, 100, 100, 1, 1, 1);
}

MyBox::MyBox( ofVec3f startPosition,
              ofVec3f startVelocity,
              ofVec3f startAcceleration){
    
    position = startPosition;
    velocity = startVelocity;
    acceleration = startAcceleration;
    
    rotationAngle = ofVec3f(ofRandomf(), ofRandomf(), ofRandomf());
    rotationSpeed = ofRandom(10);
    
    mesh = ofMesh::box(100, 100, 100, 1, 1, 1);
}

void MyBox::update()
{
    velocity += acceleration;
    velocity.limit(40);
    position += velocity;
}

void MyBox::draw()
{
    ofPushMatrix();
    
    ofTranslate(position);
    ofRotate(ofGetFrameNum(), .1, .3, .7);
    
    ofSetColor(ofColor::orchid);
    mesh.draw();
    ofSetColor(ofColor::limeGreen);
    mesh.drawWireframe();
    
    ofPopMatrix();
}











