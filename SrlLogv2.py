import os
import serial
import time
import daemon

baud = 57600
arduino = serial.Serial('/dev/ttyUSB0', baud)
inWait = 4
debug = True

#here = os.path.dirname(os.path.abspath(__file__))
folder = '/home/chris/datalogs/python_serial_logger/'
#here = '/home/pi/datalogs/'

# clear the serial buffer
while inWait > 0:
    arduino.flushInput()
    arduino.flush()
    arduino.flushOutput()
    inWait = arduino.inWaiting()

# main function
def main():
    if debug:
            print('002')
    readOne = 0
    s = True

    while True:
        if debug:
            print(003)
        now = time.localtime()
        epoch = time.time()
        if debug:
            print(004)
        data = arduino.readline()
        if readOne < 1:
            readOne = readOne + 1
            data = ""
            arduino.flushInput()
            arduino.flush()
            arduino.flushOutput()
        if debug:
            print(005)
        elif data:
            print(data)
            outf = open(fname, 'a', 0)
            outf.write(str(epoch) + time.strftime(",%y-%m-%d %H:%M:%S,", now))
            if debug:
                print(006)
            outf.write(data)
            outf.flush()
            outf.close()
        if debug:
            print(007)

if __name__ == "__main__":
    start = time.localtime()
    fname = time.strftime("%y-%m-%d %H:%M:%S", start) + '.txt'
    if debug:
        print(001)
        print(fname)
        print(folder)
    with daemon.DaemonContext(working_directory = folder, stdout = fname):
        main()
