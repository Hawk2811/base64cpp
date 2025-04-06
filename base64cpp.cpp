/*
*   Base64cpp - Simple library to encode and decode base64 texts for C++ programs
*   base64cpp.cpp
*   Created by Hawk2811
*/


#include "base64cpp.h"


using namespace std;

string b64_encode(string input){
    string out;
    int val = 0, valb = -6;
    for (char c : input){
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0){
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
            valb -= 6;
        }
    }
    if (valb>-6) {
        out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
    }
    while (out.size()%4){
        out.push_back('=');
    }
    return out;
    
    
}

string b64_decode(string input){

}