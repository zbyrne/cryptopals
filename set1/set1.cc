#include "set1.h"
#include <map>
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

byte_vector unhexlify(string &s){
    byte_vector out;
    int count = s.length() % 2;
    unsigned char buffer = 0;
    for(auto &it: s){
        buffer <<= 4;
        buffer += hex_to_nibble(it);
        if (++count == 2){
            out.push_back(buffer);
            count = 0;
            buffer = 0;
        }
    }
    return out;
}

string b64encode(byte_vector &bytes){
    unsigned int buffer = 0;
    int count = 0, index;
    string out = string();
    for(auto &it: bytes){
        buffer <<= 8;
        buffer += it;
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
        out.append("==");
        break;
    case 2:
        out.push_back('=');
        break;
    }
    return out;
}

byte_vector b64decode(string &s){
    byte_vector out;
    unsigned int buffer = 0;
    int count = 0;
    for(auto &it: s){
        if(it == '=')
            break;
        buffer <<= 6;
        for(int i=0; i < b64_alpha.length(); i++){
            if(b64_alpha[i] == it){
                buffer += i;
                break;
            }
        }
        if(++count == 4){
            for(int i=2; i>=0; i--){
                out.push_back((buffer >> i*8) & 0xff);
            }
            buffer = 0;
            count = 0;
        }
    }
    switch(count){
    case 3:
        out.push_back((buffer >> 8) & 0xff);
    case 2:
        out.push_back(buffer & 0xff);
    }
    return out;
}

byte_vector xor_bytes(byte_vector &a, byte_vector &b){
    byte_vector out;
    for(byte_vector::iterator it_a=a.begin(), it_b=b.begin();
        it_a!=a.end() && it_b!=b.end(); ++it_a, ++it_b){
        out.push_back(*it_a ^ *it_b);
    }
    return out;
}

map<char, int> freq = {
    {' ', 124}, {'e', 92}, {'t', 79}, {'i', 53}, {'a', 53}, {'s', 46},
    {'o', 43}, {'n', 42}, {'r', 33}, {'l', 33}, {'h', 31}, {'p', 22},
    {'u', 21}, {'b', 21}, {'y', 17}, {'d', 17}, {'c', 17}, {'m', 16},
    {'f', 12}, {'g', 11}, {'x', 6}, {'v', 5}, {'w', 4}, {'k', 2},
    {'z', 1}
};

int score_key(byte_vector &bytes, unsigned char key){
    int score = 0;
    unsigned char c;
    for(auto &b: bytes){
        c = b ^ key;
        if(c & 0x80)
            return -1;
        if(freq.count(c) > 0)
            score += freq[c];
    }
    return score;
}

pair<int, int> find_best_key(byte_vector &bytes){
    int best = -1;
    int best_score = -1;
    int score;
    for(int c=0; c < 0x100; c++){
        score = score_key(bytes, c);
        if(score >= 0 && score > best_score){
            best_score = score;
            best = c;
        }
    }
    return pair<int, int>(best, best_score);
}

byte_vector rk_xor_encrypt(byte_vector &bytes, byte_vector &key){
    int key_index = 0;
    byte_vector out;
    for(auto &it: bytes){
        out.push_back(it ^ key[key_index++]);
        key_index %= key.size();
    }
    return out;
}

int hamming_distance(byte_vector &a, byte_vector &b){
    byte_vector x = xor_bytes(a, b);
    int distance = 0;
    for(auto &c: x){
        distance += __builtin_popcount(c);
    }
    return distance;
}

byte_vector find_rk_xor_key(byte_vector &bytes){
    byte_vector key;
    int keysize = 0;
    double distance;
    double best_distance = 1000000;
    for(int i=2; i < 42; i++){
        distance = 0;
        for(int j=0; j < 4; j++){
            int start = j*i;
            int mid = j*i + i;
            int end = j*i + 2*i;
            auto a = byte_vector(bytes.begin()+start,
                                 bytes.begin()+mid);
            auto b = byte_vector(bytes.begin()+mid,
                                 bytes.begin()+end);
            distance += hamming_distance(a, b);
            //cout << (int)a[0] << ' ' << (int)b[0] << endl;
        }
        distance /= i*4;
        //cout << i << ' ' << distance << endl;
        if(distance < best_distance){
            best_distance = distance;
            keysize = i;
        }
    }
    return key;
}
