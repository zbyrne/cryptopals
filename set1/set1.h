#ifndef SET1_H
#define SET1_H
#include <string>
#include <vector>

typedef std::vector<unsigned char> byte_vector;

byte_vector unhexlify(std::string &);
std::string b64encode(byte_vector &);
byte_vector b64decode(std::string &);
byte_vector xor_bytes(byte_vector &, byte_vector &);
int score_key(byte_vector &, unsigned char);
std::pair<int, int> find_best_key(byte_vector &);
byte_vector rk_xor_encrypt(byte_vector &, byte_vector &);
int hamming_distance(byte_vector &, byte_vector &);
byte_vector find_rk_xor_key(byte_vector &);

#endif
