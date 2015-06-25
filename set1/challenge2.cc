#include <iostream>
#include "set1.h"

using namespace std;

int main(void){
    string a = "1c0111001f010100061a024b53535009181c";
    string b = "686974207468652062756c6c277320657965";
    vector<unsigned char> hex_a = unhexlify(a);
    vector<unsigned char> hex_b = unhexlify(b);
    vector<unsigned char> x = xor_bytes(hex_a, hex_b);
    for(int i=0; i < x.size(); i++)
        cout << x[i];
    cout << endl;
    return 0;
}
