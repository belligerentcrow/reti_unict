# Exercise 1: Sensors
Develop a Software solution that allows a Sensor Node to send some sensor data to a special Central Node. 
When a Central Node receives data from sensor, if a specific condition happens, the Central Node will send an Alarm to a Control Node.

## Sensor Node
* Can send data every 3 seconds
* Communication doesn't have to be reliable
* Sensor data could be Temperature, Humidity, Air Quality
* Every sensor must be identified by an unique ID

## Central Node
* Will store new Sensor when receives a message from it
* If the temperature is higher than 30 or air quality is poor, it must send a message to the Control Node
* The communication must be reliable

## Control Node
* Will print the Alarms
* Will store a file LOG of all alarms

## Extra (things said during the lesson)
* The sensor must advertise itself to the central server in a reliable way (TCP).
* The data must be sent in an unreliable way to the central server (UDP).
* The alarm must be noticed by the sensor, and it must send the alarm to the server reliably, with TCP.
* The server, as it acknowledges the alarm, must send to the client an order to shut down - after 5 second, the server must send to the client a command of re-activation, reliably (through TCP). 

## Extra (as suggested at lesson)
* Execute this code inside Virtual Machines. The executable must be copied inside the machine (use scp). Compile the executable with --static.
* Try to make some clients (or re-make the server) in Python. 
