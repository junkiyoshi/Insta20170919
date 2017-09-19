#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofEnableSmoothing();

	this->size = 30;
	bool flg = true;
	for (float y = -ofGetHeight(); y < ofGetHeight(); y += this->size + this->size / 2) {
		for (float x = -ofGetWidth(); x < ofGetWidth(); x += this->size * sqrt(3)) {
			ofVec3f location;
			if (flg) {
				location = ofVec3f(x, y, 0);
			} else {
				location = ofVec3f(ofVec3f(x + (this->size * sqrt(3) / 2), y, 0));
			}

			ofColor body_color(255, 0, 0);
			this->particles.push_back(new Particle(location, this->size, body_color));
		}
		flg = !flg;
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (Particle* p : this->particles) {
		float height = 300 * ofNoise(p->getLocation().x * 0.0025, p->getLocation().y * 0.0025, ofGetFrameNum() * 0.005);
		p->update(height);	
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	for (Particle* p : this->particles) {
		p->draw();
	}

	
	this->cam.end();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
