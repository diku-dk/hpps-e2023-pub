#!/usr/bin/env python

import sys

fname = sys.argv[1]

if b'A' in open(fname, "rb").read():
    print('found')
else:
    print('not found')
