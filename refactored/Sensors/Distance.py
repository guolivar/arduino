
# IR sensor conversion
# formula retrieved from http://home.roboticlab.eu/en/sensor/ir_distance
# measures back to the back / middle of the sensor???

import Sensor
def Convert(data, places):

    min_17 = data - 17
    divisor = float( min_17 -2)
    distance = 5461 / divisor

   # distance = 16.2537 * data **4 - 129.893 + data **3 + 382.268 * data ** 2 - 512.611 * data + 306.439

    #distance =  2583.711122992086 - 20.197897855471*data + 0.071746539329 *data*data- 0.000115854182 *data*data*data + 0.000000068590 *data*data*data*data
    return round(distance, places)

def GetData(channel):  
    
    return lambda : ( Sensor.Data( channel, Convert) )

    

