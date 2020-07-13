## File: Boss_Button.py
##
## Author: Jakub Standarski
##
## Date: 06.11.2019
##
## Description:
## 1. Program listens indefinitely serial port
## 2. After pressing the button, program opens up specified website

BOSS_SITE = "https://www.allaboutcircuits.com/latest/"

SERIAL_PORT = "/dev/tty.usbserial-AH070549"
BAUD_RATE = 9600


import serial
import webbrowser


serialPort = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout = 5)
serialPort.flush()
print("Boss Button")

while(1):
    serialPortResponse = serialPort.read(1)

    if serialPortResponse == "0":
        print("Confirmation received, waiting for button.")
    elif serialPortResponse == "X":
        print("Watchout! Boss is coming! Alarm!")
        webbrowser.open(BOSS_SITE)
    else:
        print("Sector clear. Still waiting...")
        