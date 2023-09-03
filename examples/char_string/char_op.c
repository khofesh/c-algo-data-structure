#include "char_op.h"

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}

int is_lower(char c)
{
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\12');
}

int strlen(char *pStr)
{
    int i = 0;
    while (pStr[i])
    {
        i++;
    }
    return i;
}

void to_upper(char *pStr)
{
    for (char *p = pStr; *p; ++p)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p -= 'a' - 'A';
        }
    }
}

void to_lower(char *pStr)
{
    for (char *p = pStr; *p; ++p)
    {
        if (*p >= 'A' && *p <= 'Z')
        {
            *p += 'a' - 'A';
        }
    }
}