#pragma once
#define RECEIVE_PORT 57110
#define NUM_MSG_STRINGS 20


#include <iostream>
#include "ofMain.h"
#include "ofxOsc.h"
#include "Desitination.h"


class slOscManager {
    
public:
    slOscManager();
    slOscManager(int port);
    virtual void setup();
    virtual void fireMessage(ofxOscMessage *m);
    void update();
    
    ofxOscReceiver receiver;
    int current_msg_string;
    string msg_strings[NUM_MSG_STRINGS];
    float timers[NUM_MSG_STRINGS];
    
    //Event Invoking
    ofEvent<float> test1; //Add your own event and invole it in receiveMessage


};

//////

// Add event listenner in ofApp as follows,

// in ofApp.h :: void test1(float &val);
// in setup() :: ofAddListener(osc.test1, this, &ofApp::test1);

//Event invoking code  in oscManager:
// ofNotifyEvent(test1, fnum);

//////