# -*- coding: utf-8 -*-
"""
Created on Wed Dec 21 11:40:05 2016

@author: User
"""

#!/usr/bin/pypy
 
import spidev
import time
import os
 
# Open SPI bus
spi = spidev.SpiDev()
spi.open(0,0)
 
# Function to read SPI data from MCP3008 chip
# Channel must be an integer 0-7
def ReadChannel(channel):
  adc = spi.xfer2([1,(8+channel)<<4,0])
  data = ((adc[1]&3) << 8) + adc[2]
  return data
 
# Function to convert data to voltage level,
# rounded to specified number of decimal places.
def ConvertVolts(data,places):
  volts = (data * 3.3) / float(1023)
  volts = round(volts,places)
  return volts
 
# Function to calculate temperature from
# TMP36 data, rounded to specified
# number of decimal places.
def ConvertTemp(data,places):
 
  # ADC Value
  # (approx)  Temp  Volts
  #    0      -50    0.00
  #   78      -25    0.25
  #  155        0    0.50
  #  233       25    0.75
  #  310       50    1.00
  #  465      100    1.50
  #  775      200    2.50
  # 1023      280    3.30
 
  temp = ((data * 330)/float(1023))-50
  temp = round(temp,places)
  return temp

# IR sensor conversion
# formula retrieved from http://home.roboticlab.eu/en/sensor/ir_distance
# measures back to the back / middle of the sensor???

# seems to be 1 cm too large all the time

def ConvertDistance(data, places):
  #return round ( 5461 / (data - 17) -2, places)

  # subtracting 1 extra to compensate maybe it's just the hardware???
  return round ( 5461 / (data - 17) -3, places)

# Define sensor channels
light_channel = 0
temp_channel  = 1

# --Ryan adding one more channel for the ir sensors
ir_channel = 2
 
# Define delay between readings
delay = 5
 
while True:
 
  # Read the light sensor data
  light_level = ReadChannel(light_channel)
  light_volts = ConvertVolts(light_level,2)
 
  # Read the temperature sensor data
  temp_level = ReadChannel(temp_channel)
  temp_volts = ConvertVolts(temp_level,2)
  temp       = ConvertTemp(temp_level,2)

  # --Ryan Read the distance data
  ir_level = ReadChannel(ir_channel)
  ir_volts = ConvertVolts(ir_level, 2)
  distance = ConvertDistance(ir_level, 7)
 
  # Print out results
  print "--------------------------------------------"
  print("Light: {} ({}V)".format(light_level,light_volts))
  print("Temp : {} ({}V) {} deg C".format(temp_level,temp_volts,temp))
  print("Distance : {} ({}V) {} cm".format(ir_level, ir_volts, distance))
  print("Time: {}").format(time.asctime( time.localtime(time.time())))
 
  # Wait before repeating loop
  time.sleep(delay)
