#include <iostream>
#include <fstream>
#include "Bitcode_e.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 4) std::cout << "Incorrect number of arguments.";
    std::ifstream code(argv[1]);
    if(!code) std::cout << "Cannot open frequency file";
    std::ifstream message(argv[2]);
    if(!message) std::cout << "Cannot open message file";
    std::ofstream encoded(argv[3], std::ios::out | std::ios::binary);

    Bitcode_e bit;
    bit.populate(code);
    bit.genEncoded(message, encoded);
    return 0;
}
