#!/usr/bin/env python3
# curl -sL http://yld.me/raw/lmz | cut -d , -f 2 | grep -Eo '^B.*' | sort



import re
import requests

URL = 'http://yld.me/raw/lmz'

data = requests.get(URL).text

listed = []

for line in data.splitlines():
    line = line.split(',')[1]
    match = re.findall('^B.*', line)
    if match:
        listed.append(line)


for item in sorted(listed):
    print(item)


