#!/usr/bin/env python3

import os
import random
import sys

#const

NSFW = {'bong', 'sodomized', 'kiss', 'head-in', 'telebears'}

def main():
    cows = []


    for line in os.popen('cowsay -l'):
        for cow in line.split():
            print(cow)


if __name__ == '__main__':
    main()
