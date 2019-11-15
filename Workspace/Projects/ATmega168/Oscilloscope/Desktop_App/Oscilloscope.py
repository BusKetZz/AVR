
import serial

def ReadValue(serialPort):
    return (ord(serialPort.read(1)))

def PlotValue(value):
    leadingSpaces = " " * (value*(SCREEN_WIDTH-3) / 255)
    print "%s%3i" % (leadingSpaces, value)

def Oscilloscope(serialPort):
    while(1):
        sample = ReadValue(serialPort)
        PlotValue(sample)


if __name__ == "__main__":

    PORT = '/dev/tty.usbserial-AH070549'
    BAUDRATE = 9600
    TIMEOUT = None
    SCREEN_WIDTH = 80

    serialPort = serial.Serial(PORT, BAUDRATE, timeout=TIMEOUT)
    serialPort.flush()
    Oscilloscope(serialPort)
    