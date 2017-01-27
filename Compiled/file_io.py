#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0x78c1d848

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
import demjson
import json
def retrieve_data(file_name):
 file = open(file_name)
 result = json.load(file)
 file.close()
 return result
def store_data(file_name, data):
 file = open(file_name, "w")
 json = demjson.encode(data)
 file.write(json)
 file.close()
