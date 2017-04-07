#ifndef BITCODE_E_H
#define BITCODE_E_H
#include <string>
#include <iostream>
#include <fstream>
class Bitcode_e
{
public:
    struct CodePair
    {
        char ch;
        std::string bits;
    };

    int index = 0;
    CodePair pairArray[30];

    void input(char, std::string);
    void populate();
    void print();
    void genEncoded();
    void standardize(char&);
    void printBinary(std::string, int&, std::ofstream&);
};

#endif // BITCODE_E_H
