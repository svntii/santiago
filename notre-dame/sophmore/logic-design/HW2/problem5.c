// problem5.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sumInt(int, int);

int main(void)
{

    sumInt(100, 200);
    sumInt(-100, -200);
    sumInt(0x7FFFFFFF, 1);
    sumInt(0x80000000, -1);
    sumInt(0x7FFFFFFF, 0x80000000);

    return 0;
}

void sumInt(int a, int b)
{

    int sum = a + b;

    fprintf(stdout, "%d + %d = \n", a, b);
    fprintf(stdout, "Sum: %d (decimal), %x (hex)\n", sum, sum);

    if ((~(a >> 31 | b >> 31)) & (sum >> 31))
    {
        printf("overflow\n\n");
    }
    else if ((a >> 31 & b >> 31) & ~(sum >> 31))
    {
        printf("overflow\n\n");
    }
    else
    {
        printf("no overflow\n\n");
    }
};
