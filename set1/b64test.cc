#include <iostream>
#include "set1.h"

using namespace set1;

int main(void){
    std::string test = "easure.";
    auto b = byte_vector(test.begin(), test.end());
    auto b64 = b64encode(b);
    std::cout << b64 << std::endl;
    auto dec = b64decode(b64);
    for(const auto &c: dec)
        std::cout << c;
    std::cout << std::endl;
    return 0;
}
