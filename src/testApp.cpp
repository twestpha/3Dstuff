#include "testApp.h"
#include <vector>
#include <random>
#include <time.h>
#include "../Matrix.h"
#include "../Camera.h"
#include "../Vertex.h"
#include "../Face.h"

Camera c(-5.0,0,0,0,0,0,1.57);
Vertex q(0, 1, -4);
Vertex r(0, 1,  4);
Vertex s(4, 1,  4);
Face f(q, r, s, 200, 200, 200);
Vertex q1(0, 1, -4);
Vertex r1(4, 1,  4);
Vertex s1(4, 1, -4);
Face k(q1, r1, s1, 150, 150, 150);

//--------------------------------------------------------------
void testApp::setup(){
	srand (time(NULL));
	ofSetFrameRate(60);
	ofDisableAntiAliasing();
	ofBackground(45,45,45);
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	f.draw(c);
	k.draw(c);
	ofSetColor(200,200,200);
	ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == 'a'){
		c.z -= 1;
	}
	
	if (key == 'd'){
		c.z += 1;
	}

	if(key == 'w'){
		c.x += 1;
	}

	if(key == 's'){
		c.x -= 1;
	}

	if(key == 'q'){
		c.y -= 1;
	}

	if(key == 'e'){
		c.y -= 1;
	}

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}