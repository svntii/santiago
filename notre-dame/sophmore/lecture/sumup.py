#!/usr/bin/env python3

import sys 

arguments = sys.argv[1:]
'''
print(sys.argv)
print(len(sys.argv))
print(arguments)
print(sum(arguments))
'''

numbers  = []

for argument in arguments:
    try:
        numbers.append(int(argument))
    except ValueError:
        pass
print(f'The sum of {numbers} is {sum(numbers)}')
