
# IR sensor conversion
# formula retrieved from http://home.roboticlab.eu/en/sensor/ir_distance
# measures back to the back / middle of the sensor???

import Sensor
def Convert(data, places):
#return round ( 5461 / (data - 17) -2, places)

# subtracting 1 extra to compensate for it being 1 too large ?
# return round ( 5461 / (data - 17) -3, places)

    # maybe this will give us mm??? look into it
    return 5461 / float((data - 17) -2 -1)

def GetData():  
    
    return Sensor.Data( 2 , "cm", Convert)

    

