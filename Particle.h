#pragma once

#include "ofMain.h"

class Particle {
public:
	Particle();
	Particle(ofVec3f location, float radius, ofColor c);
	~Particle();

	void update(float height);
	void draw();

	ofVec3f getLocation();

private:
	float radius;
	float height;
	ofVec3f location;
	ofColor body_color;
};