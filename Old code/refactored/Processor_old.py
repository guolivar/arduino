def process_sensors(process, sensors):
    for index, sensor in enumerate(sensors):
        process(index, sensor)


# replace this with map reduce etc   
def repeat(callback, repetitions):

    """ This function  calls the callback the specified times """
    
    results = []
    i = 0
    while i <= repetitions:
        results.append(callback())
        i+= 1
    return results

def average(items):
    return sum(items) / len(items)

def average_10(callback):
    return average(repeat(callback, 10))

def nth_elem(items, index):
    return lambda : ( items()[index] )


def FormatVolts(volts):
    return "({}V) ".format(volts)

def format_data(data, level, volts, unit):
    # this function pulls out the data from the spi port and converts it into the relevant format according to the ConvertData callback
 
    result = str(level) + " " + FormatVolts(volts)

    value  = str(data) +  " " + unit
    return result + value
    

