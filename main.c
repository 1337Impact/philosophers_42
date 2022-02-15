#include <stdio.h>

int main()
{
    char str[] = "hello world";
    char *h = str+6;
    printf("%c\n", h[-3]);
    return 0;
}