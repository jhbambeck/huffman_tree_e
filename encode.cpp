#include <iostream>
#include <fstream>
#include "Bitcode_e.h"

using namespace std;

int main()
{
    std::ifstream code("basic_code");
    std::ifstream message("basic_message");
    std::ofstream encoded("encoded.bin", std::ios::out | std::ios::binary);
    Bitcode_e bit;
    bit.populate(code);
    bit.print();
    bit.genEncoded(message, encoded);
    return 0;
}
