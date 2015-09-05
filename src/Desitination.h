//
//  Desitination.h
//  mtPerformanceManager
//
//  Created by sonir on 5/29/15.
//
//

#ifndef __mtPerformanceManager__Desitination__
#define __mtPerformanceManager__Desitination__

#include <stdio.h>
#include "ofxOsc.h"

class Destination {
    
    public:
        Destination(string ip, int port){
            
            sender.setup(ip, port);
            
        };
    
        void send(string adr,int i_param){
            
            ofxOscMessage m;
            m.setAddress(adr);
            m.addIntArg(i_param);
            sender.sendMessage(m);
            
        }

        void send(string adr,float f_param){

            ofxOscMessage m;
            m.setAddress(adr);
            m.addFloatArg(f_param);
            sender.sendMessage(m);
            
        }

        void send(string adr,int i_param, float f_param){
            
            ofxOscMessage m;
            m.setAddress(adr);
            m.addIntArg(i_param);            
            m.addFloatArg(f_param);
            sender.sendMessage(m);
            
        }

    void send(string adr,int i_param1, int i_param2){
        
        ofxOscMessage m;
        m.setAddress(adr);
        m.addIntArg(i_param1);
        m.addIntArg(i_param2);
        sender.sendMessage(m);
        
    }
    
        ofxOscSender sender;
    
    
};


#endif /* defined(__mtPerformanceManager__Desitination__) */
