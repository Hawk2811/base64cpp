/*
*   Base64cpp - Simple library to encode and decode base64 texts for C++ programs
*   base64cpp.cpp
*/


#include "base64cpp.h"


using namespace std;

string b64_encode(string input){
    string out; //This will hold the resulting Base64 encoded string.
    int val = 0, valb = -6; //The Variable "val" is used to accumulate the bits of the input characters.
    //Variable "valb" keeps track of how many bits are currently in "val".
    for (char c : input){
        /*
        * For each character "c" in the input string, it shifts val left by 8 bits and adds the ASCII value of "c".
        * It then increases "valb" by 8 (the number of bits added).
        * While there are at least 6 bits in "val", it extracts the top 6 bits and appends the corresponding Base64 character to "out".
        */
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0){
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
            valb -= 6;
        }
    }
    if (valb>-6) {
        //If there are still bits left in "val" that haven't been encoded (i.e., "valb" is greater than -6), it processes those bits and appends the corresponding Base64 character.
        out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
    }
    while (out.size()%4){
        out.push_back('=');
    } //Base64 encoding requires the output to be a multiple of 4 characters. If the encoded string is not, it appends "=" characters as padding.
    return out;
    
    
}

string b64_decode(string input){
    string out; //out: This will hold the resulting decoded string.
    vector<int> T(256,-1);//T: A lookup table initialized to -1 for all 256 ASCII characters.
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