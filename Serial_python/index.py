import serial
import time

arduino = serial.Serial("/dev/tty.usbmodemfd121", 9600);

while 1:
    incoming = arduino.readline()
    if("hello python!" in incoming):
        arduino.write('0');
    else: 
        print "incoming: "
        print incoming

