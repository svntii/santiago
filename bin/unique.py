#!/usr/bin/env python3

import os
import sys

# Functions

def usage(status=0):
    ''' Display usage message and exit with status. '''
    progname = os.path.basename(sys.argv[0])
    print(f'''Usage: {progname} [flags]

    -c      Prefix lines by the number of occurences
    -d      Only print duplicate lines
    -i      Ignore differences in case when comparing, prints out full line in lowercase
    -u      Only print unique lines

By default, {progname} prints one of each type of line. The better version of uniq''')
    sys.exit(status)

def count_frequencies(stream=sys.stdin, ignore_case=False):
    ''' Count the line frequencies from the data in the specified stream while
    ignoring case if specified.
    '''
    
    counts = {}
    for words in stream:
        words = words.rstrip()
        if not ignore_case:
            counts[words] = counts.get(words, 0) + 1
        else:
            counts[words.lower()] = counts.get(words.lower(), 0) + 1
    
    return counts


def print_lines(frequencies, occurrences=False, duplicates=False, unique_only=False):
    ''' Display line information based on specified parameters:

    - occurrences:  if True, then prefix lines with number of occurrences
    - duplicates:   if True, then only print duplicate lines
    - unique_only:  if True, then only print unique lines
    '''
    for key, value in frequencies.items():
        line = '' # clears line
        if occurrences == True: # logic that controls if occurence prefaces the print
            line = f'{value:>7} {key}'
        else:
            line = key

        if duplicates == True:
            if value > 1:
                print(line)
        elif unique_only == True:
            if value == 1:
                print(line)
        else:
            print(line)
   
def main():
    ''' Process command line arguments, count frequencies from standard input,
    and then print lines. '''
    arguments = sys.argv[1:]
    PREFIX = 0
    DUPLICATE = 0
    iCASE = 0
    UNIQUE = 0

    while arguments and arguments[0].startswith('-'):
        if arguments[0] == '-c':
            PREFIX = True
        elif arguments[0] == '-d':
            DUPLICATE = True
        elif arguments[0] == '-i':
            iCASE = True
        elif arguments[0] == '-u':
            UNIQUE = True
        elif arguments[0] == '-h':
            usage(0)
        else:
            usage(1)
        arguments.pop(0)
# Main Execution
    freq = count_frequencies(ignore_case = iCASE)
    print_lines(freq, PREFIX, DUPLICATE, UNIQUE)

if __name__ == '__main__':
    main()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
