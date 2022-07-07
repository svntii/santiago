#!/usr/bin/env python3

import sys

def main():
    # TODO: Read numbers
    s = set()
    total = 0
    for i in sys.stdin:
        if i in s:
            total+=1
        else:
            s.add(i)
    # TODO: Count duplicates

    # TODO: Display total
    print(f"the total is {total}")
if __name__ == '__main__':
    main()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:

