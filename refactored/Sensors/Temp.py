import Sensor


# Function to calculate temperature from
# TMP36 data, rounded to specified
# number of decimal places.
def convert(data,places):

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
    temp = round(temp, places)
    return temp

def GetData(channel):
   
    return Sensor.Data(channel, "deg C", convert)

