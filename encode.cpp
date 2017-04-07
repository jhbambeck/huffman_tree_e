#include <iostream>
#include "Bitcode_e.h"

using namespace std;

int main()
{
    Bitcode_e bit;
    bit.populate();
    bit.print();
    bit.genEncoded();
    return 0;
}
