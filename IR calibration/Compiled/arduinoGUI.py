#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0x2cdecc9b

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
if _coconut_sys.version_info < (3,):
 from Tkinter import *
else:
 from tkinter import *
from arduinoComms import *
import atexit
def exit_handler():
 print('Error closing application')
 closeSerial()
atexit.register(exit_handler)
tkArd = Tk()
tkArd.minsize(width=320, height=170)
tkArd.config(bg='yellow')
tkArd.title("Infrared calibrator")
frame = Frame(bg="green")
radioVar = StringVar()
def setupView():
 frame.pack()
 selectPort()
def runProgram():
 tkArd.mainloop()
from skomobo import resolve
destroy = lambda child: child.destroy()
def clean_window():
 _coconut.functools.partial(resolve, destroy, frame.winfo_children())
def config(item, command):
 item.config(command=command)
 return item
labl = _coconut.functools.partial(Label, frame)
def my_labl(width, height, text=""):
 return labl(width=width, height=height, text=text).pack()
def txt_labl(text):
 return labl(text=text).pack()
def selectPort():
 clean_window()
 my_labl(width=5, height=2)
 def createRadio(words):
  return config(Radiobutton(frame, variable=radioVar, value=words, text=words), radioPress).pack(anchor=W)
 def createRadios(radios):
  if len(radios) > 0:
   resolve(createRadio, radios)
  else:
   txt_labl("No Serial Port Found")
 createRadios(listSerialPorts())
def mainScreen():
 clean_window()
 Button(frame, text="LedA", fg="white", bg="black").config(command=lambda _=None: valToArduino("Record"))
def radioPress():
 setupSerial(radioVar.get())
 mainScreen()
setupView()
tkArd.mainloop()
