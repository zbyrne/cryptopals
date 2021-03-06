#include <iostream>
#include <iomanip>
#include <fstream>
#include "set1.h"

using namespace set1;

int main(void){
    std::ifstream ifs;
    ifs.open("6.txt");
    std::string buffer;
    std::string input;
    while(ifs){
        ifs >> buffer;
        input.append(buffer);
    }
    auto cipher = b64decode(input);
    auto key = find_rk_xor_key(cipher);
    auto plain = rk_xor_encrypt(cipher, key);
    for(const auto &p: plain)
        std::cout << p;
    std::cout << std::endl;
    return 0;
}
