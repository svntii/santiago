#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void disassemble(int);

int main()
{
    disassemble(0x63a4);
    disassemble(0x317f);
    disassemble(0x1ab2);

    return 0;
}

void disassemble(int i)
{

    int last = 0x000f & i;
    int third = (0x00f0 & i) >> 4;
    int second = (0x0f00 & i) >> 8;
    int first = (0xf000 & i) >> 12;

    printf("opcode = %x    rw = %x    ra = %x    rb = %x\n", first, second, third, last);
}