#include <iostream>
#include <iomanip>
#include "set1.h"

using namespace set1;

int main(void){
    std::string c = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    auto bytes = unhexlify(c);
    auto x = b64encode(bytes);
    std::cout << x << std::endl;
    auto test = b64decode(x);
    for(const auto &byte: test){
        std::cout << std::setbase(16) << (int)byte;
    }
    std::cout << std::endl;
    return 0;
}
