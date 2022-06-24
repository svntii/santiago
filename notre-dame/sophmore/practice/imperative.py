#!/usr/bin/env python3

import math


'''
def find_squares(start, end):
    squares = []
    for number in range(start, end):
        if math.sqrt(number) == int(math.sqrt(number)):
            squares.append(number)
    return squares
'''

# this method produces a generator
# emphasis on the yield portion
'''
def find_squares(start=0, end= 25):
    for number in range(start, end):
        if math.sqrt(number) == int(math.sqrt(number)):
            yield number
'''

def find_squares(start=0, end= 25):
    return filter(lambda number: math.sqrt(number) == int(math.sqrt(number)), range(stat, end))



squares = find_squares(0,101)

for item in squares:
    print(item)


