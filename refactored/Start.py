# -*- coding: utf-8 -*-
"""
Created on Mon Jan 23 2017

@author: Ryan Weyers
"""

#!/usr/bin/pypy


# standard python library
from time import sleep

from Sensors import Temp, Distance, Light, Time



def print_data(sensors):

    """ This function prints data for a specific sensor"""
    for index, sensor in enumerate(sensors):
        print sensor.__name__[8:] + ": " + sensor.GetData(index)


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
