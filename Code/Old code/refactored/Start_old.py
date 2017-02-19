# -*- coding: utf-8 -*-
"""
Created on Mon Jan 23 2017

@author: Ryan Weyers
"""

#!/usr/bin/pypy


# standard python library
from time import sleep

from Sensors import Temp, Distance, Light, Time, Sensor
from Processor import average_10, nth_elem, process_sensors, format_data

#impo Processor

def average (data, index):
    return round(average_10( nth_elem( data, index)), 2)

def print_sensor(index, sensor):

    # we remove the "Sensor." from the name of the measurement
    measurement_type = sensor.__name__[8:] + ": "

    rawData = sensor.GetData
    
    data  = average( rawData(index), 0 )
    volts = average( rawData(index), 1 )
    level = average( rawData(index), 2 )
    
    reading = format_data(data, level, volts, sensor.unit)
    #reading = format_data(rawData())
    
    print (measurement_type + reading)

def print_data(sensors):

    """ This function prints data for a specific sensor"""
    process_sensors(print_sensor, sensors)


def print_all_data():

    """ This function prints out all the data for our sensors """
    # Print out results
    print ("--------------------------------------------")

    sensors = Distance, Distance, Distance, Time
    
    print_data(sensors)
    
    # Wait before repeating loop
    sleep(5)

    # repeat loop
    print_all_data()

print_all_data()
