#!/usr/bin/env python3
import sys

MAPPING = [
    ('a', '4'),
    ('e', '3'),
    ('i', '1'),
    ('o', '0'),
]

for line in sys.stdin:
    line = line.rstrip()
    result = ""
    for letter in line:
        for key, value in MAPPING:
            if letter == key:
                letter = value
        result += letter
    
    print(result)

