
# IR sensor conversion
# formula retrieved from http://home.roboticlab.eu/en/sensor/ir_distance
# measures back to the back / middle of the sensor???

import Sensor
def Convert(data, places):

    distance = 5461 / float((data - 17) -2 -1)

    return round(distance, places)

def GetData(channel):  
    
    return Sensor.Data( channel , "cm", Convert)

    

