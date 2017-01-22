
import time

def GetTime():
    return time.asctime(time.localtime(time.time()))


def GetData(channel):
    return "Time: " + GetTime()
