#!/usr/bin/env python
# -*- coding: utf-8 -*-

from skomobo import *

def test_distance():
    assert ConvertDistance(2.25, 2) == 10

def test_volts():
    assert ConvertVolts(10, 2) == 0.03

def test_addUp():
    assert addUp([1, 2, 3, 4, 4]) == 14

def test_average():
    assert average([3, 3, 4, 4, 5]) == 3.8