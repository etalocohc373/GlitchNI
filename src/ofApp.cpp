#include "ofApp.h"

#define WIDTH 640
#define HEIGHT 480

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0);
    ofSetWindowShape(WIDTH, HEIGHT);
    ofSetVerticalSync(true);
    ofSetCircleResolution(3);
    
    myFbo.allocate(WIDTH, HEIGHT);
    myGlitch.setup(&myFbo);
    shaderIndex = false;
    movie.loadMovie("movie.mp4");
    
    ofSetFrameRate(30);
    
    /*kinect.setup();
    kinect.setRegister(true);
    kinect.setMirror(true);
    kinect.addImageGenerator();
    kinect.addDepthGenerator();
    kinect.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(kinect.getImageGenerator());
    kinect.addUserGenerator();
    kinect.setMaxNumUsers(1);
    kinect.start();*/
    shaderSwitch = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    //kinect.update();
    /*movie.update();
    myFbo.begin();
    ofClear(0, 0, 0,255);
    //kinect.drawDepth(0, 0, WIDTH, HEIGHT);
    movie.draw(0, 0, WIDTH, HEIGHT);
    myFbo.end();*/
    
    //if (shaderSwitch){
        /*if (ofGetElapsedTimeMillis() % 1000 < 300)*/ myGlitch.setFx(OFXPOSTGLITCH_SHAKER, true);
        //else myGlitch.setFx(OFXPOSTGLITCH_SHAKER, false);
    //}else{
       // myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
    //}
}

//--------------------------------------------------------------
void ofApp::draw(){
    //kinect.drawDepth(0, 0, WIDTH, HEIGHT);
    
    myGlitch.generateFx();
    myFbo.draw(0, 0);
    
    //kinect.drawSkeletons(0, 0, WIDTH, HEIGHT);
}
//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            shaderSwitch = true;
            break;
            
        case 'p':
            movie.play();
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case ' ':
            shaderSwitch = false;
            break;
            
        default:
            break;
    }
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