#!/usr/bin/env python3

import random

def FizzBuzz(start = 1, end = 5):

    for number in range(start, end + 1):
        if number % 15 == 0:
            print("fizzBuzz")
        elif number % 5 == 0:
            print("buzz")
        elif number % 3 == 0:
            print("fizz")
        else:
            print(number)

FizzBuzz(1, 100)
