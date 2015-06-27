#include <iostream>
#include <fstream>
#include "set1.h"

using namespace std;

int main(void){
    ifstream ifs;
    vector<byte_vector> ciphers;
    string buffer;
    int best_score = -1;
    int best_key = -1;
    byte_vector candidate;
    ifs.open("4.txt");
    while(ifs.good()){
        getline(ifs, buffer);
            ciphers.push_back(unhexlify(buffer));
    }
    for(auto &bytes: ciphers){
        auto key = find_best_key(bytes);
        if(key.first >= 0 && key.second > best_score){
            best_score = key.second;
            best_key = key.first;
            candidate = bytes;
        }
    }
    auto key_vec = byte_vector(candidate.size(), best_key);
    auto plain_text = xor_bytes(candidate, key_vec);
    for(int i=0; i < plain_text.size(); i++)
        cout << plain_text[i];
    cout << endl;

    return 0;
}
