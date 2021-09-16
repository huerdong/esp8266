The code here is very barebone to demonstrate very basic 
functionality in the ESP8266 chip. Originally designed for for USC EE capstone
459 course. 

I do not use the ESP8266 TX line directly in this code so users will need to 
fill in the blanks here or use an oscilloscope to monitor outputs (Which is 
what I did). 

1. test_serial - Used to validate that the chip is indeed responding 
to serial commands with a stream of AT+GMR commands

2. connect_wifi - Connects to USC wireless network then sends a stream of 
pings to google.com to check if online

3. continuous_connect - Demonstrates that wifi AP is saved even after powering 
via pings to google.com

4. disconnect_wifi - Demonstrates that online access is indeed disabled when
wifi is disconnected

5. download_webpage - Makes a TCP connection on port 80 (HTTP) to a website,
and makes a request to download a simple page
