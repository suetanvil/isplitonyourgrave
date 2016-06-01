#!/usr/bin/env python

import sys

def isoyg(s): return s.split("your grave")

for s in sys.argv[1:]:
    print "\n".join(isoyg(s)), "\n"
