#!/usr/bin/env python3

import os
import re

matches = []

for line in open('/etc/passwd'):
    match = line.split(':')[2]
    search = re.findall(r'^[0-9]{2}$',match)
    if search:
        matches.append(match)

uniqset = sorted(set(matches))

for item in uniqset:
    print(item)
