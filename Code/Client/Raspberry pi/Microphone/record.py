##import fileinput
##
##for line in fileinput.input():
##    print(line)



#v1 this streamer works without needing a intemediary file

from sys import stdin

from struct import unpack

import audioop

import matplotlib as plt


for line in stdin:

   for char in range(len(line)):

        def chunkify(x):
            #print(char + x)
            #print(len(line))

            incremented = char + x

            # note if there is less than 4 bytes we drop the packet

            #nb the next byte is probably in the next line so I will have
            # fix this issue also find a proper way to convert the data
            
            if(incremented < len(line)):
                return line[char + x]
            else:
                return '0'

        chunk = map(chunkify, range(4))
        

        #unpack the signed little endian bytes as ints
        print(unpack("<i", ''.join(chunk))[0])

        ## setup a live graph showing the values overtime to see if it makes sebnse


#v2 start the command from python rather than having to start it from bash


#also process the raw info into actual sound data ie decibals depending on what it is atm I think it is raw wav data


# maybe somehow get pyaudio to be best friends so we can process it properly need to be able to get decibals

# look up the wav file reader library cus I can copy it adjust it and then just feed it a raw wav string instead to get the data from it maybe
