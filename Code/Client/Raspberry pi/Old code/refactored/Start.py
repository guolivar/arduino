#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0x46ad5bcd

# Compiled with Coconut version 1.2.0 [Colonel]

"""
Created on Mon Jan 23 2017

@author: Ryan Weyers
"""

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

from time import sleep
from Sensors import Temp
from Sensors import Distance
from Sensors import Light
from Sensors import Time
from Sensors import Sensor
from Processor import average_10
from Processor import process_sensors
from Processor import format_data
@_coconut_tco
def normelize(data):
 averaged = (average_10)(data)
 raise _coconut_tail_call(round, averaged, 2)
def print_sensor(index, sensor):
 measurement_type = sensor.__name__[8:] + ": "
 data = (normelize)(_coconut.functools.partial(sensor.GetData, index))
 reading = str(data)
 print(measurement_type + reading)
def print_data(sensors):
 """ This function prints data for a specific sensor"""
 process_sensors(print_sensor, sensors)
def print_all_data():
 """ This function prints out all the data for our sensors """
 print("--------------------------------------------")
 sensors = Distance, Distance, Distance
 print_data(sensors)
 print(Time.GetTime())
 sleep(5)
 print_all_data()
print_all_data()
