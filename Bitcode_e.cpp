#include "Bitcode_e.h"

void Bitcode_e::input(char c, std::string b)
{
    pairArray[index].ch = c;
    pairArray[index].bits = b;
    ++index;
}

void Bitcode_e::populate(std::ifstream& code)
{
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

void Bitcode_e::genEncoded(std::ifstream& message, std::ofstream& encoded)
{
    char c;
    std::string b;
    int numBits = 0;

    message.get(c);
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
        message.get(c);
    }
    b = pairArray[29].bits;
    printBinary(b, numBits, encoded);

    char buff[1];
    buff[0] = '0';
    int numZeros = numBits % 8;
    for(int i = 0; i < numZeros; i++)
    {
        encoded.write(buff, 1);
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
    numBits += bits.length();
}

void Bitcode_e::standardize(char& c)
{
    if(c == ' ') c = '-';
    if(c == '\n') c = '!';
}
