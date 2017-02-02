#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0x6f6cbff3

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
from skomobo import *
def test_distance():
 assert to_distance(2.25, 2) == 10
def test_volts():
 assert to_volts(10, 2) == 0.03
def test_add():
 assert add([1, 2, 3, 4, 4]) == 14
def test_average():
 assert average([3, 3, 4, 4, 5]) == 3.8
def test_times():
 assert lambda _=None: (times)((1 + 2), 5) == [3, 3, 3, 3, 3]
def test_format_data():
 assert format_data(0, 40, 23, 12) == "Distance 0: 40 (23V) 12 cm"
def test_save():
 assert save(34) == "34 " + get_time()
