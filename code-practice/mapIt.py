#!/usr/bin/env python3

import sys
import os
import re
import webbrowser
import pyperclip
# webbrowser.open('https://www.google.com/')

# GLOBALS
url = 'https://www.google.com/maps/place/'

#def usage(status=0):

# MAIN FUNCTION

def main():
    
    arguments = sys.argv[1:]

    while arguments and arguments[0].startswith('-'):
        argument = arguments.pop(0)
        if argument == '-h':
            pass
        else:
            pass

    if not arguments:
        address = pyperclip.paste()
        return 1
    else:
        address = arguments
    
    webbrowser.open('https://www.google.com/maps/place/' + str(address))






if __name__ == '__main__':
    main()
