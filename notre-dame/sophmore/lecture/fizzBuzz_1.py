#!/usr/bin/env python3

import random

def fizzBuzz(start = 1, end = 5):
    '''
    Print fizzBuzz from start to end
    
    >>> fizzBuzz(1, 5)
    1
    2
    fizz
    4
    buzz
    '''
    for number in range(start, end + 1):
        if number % 15 == 0:
            print("fizzBuzz")
        elif number % 5 == 0:
            print("buzz")
        elif number % 3 == 0:
            print("fizz")
        else:
            print(number)

if __name__ == '__main__':
    fizzBuzz()
