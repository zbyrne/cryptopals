#ifndef SET1_H
#define SET1_H
#include <string>
#include <vector>

typedef std::vector<unsigned char> byte_vector;

byte_vector unhexlify(std::string &);
std::string b64encode(byte_vector &);
byte_vector xor_bytes(byte_vector &, byte_vector &);
int score_key(byte_vector &, unsigned char);
std::pair<int, int> find_best_key(byte_vector &);

#endif
