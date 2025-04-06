/*
*   Base64cpp - Simple library to encode and decode base64 texts for C++ programs
*   base64cpp.cpp
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
    string out;
    vector<int> T(256,-1);
    for (int i = 0; i < 64; i++){
        T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;
    }
    
    int val=0, valb=-8;
    for (char c : input) {
        if (T[c] == -1){
            break;
        }
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0){
            out.push_back(char((val>>valb)&0xFF));
            valb -= 8;
        }
    }
    return out;
    
}