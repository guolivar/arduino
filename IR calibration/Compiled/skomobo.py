#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0xcd964d0d

# Compiled with Coconut version 1.2.0 [Colonel]

""" This file stores all our personal functions that don't rely on SPI so that we can unit test """

from __future__ import print_function, absolute_import, unicode_literals, division
import sys as _coconut_sys, os.path as _coconut_os_path
_coconut_file_path = _coconut_os_path.dirname(_coconut_os_path.abspath(__file__))
_coconut_sys.path.insert(0, _coconut_file_path)
from __coconut__ import *
import __coconut__
_coconut_sys.path.remove(_coconut_file_path)
for name in dir(__coconut__):
 if name.startswith("_") and not name.startswith("__"):
  globals()[name] = getattr(__coconut__, name)

""" @author: Ryan Weyers """
def to_volts(data, places=2):
 volts = (data * 3.3) / float(1023)
 volts = round(volts, places)
 return volts
def to_distance(v, places=2):
 return 16.2537 * v**4 - 129.893 * v**3 + 382.268 * v**2 - 512.611 * v + 306.439
resolve = _coconut_compose(list, map)
def convert(*items):
 """ Takes the first arg and runs the next arg on it and stores the result in a final list """
 result = []
 result.append(items[0])
 append = _coconut_compose(result.append, resolve)
 append(items[1], items[0])
 append(items[2], result[1])
 return result
from time import sleep
from time import asctime
from time import localtime
from time import time
get_time = _coconut_compose(asctime, localtime, time)
def save(text):
 log = open("Log.txt", "a")
 data = str(text) + " " + get_time()
 resolve(log.write, (data, "\n"))
 log.close()
 return data
@_coconut_tco
def times(funct, repetitions):
 raise _coconut_tail_call(resolve, lambda _=None: funct(), range(repetitions))
add = _coconut.functools.partial(reduce, _coconut.operator.add)
def average(items):
 return add(items) / len(items)
@_coconut_tco
def format_data(*data):
 raise _coconut_tail_call("Distance {}: {} ({}V) {} cm".format, *data)
