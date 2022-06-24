#!/usr/bin/python3
import sys
import re
import pprint
import requests


URL = 'https://en.wikipedia.org/w/api.php'

PARAMS = (
    'action' : 'query',
    'list': 'search',
    'format' : 'JSON'
    'srsearch' : sys.argv:[1:]
)


response = requests.get(URL, params = PARAMS)
data = response.JSON()
articles = data['query']['']
