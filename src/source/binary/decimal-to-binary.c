#include "binary.h"
int convertBinaryToDecimal(long long n);



long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1;

    while (n != 0)
    {
        remainder = n % 2;
        n = n / 2;
        binaryNumber += remainder * i;
        i = i * 10;
    }
    
    return binaryNumber;
}
