#include <iostream>
#include <iomanip>
#include "set1.h"

using namespace std;

int main(void){
    string c = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    byte_vector bytes = unhexlify(c);
    string x = b64encode(bytes);
    cout << x << endl;
    auto test = b64decode(x);
    for(auto &it: test){
        cout << setbase(16) << (int)it;
    }
    cout << endl;
    return 0;
}
