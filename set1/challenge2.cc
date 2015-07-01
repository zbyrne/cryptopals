#include <iostream>
#include "set1.h"

using namespace set1;

int main(void){
    std::string a = "1c0111001f010100061a024b53535009181c";
    std::string b = "686974207468652062756c6c277320657965";
    auto hex_a = unhexlify(a);
    auto hex_b = unhexlify(b);
    auto x = xor_bytes(hex_a, hex_b);
    for(const auto &byte: x)
        std::cout << byte;
    std::cout << std::endl;
    return 0;
}
