#!/usr/bin/env python3

import collections

Person = collections.namedtuple(
    'Person',
    'first_name last_name'
)

People = [

    Person('Oat', 'Rodriguez-Hoyte'),
    Person('Levi', 'Rodriguez-Hoyte'),
    Person('Prestina', 'Rodriguez-Hoyte'),
]


SortedPeople = sorted(People, key=lambda p: (p.last_name, p.first_name))
# order matters in which your sort. Priority last
for person in sorted(People, key = lambda p: p.last_name):
    print(person.first_name, person.last_name)
