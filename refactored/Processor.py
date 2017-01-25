#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0x2ae8e60e

# Compiled with Coconut version 1.2.0 [Colonel]

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
def process_sensors(process, sensors):
 for index, sensor in enumerate(sensors):
  process(index, sensor)
@_coconut_tco
def repeat(callback, repetitions, items=[]):
 """ This function  calls the callback the specified times """
 (items.append)(callback())
 if repetitions == 0:
  return items
 raise _coconut_tail_call(repeat, callback, repetitions - 1, items)
def average(items):
 return sum(items) / len(items)
@_coconut_tco
def average_10(callback):
 "this function repeats a callback 10 times and then averages the result"
 raise _coconut_tail_call((average), (repeat)(*(callback, 10)))
@_coconut_tco
def FormatVolts(volts):
 raise _coconut_tail_call("({}V) ".format, volts)
def format_data(data, level, volts, unit):
 result = str(level) + " " + FormatVolts(volts)
 value = str(data) + " " + unit
 return result + value
