/*
*   Base64cpp - Simple library to encode and decode base64 texts for C++ programs
*   test.cpp
*/

#include <iostream>
#include "base64cpp.h"


using namespace std;

int main(){
    cout << "Encoded - SGVsbG8gV29ybGQh" << endl;
    string output = b64_encode("Hello World!");
    cout << output << endl;
    cout << "Decoded - Hello World!" << endl;
    output = b64_decode("SGVsbG8gV29ybGQh");
    cout << output << endl;
    return 0;
}