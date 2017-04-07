#include "Bitcode_e.h"

void Bitcode_e::input(char c, std::string b)
{
    pairArray[index].ch = c;
    pairArray[index].bits = b;
    ++index;
}

void Bitcode_e::populate()
{
    std::ifstream code;
    code.open("basic_code");
    if(!code)
    {
        std::cout << "Cannot open code file";
    }

    for(int i = 0; i < 30; i++)
    {
        char c;
        std::string b;
        code >> c >> b;
        input(c,b);
    }
}

void Bitcode_e::print()
{
    for(int i = 0; i < index; i++)
    {
        std::cout << pairArray[i].ch << " " << pairArray[i].bits << std::endl;
    }
}

void Bitcode_e::genEncoded()
{
    std::ifstream message;
    message.open("basic_message");
    if(!message)
    {
        std::cout << "couldn't open message file";
    }

    std::ofstream encoded("basic_encoded.bin", std::ios::out | std::ios::binary);

    char c;
    std::string b;
    int numBits;

    message >> c;
    while(!message.eof())
    {
        standardize(c);
        for (int i = 0; i < index; i++)
        {
            if(c == pairArray[i].ch)
            {
                b = pairArray[i].bits;
            }
        }
        printBinary(b, numBits, encoded);
        message >> c;
    }
}

void Bitcode_e::printBinary(std::string bits, int& numBits, std::ofstream& encoded)
{
    char buff[1];
    int len = bits.length();
    for(int i = 0; i < len; i++)
    {
        buff[0] = bits.at(i);
        encoded.write(buff, 1);
    }
}

void Bitcode_e::standardize(char& c)
{
    if(c == ' ') c = '-';
    if(c == '\n') c = '!';
}
