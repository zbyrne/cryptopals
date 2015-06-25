#include <vector>
#include <string>
#include <iostream>

using namespace std;

string b64_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

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

string b64encode(vector<unsigned char> &bytes){
    unsigned int buffer = 0;
    int count = 0, index;
    string out = string();
    for(vector<unsigned char>::iterator it=bytes.begin(); it!=bytes.end(); ++it){
        buffer <<= 8;
        buffer += *it;
        if(++count == 3){
            for(int i=3; i>=0; i--){
                index = (buffer >> i*6) & 0x3f;
                out.push_back(b64_alpha[index]);
            }
            buffer = 0;
            count = 0;
        }
    }
    for(int i=0; i<(bytes.size()%3); i++){
        buffer <<= 8;
        if(++count == 3){
            for(int i=3; i>=0; i--){
                index = (buffer >> i*6) & 0x3f;
                out.push_back(b64_alpha[index]);
            }
        }
    }
    switch(bytes.size()%3){
    case 1:
        out.push_back('=');
        out.push_back('=');
        break;
    case 2:
        out.push_back('=');
        break;
    }
    return out;
}


int main(void){
    string c = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    vector<unsigned char> bytes = unhexlify(c);
    cout << b64encode(bytes) << endl;
    return 0;
}
