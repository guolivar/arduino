#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0xb9ad1a00

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
@_coconut_tco
def addUp(items):
 """ Our owm summing function because the python one has a memory leak"""
 add = _coconut.functools.partial(reduce, _coconut.operator.add)
 raise _coconut_tail_call((add), items)
def average(*data):
 return addUp(data) / len(data)
