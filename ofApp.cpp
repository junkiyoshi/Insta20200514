#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {
	
	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int x = 120; x < 720; x += 240) {

		for (int y = 120; y < 720; y += 240) {

			ofPushMatrix();
			ofTranslate(x, y);

			auto noise_seed_deg = ofRandom(1000);
			auto noise_seed_radius = ofRandom(1000);

			vector<glm::vec2> vertices;
			for (int i = 0; i < 100; i++) {

				auto noise_deg = ofMap(ofNoise(noise_seed_deg, (ofGetFrameNum() + i) * 0.05), 0, 1, -10, 10);
				auto noise_radius = ofMap(ofNoise(noise_seed_radius, (ofGetFrameNum() + i) * 0.01), 0, 1, -120, 120);
				vertices.push_back(glm::vec2(noise_radius * cos(noise_deg * DEG_TO_RAD), noise_radius * sin(noise_deg * DEG_TO_RAD)));
			}

			for (int i = 0; i < 18; i++) {

				ofRotateZ(20);

				ofNoFill();
				ofBeginShape();
				ofVertices(vertices);
				ofEndShape();

				ofFill();
				ofDrawCircle(vertices.back(), 3);
				ofDrawCircle(vertices.front(), 3);
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}