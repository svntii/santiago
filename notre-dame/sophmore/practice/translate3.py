#!/usr/bin/env python3

import requests
import re
import os


data = requests.get('http://yld.me/raw/lmz').text

for line in data.splitlines():
    line  = line.split(',')[0]
    match = re.findall(r'^[^jfs].*', line)
    if match:
        print(line)
