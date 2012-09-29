#**************#
# Brad Wells   #
# wellsb.com   # 
# *************#

##Import Libraries
import twitter
import serial
import time
import sched

lastMention = 0
lastStatus = 0
lastFetchTime = 0
mentionsInterval = 15

##Authenticate with Twitter API
api = twitter.Api(consumer_key='iQtIi2Ws9thbYzdVpXR9A', consumer_secret='Ah57xPprjvLWXx5Zd73F1caXD0J6G096n20dUSXo', access_token_key='842181841-htj7gl9DaWB08pJYARxDtTEdSFdqDrTEGnUydXAZ', access_token_secret='lm2eAlZwksCP3JbcmkDggFDP1LQkEMa8gACtJHSRDc4') 

##Configure Serial Port
arduino = serial.Serial('/dev/tty.usbmodemfa141', 9600)

## Get first mentions
replies = api.GetReplies()
lastMention = replies[0].id

while 1:
    status = arduino.readline()
    if (lastStatus != status):
        if "0" in status:
            lastStatus = status
            timestamp = time.time()
            time_tuple = time.localtime(timestamp)
            time_str = time.strftime("%d-%m-%Y %H:%M:%S")
            api.PostUpdate("@donnywals It's dark in here! ("+time_str+")");
        else:
            print "invalid status: "+status

    if (time.time() - lastFetchTime > mentionsInterval):
        replies = api.GetReplies()
        if(replies[0].id > lastMention):
            if("lights on" in replies[0].text):
                arduino.write("0")
            elif("lights off" in replies[0].text):
                arduino.write("1")
            lastMention = replies[0].id
            
        lastFetchTime = time.time()