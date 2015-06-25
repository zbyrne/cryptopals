#include "set1.h"

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

vector<unsigned char> xor_bytes(vector<unsigned char> &a, vector<unsigned char> &b){
    vector<unsigned char> out;
    for(vector<unsigned char>::iterator it_a=a.begin(), it_b=b.begin();
        it_a!=a.end() && it_b!=b.end(); ++it_a, ++it_b){
        out.push_back(*it_a ^ *it_b);
    }
    return out;
}

// frequency map made in python by looking at the output of the 'this' module
// [(' ', 124), ('e', 92), ('t', 79), ('i', 53), ('a', 53), ('s', 46),
//  ('o', 43), ('n', 42), ('r', 33), ('l', 33), ('h', 31), ('p', 22),
//  ('u', 21), ('b', 21), ('y', 17), ('d', 17), ('c', 17), ('m', 16),
//  ('f', 12), ('g', 11), ('x', 6), ('v', 5), ('w', 4), ('k', 2), ('z', 1)]
