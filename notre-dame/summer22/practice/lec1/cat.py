#!/usr/bin/env python3

import sys

for line in sys.stdin:
    '''
    you are taking each line in stdin and mapping every character in a line that delim
    by a space and mapping the integer function on it

    .split auto makes lines arrays
    and each element is auto char

    '''
    x, y = map(int, line.split())
    print(f'{x} {y}')
    print(f"{x + y}")
