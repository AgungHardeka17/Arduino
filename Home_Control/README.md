# Home Control 
_Control stuff in your house via twitter_
This project is created to have Arduino communicate about things via Twitter.  
Right now it's possible for Arduino to know when it's getting dark in a space, and to notify me by sending me an @ mention. When I reply with a string that contains "Lights on", a LED turns on. When I send my Arduino a message that contains "Lights off, the LED goes off".

I'm looking to expand this project with real lights and a remote. Also I might add more functions later (like temperature for example.)

## Libraries used
I used some libraries to come up with the result. Your dependancies are:

* [pyserial](http://pyserial.sourceforge.net) for reading/write your Arduino's Serial data
* [python-twitter](http://code.google.com/p/python-twitter/) a wrapper for communication between Twitter and Python

## Instructions
You can apply for a Twitter API key here: [https://dev.twitter.com/apps/new](https://dev.twitter.com/apps/new).

In order to get this to work you need to create a config file of your own. The config file should be called 'config.py' and contain the following content:
* consumer_key='YOUR KEY'
* consumer_secret='YOUR SECRET'
* access_token_key='YOUR TOKEN KEY'
* access_token_secret='YOUR TOKEN SECRET'
* serial_port='YOUR USB PORT'
