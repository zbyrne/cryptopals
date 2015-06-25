#include <iostream>
#include "set1.h"

using namespace std;

int main(void){
    string c = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    vector<unsigned char> bytes = unhexlify(c);
    cout << b64encode(bytes) << endl;
    return 0;
}
