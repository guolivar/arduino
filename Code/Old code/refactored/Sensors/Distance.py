
# IR sensor conversion
# formula retrieved from http://home.roboticlab.eu/en/sensor/ir_distance
# measures back to the back / middle of the sensor???

from Sensor import ReadChannel, ConvertVolts

unit = "cm"

def Convert(data):

    if( data > 0 ):
    
        min_17 = data - 17
        divisor = float( min_17 -2)
        distance = 5461 / divisor

       # distance = 16.2537 * data **4 - 129.893 + data **3 + 382.268 * data ** 2 - 512.611 * data + 306.439

        #distance =  2583.711122992086 - 20.197897855471*data + 0.071746539329 *data*data- 0.000115854182 *data*data*data + 0.000000068590 *data*data*data*data
        return distance
    else:
        return 0


def GetData(channel):  
    return Convert(ReadChannel(channel))
    

def GetVolts(channel):
    return ConvertVolts(ReadChannel(channel))

def GetLevel(channel):
    return ReadChannel(channel)