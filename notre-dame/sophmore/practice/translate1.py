#!/usr/bin/env python3

import os
import re

count = 0
for line in open('/etc/passwd'):
    search = (line.split(':')[0])
    match = re.findall(r'd$', search)
    if match:
        count += 1

print(count)
