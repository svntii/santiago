#!/usr/bin/env python3

import os
import sys
import csv

def main():
    stream = open("/etc/passwd")
    for record in csv.reader(stream, delimiter = ":"):
       print(record)

if __name__ =="__main__":
    main()
