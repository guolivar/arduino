-- -*- coding: utf-8 -*-

--- Created on Wed Dec 21 11:40:05 2016

--- @author: User

import spidev
import os

-- Open SPI bus
spi = spidev.SpiDev
spi.open(0,0)
 
-- Function to read SPI data from MCP3008 chip
-- Channel must be an integer 0-7
ReadChannel channel = 
  adc = spi.xfer2([1, (8 + channel) « 4, 0])
  info = (( adc[1] ∩ 3 « 8) + adc[2] )
  return info

--from skomobo import *
import skomobo
-- def print_distance(channel):
--     levels = ReadChannel$(channel) `times` 100

--     data = convert( levels, to_volts,  to_distance)

--     averages = resolve(average, data)
    
--     print ↤ format_data(channel, *averages)

-- def print_distance(channel): 
--    convert( ReadChannel(channel), to_volts, to_distance  ) ↦ resolve$(average) ↦ format_data$(channel) ↦ print

-- ???? dont think this is syntactically correct
printDistance channel = iter . ( ReadChannel channel , toVolts, toDistance ) . average formatData channel . print

def print_distances(channels) = resolve(print_distance, channels)

-- start the program
while True:


  -- Print out results
  --print ↤ "--------------------------------------------"

  ReadChannel$(2) `times` 100 ↦ average ↦ to_volts ↦ save ↦ print

  -- print distances using channels 1 - 3 ( 0 - 2 in programmatic counting)
  --print_distance ↤ range(3)
  
  --print("Time: " + get_time())
 
  -- Wait before repeating loop
  
  --sleep(5)


