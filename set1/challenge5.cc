#include <iostream>
#include "set1.h"
#include <iomanip>

using namespace set1;

int main(void){
    std::string s = "Burning 'em, if you ain't quick and nimble\n"
        "I go crazy when I hear a cymbal";
    std::string k = "ICE";
    auto bytes = byte_vector(s.begin(), s.end());
    auto key = byte_vector(k.begin(), k.end());
    auto cipher = rk_xor_encrypt(bytes, key);
    auto plain = rk_xor_encrypt(cipher, key);
    for(const auto &p: plain){
        std::cout << p;
    }
    std::cout << std::endl;
}
