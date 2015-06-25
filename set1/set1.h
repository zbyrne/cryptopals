#ifndef SET1_H
#define SET1_H
#include <string>
#include <vector>

std::vector<unsigned char> unhexlify(std::string &);
std::string b64encode(std::vector<unsigned char> &bytes);
std::vector<unsigned char> xor_bytes(std::vector<unsigned char> &, std::vector<unsigned char> &);

#endif
