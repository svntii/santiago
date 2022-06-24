#!/usr/bin/env python3


import os
import sys

arguments = sys.argv[1:]
'''
.sort sorts in place and doesn't return anything
arguments = arguments.sort()

or

use sorted

'''
for argument in sorted(arguments):
    '''
    try:
        value = os.environ[argument]
    except KeyError:
        value = ''
    print(f'{argument}:{value}')
    '''
    
    '''
    if argument in os.environ:
        print(f'{argument}:{os.environ[argument]}')
    else:
        print(f'{argument}: ')
    '''
    
    
