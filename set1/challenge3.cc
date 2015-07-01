#include <iostream>
#include "set1.h"

using namespace set1;

int main(void){
    std::string s = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    auto bytes = unhexlify(s);
    auto key = find_best_key(bytes);
    auto key_vec = byte_vector(bytes.size(), key.first);
    auto plain_text = xor_bytes(bytes, key_vec);
    for(const auto &byte: plain_text)
        std::cout << byte;
    std::cout << std::endl;
    return 0;
}
