#include "slOscManager.h"
using namespace std;

slOscManager::slOscManager(){
    cout << "listening for osc messages on port " << RECEIVE_PORT << "\n";
    receiver.setup(RECEIVE_PORT);
    

    
}

void slOscManager::setup(){
    
    
    
}

slOscManager::slOscManager(int port){
    cout << "listening for osc messages on port " << port << "\n";
    receiver.setup(port);
    
}


void slOscManager::fireMessage(ofxOscMessage *m){
    
    if(m->getAddress() == "/test1"){
        
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(test1, fnum);
    }
    else if(m->getAddress() == "/test2"){
        
    }
    else{
        // unrecognized message: display on the bottom of the screen
        string msg_string;
        msg_string = m->getAddress();
        msg_string += ": ";
        for(int i = 0; i < m->getNumArgs(); i++){
            // get the argument type
            msg_string += m->getArgTypeName(i);
            msg_string += ":";
            // display the argument - make sure we get the right type
            if(m->getArgType(i) == OFXOSC_TYPE_INT32){
                msg_string += ofToString(m->getArgAsInt32(i));
            }
            else if(m->getArgType(i) == OFXOSC_TYPE_FLOAT){
                msg_string += ofToString(m->getArgAsFloat(i));
            }
            else if(m->getArgType(i) == OFXOSC_TYPE_STRING){
                msg_string += m->getArgAsString(i);
            }
            else{
                msg_string += "unknown";
            }
        }
        // add to the list of strings to display
        msg_strings[current_msg_string] = msg_string;
        timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
        current_msg_string = (current_msg_string + 1) % NUM_MSG_STRINGS;
        // clear the next line
        msg_strings[current_msg_string] = "";
    }
    
}


void slOscManager::update(){
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        fireMessage(&m);

        
    }
    
    
}