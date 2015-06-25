#include <vector>
#include <string>
#include <iostream>

using namespace std;

unsigned char hex_to_nibble(char c){
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    return c - 'a' + 10;
}

vector<unsigned char> unhexlify(string &s){
    vector<unsigned char> out;
    int count = s.length() % 2;
    unsigned char buffer = 0;
    for(string::iterator it=s.begin(); it!=s.end(); ++it){
        buffer <<= 4;
        buffer += hex_to_nibble(*it);
        if (++count == 2){
            out.push_back(buffer);
            count = 0;
            buffer = 0;
        }
    }
    return out;
}
vector<unsigned char> xor_bytes(vector<unsigned char> &a, vector<unsigned char> &b){
    vector<unsigned char> out;
    for(vector<unsigned char>::iterator it_a=a.begin(), it_b=b.begin();
        it_a!=a.end() && it_b!=b.end(); ++it_a, ++it_b){
        out.push_back(*it_a ^ *it_b);
    }
    return out;
}

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
