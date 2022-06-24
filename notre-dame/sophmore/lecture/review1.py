#!/usr/bin/env python3

# imperative

numbers = range(0, 10)


doubled = map( lambda num: num * 2  , numbers)

'''
    for n in numbers:
        doubled.append(n *2 )
'''

selected = filter( lambda n:not n % 4, doubled)

'''
    for n in doubled:
        if not n % 4:
            selected.append(n)
'''


doubled_2 = [n * 2  for n in numbers]

selected_2 = [n for n in doubled_2 if not n % 4]

for s in selected:
    print(s)

for g in selected_2:
    print(g)

