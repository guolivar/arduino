#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0x7445b7b6

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
import serial
import time
import sys
import glob
from skomobo import resolve
from skomobo import my_filter
def try_port(items, port):
 try:
  s = serial.Serial(port)
  s.close()
  items.append(port)
 except (OSError, serial.SerialException):
  return
def listSerialPorts():
 """ Lists serial ports :returns: A list of available serial ports """
 port_name = lambda i: 'COM' + str(i + 1)
 ports = resolve(port_name, range(256))
 tested_ports = []
 resolve(_coconut.functools.partial(try_port, tested_ports), ports)
 return tested_ports
def setupSerial(serPort):
 global ser
 baudRate = 9600
 ser = serial.Serial(serPort, baudRate)
 (print)("Serial port " + serPort + " opened  Baudrate " + str(baudRate))
 waitForArduino()
def closeSerial():
 global ser
 if 'ser' in globals():
  ser.close()
  (print)("Serial Port Closed")
 else:
  (print)("Serial Port Not Opened")
startMarker = 60
endMarker = 62
def sendToArduino(sendStr):
 global startMarker, endMarker, ser
 ser.write(chr(startMarker))
 ser.write(sendStr)
 ser.write(chr(endMarker))
def recvFromArduino(timeOut):
 global startMarker, endMarker, ser
 dataBuf = ""
 x = "z"
 byteCount = -1
 startTime = time.time()
 while ord(x) != startMarker:
  if time.time() - startTime >= timeOut:
   return ('<<')
 x = ser.read()
 while ord(x) != endMarker:
  if time.time() - startTime >= timeOut:
   return ('>>')
  if ord(x) != startMarker:
   dataBuf = dataBuf + x
  x = ser.read()
 return (dataBuf)
def waitForArduino():
 (print)("Waiting for Arduino to reset")
 msg = recvFromArduino(10)
 while msg.find("Arduino is ready") != -1:
  msg = recvFromArduino(10)
  if msg != "" and msg != " ":
   (print)(msg + "\n")
