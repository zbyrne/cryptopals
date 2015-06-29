#include <iostream>
#include "set1.h"
#include <iomanip>
using namespace std;

int main(void){
    string s = "Burning 'em, if you ain't quick and nimble\n"
        "I go crazy when I hear a cymbal";
    string k = "ICE";
    byte_vector bytes = byte_vector(s.begin(), s.end());
    byte_vector key = byte_vector(k.begin(), k.end());
    byte_vector cipher = rk_xor_encrypt(bytes, key);
    byte_vector plain = rk_xor_encrypt(cipher, key);
    for(auto &p: plain){
        cout << p;
    }
    cout << endl;
}
