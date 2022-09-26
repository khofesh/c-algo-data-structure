#include <stdio.h>
#include "binary.h"

int main(int argc, char *argv[]) 
{
    int n = 0;
    long long result = 0;

    printf("enter a decimal number:");
    scanf("%d", &n);

    result = convertDecimalToBinary(n);

    printf("%d in decimal = %lld in binary\n", n, result);
    
    return 0;
}
