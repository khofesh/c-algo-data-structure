#include "binary.h"
#include <math.h>

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder = 0;

    while (n != 0)
    {
        // get last digit
        remainder = n % 10; 
        n = n / 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    
    return decimalNumber;
}
