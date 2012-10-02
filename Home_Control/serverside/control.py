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
info = __import__("config")

##Authenticate with Twitter API
api = twitter.Api(consumer_key=info.consumer_key, consumer_secret=info.consumer_secret, access_token_key=info.access_token_key, access_token_secret=info.access_token_secret)

##Configure Serial Port
arduino = serial.Serial(info.serial_port, 9600)

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
        if "1" in status:
            timestamp = time.time()
        else:
            print "invalid status: "+status

    if (time.time() - lastFetchTime > mentionsInterval):
        timestamp = time.time()
        time_tuple = time.localtime(timestamp)
        time_str = time.strftime("%d-%m-%Y %H:%M:%S")
        print "getting replies ("+time_str+")"
        replies = api.GetReplies()
        if(replies[0].id > lastMention):
            print "new reply: "
            print replies[0].text
            if("lights on" in replies[0].text):
                arduino.write("0")
            elif("lights off" in replies[0].text):
                arduino.write("1")
            elif("reset status" in replies[0].text):
                lastStatus = "null";
            lastMention = replies[0].id
            
        lastFetchTime = time.time()