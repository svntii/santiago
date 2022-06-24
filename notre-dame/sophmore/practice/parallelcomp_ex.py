#!/usr/bin/env python3

import sys

'''
import sys

results = []
for number in sys.stdin:
    number = number.strip()
    if int(number) % 2 == 0:
        results.append(number)

print(' '.join(results))
'''

# generator
'''
def evens_py():
    for number in sys.stdin:
        number = number.rstrip()
        if int(number) % 2 == 0:
            yield number
'''

# list comprehension
'''
print(''.join(
    [ for number.rstrip() in sys.stdin if int(number.rstrip()) % 2 == 0]
    ))
'''

# FUNCTIONAL PROGRAMMING
'''
print(''.join(
    filter(lambda number: int(number) % 2 == 0 , map(lambda num: num.rstrip(), sys.stdin))
    ))

'''

