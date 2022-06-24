#!/usr/bin/env python3

import collections

Node = collections.namedtuple('Node', 'data next')

def slist_data(head):
    data = []
    curr = head
    while curr:
        data.append(curr.data)
        curr = curr.next
        return data

def slist_data_generator(head):
    curr = head
    while curr:
        yield curr.data
        curr = curr.next

def recursion_slist(head):
    if curr in None:
        pass
    else:
        yield curr.data
        yield from recursion_slist(curr.next)

if __name__ = '__main__':
    slist == Node('A', Node('B', Node('C',None)))
