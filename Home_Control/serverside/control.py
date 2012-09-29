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
api = twitter.Api(consumer_key='YOUR KEY', consumer_secret='YOUR SECRET', access_token_key='YOUR TOKEN KEY', access_token_secret='YOUR TOKEN SECRET') 

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