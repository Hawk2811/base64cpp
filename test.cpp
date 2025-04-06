/*
*   Base64cpp - Simple library to encode and decode base64 texts for C++ programs
*   test.cpp
*   Created by Hawk2811
*/

#include <iostream>
#include "base64cpp.h"


using namespace std;

int main(){
    cout << "Encoded" << endl;
    string output = b64_encode("Hello World!");
    cout << output << endl;
    output = b64_decode("SGVsbG8gV29ybGQh");
    cout << output << endl;
    return 0;
}