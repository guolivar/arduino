def process_sensors(process, sensors):
    for index, sensor in enumerate(sensors):
        process(index, sensor)
        
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

def first_elem(items):
    return lambda : ( items()[0] )
            
