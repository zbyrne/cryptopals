#include <iostream>
#include <iomanip>
#include <fstream>
#include "set1.h"

using namespace std;

int main(void){
    ifstream ifs;
    ifs.open("6.txt");
    string buffer;
    string input;
    while(ifs){
        ifs >> buffer;
        input.append(buffer);
    }
    byte_vector cipher = b64decode(input);
    byte_vector key = find_rk_xor_key(cipher);
    return 0;
}
