#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0x8868e5e6

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
def valToArduino(ledA, ledB, servo):
 spaced = map(+" ", ledA, ledB, servo)
 sendStr = reduce(_coconut.operator.add, spaced)
 (print)("SENDSTR " + sendStr)
 sendToArduino(sendStr)
def try_port(port):
 try:
  s = serial.Serial(port)
  s.close()
  return port
 except (OSError, serial.SerialException):
  return
@_coconut_tco
def listSerialPorts():
 """ Lists serial ports :returns: A list of available serial ports """
 port_name = lambda i: 'COM' + str(i + 1)
 ports = takewhile(lambda i: i != None, resolve(port_name, range(256)))
 raise _coconut_tail_call(resolve, try_port, ports)
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
 msg = ""
 while msg.find("Arduino is ready") == -1:
  msg = recvFromArduino(10)
  (print)(msg)
  print()
