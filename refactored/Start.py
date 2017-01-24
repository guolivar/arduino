# -*- coding: utf-8 -*-
"""
Created on Mon Jan 23 2017

@author: Ryan Weyers
"""

#!/usr/bin/pypy


# standard python library
from time import sleep

from Sensors import Temp, Distance, Light, Time, Sensor
from Processor import average_10, first_elem, format_data

def print_sensor(index, sensor):

    # we remove the "Sensor." from the name of the measurement
    measurement_type = sensor.__name__[8:] + ": "
        
    data = average_10(first_elem(sensor.GetData(index)))
    reading = FormatData(data)
    
    print measurement_type + reading

def print_data(sensors):

    """ This function prints data for a specific sensor"""
    Processor.process_sensors(print_sensor, sensors)


def print_all_data():

    """ This function prints out all the data for our sensors """
    # Print out results
    print "--------------------------------------------"

    sensors = Distance, Distance, Distance, Time
    
    print_data(sensors)
    
    # Wait before repeating loop
    sleep(5)

    # repeat loop
    print_all_data()

print_all_data()
