#!/usr/bin/env python3

import os

# for a list
for i in [1, 2, 3, 4]:
    print(i)

# for a string
for c in 'santiago':
    print(c)

# environmental variables (dictionary)
for key, value in os.environ.items():
    print(key, value)

# for a file

for line in open('/etc/passwd'):
    print(line.rstrip())

'''
i = iter(range(5))

next(i)
...
...
StopIteration ERROR

iterator is not a list
 *** you can type cast with list()
'''


