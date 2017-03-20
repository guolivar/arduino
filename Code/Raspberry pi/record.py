##import fileinput
##
##for line in fileinput.input():
##    print(line)



#v1 this streamer works without needing a intemediary file

from sys import stdin

for line in stdin:
    print(line)

#v2 start the command from python rather than having to start it from bash


#also process the raw info into actual sound data ie decibals depending on what it is atm I think it is raw wav data


# maybe somehow get pyaudio to be best friends so we can process it properly need to be able to get decibals

# look up the wav file reader library cus I can copy it adjust it and then just feed it a raw wav string instead to get the data from it maybe