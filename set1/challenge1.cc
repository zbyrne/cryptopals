#include <string>
#include <iostream>
using namespace std;

unsigned int hex_to_int(char c){
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    return c - 'a' + 10;
}

int main(void){
    string c = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    for (int i=0; i < c.length(); i++){
        cout << hex_to_int(c[i]);
    }
    return 0;
}
