#!/usr/bin/env python3

import requests
import csv


URL      = 'https://yld.me/raw/cxEe'
POINTS   = [5]*6
MAX      = sum(POINTS)
SECTIONS = (
    'Commands',
    'Shells and Files',
    'Processing and Networking',
    'Pipelines',
    'Shell Scripting',
    'Filters'
)

#fetch data

response = requests.get(URL)
scores = []
sections = [0]*len(SECTIONS)

for student in csv.reader(response.text.splitlines()):
    score = 0    
    for section, point in enumerate(student):
        score += float(point)
        sections[section] += float(point)
    scores.append(score)

average = sum(scores) / len(scores)
median  = sorted(scores)[int(len(scores)/2)]
maximum = max(scores)

print(f'average = {average:5.2f} ({average/maximum*100:5.2f}%)')
print(f'median = {median:5.2f} ({median/maximum*100:5.2f}%)')
print(f'maximum = {maximum:5.2f}')
