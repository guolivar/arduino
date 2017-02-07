
-- This file stores all our personal functions that don't rely on SPI so that we can unit test 
-- @author: Ryan Weyers 

 
-- Function to convert data to voltage level,  rounded to specified number of decimal places.
toVolts adc = (adc * 3.3) / 1023
  


   -- IR sensor conversion
 -- formula retrieved from http://home.roboticlab.eu/en/sensor/ir_distance
-- measures back to the back / middle of the sensor???

-- seems to be 1 cm too large all the time

-- import Data.Optional

-- to_distance :: float, Optional int -> float
-- to_distance v, (Specific places)  = round(16.2537 * v ** 4 - 129.893 * v ** 3 + 382.268 * v ** 2 - 512.611 * v + 306.439, places)
-- to_distance v, default = 16.2537 * v ** 4 - 129.893 * v ** 3 + 382.268 * v ** 2 - 512.611 * v + 306.439

 -- point num volts power = num * volts ** power

-- to_distance volts = point 16.2537 volts 4 - point 129.893 volts 3 + point 382.268 volts 2 - point 512.611 volts + 306.439

toDistance volts = 16.2537 * volts ** 4 - 129.893 * volts ** 3 + 382.268 * volts ** 2 - 512.611 * volts + 306.439
   --return round ( 5461 ÷ (data - 17) -2, places)

   -- subtracting 1 extra to compensate maybe it's just the hardware???
   --return round ( 5461 ÷ float((data - 17) -3), places)  
   --return round ( 5461 ÷ float((data - 17) -2), places)
   --return 13.5 ÷ volts

  --return 65 * (volts ↑ -1.10)

  --return (4.104815014 * 10 ** -12) * (x**10) - (7.50448734 * 10 ** -10 ) * (x**9) + (5.754181221*10**-8) * (x**8) - 2.386526798·10-6 x7 + 5.700833884·10-5 x6 - 7.452731288·10-4 x5 + 3.565112317·10-3 x4 + 3.087640411·10-2 x3 - 4.920343313·10-1 x2 + 2.002517114 x + 2.206473192·10-1

-- resolve = list ∘ map

convert items =
  --- Takes the first arg and runs the next arg on it and stores the result in a final list 
  result = []
  result.append items[0]

  append = result.append ∘ resolve
  
  append items[1] items[0]
  append items[2] result[1]

  return result


--from time import sleep, asctime, localtime, time

--from datetime import datetime

 -- get_time = asctime ∘ localtime ∘ time

-- get_time_stamp = localti

-- save text =
--   log = open "Log.txt" "a"
--   info = text + " " + getCurrentTime
--    --more efficient than the normal way of writing it because we don't concatenate to make a new string in memory
--   resolve log.write info "\n"
--   log.close

--    --we return the data for unit testing purposes 
--   return info


 --  times(funct, repetitions =100) = resolve( → funct(), range(repetitions))

  -- funct `times` repetitions = resolve( → funct(), range(repetitions))

--add = fold$(+)

mean items = sum items / Length items


format distance = "Distance %d: %d (%dV) %d cm" distance

 -- from Vendor import demjson
 -- import json
 --   retrieve_data(file_name):

 --     file = open(file_name)
 --     result = json.load(file)
 --     file.close()
 --     return result

 --   store_data(file_name, data):
 --     file = open(file_name, "w")
 --      -- write to file note cwd is the root of he vscode project    

 --     json = demjson.encode(data)
 --     file.write(json)
 --     file.close()

