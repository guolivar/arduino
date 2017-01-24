
import spidev
import os

# Open SPI bus
spi = spidev.SpiDev()
spi.open(0,0)

def FormatVolts(volts):
    return "({}V) ".format(volts)


def ReadChannel(channel):

    # Function to read SPI data from MCP3008 chip
    # Channel must be an integer 0-7

    adc = spi.xfer2([1,(8+channel)<<4,0])
    data = ((adc[1]&3) << 8) + adc[2]
    return data
    
def ConvertVolts(data,places):

    # Function to convert data to voltage level,
    # rounded to specified number of decimal places.

    volts = (data * 3.3) / float(1023)
    volts = round(volts,places)
    return volts

def Data (channel, ConvertData):
    # this function pulls out the data from the pdi port and converts it into the relevant format according to the ConvertData callback
    level = ReadChannel(channel)
    volts = ConvertVolts(level,2)


    data = ConvertData(level,2)

    return data, level, volts

##    if not ConvertData is None:
##        value  = str(ConvertData(level,2)) +  " " + unit
##        return data + value
##    
##    else:
##        return data

    
