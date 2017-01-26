
def ConvertDistance(data, places = 2):
  #return round ( 5461 / (data - 17) -2, places)

  # subtracting 1 extra to compensate maybe it's just the hardware???
  #return round ( 5461 / float((data - 17) -3), places)
  return round ( 5461 / float((data - 17) -2), places)
  #return 13.5/ volts

  #return (16.2537 * v ** 4) - ( 129.893 * v ** 3 )+ ( 382.268 * v ** 2 )  - ( 512.611 * v )+ 306.439

def test_distance():
    print(ConvertDistance(2.5))

test_distance()