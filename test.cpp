#include <iostream>
#include "base64cpp.h"


using namespace std;

int main(){
    cout << "Message is 'Hello World'" << endl;
    cout << "Encoded" << endl;
    string output = b64_encode("Hello World!");
    cout << output << endl;
    return 0;
}