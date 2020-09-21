# Project Objective
  The objective of this project is to make a simple post request using arduino as the client.
  Two seperate braches was created for the purpose of this project, master branch and an php_serverCode branch.
  The master branch houses the Arduino HttpClient code while the php_serverCode branch contains the PHP code for server side.
  
## Dependencies
 - ArduinoHttpClient
 - TinyGsmClient
 
### ArduinoHttpClient:
   ArduinoHttpClient is a library to make it easier to interact with web servers from Arduino.
    
### TinyGsmClient:
   TinyGsmClient is a gsm module library that makes it easy to connect to the internet 
   using the gprs capability of a gsm module, thus this enables us to make use of our local ISP 
   like MTN to gain access to the internet [Click to Download Library](https://github.com/vshymanskyy/TinyGSM)

## Usage

### Client side:
   On system activation the arduino sets the gsm module to gprs mode using the required AT Commmands
   via serial communication protocol.
   When connection between the ISP and the gsm module have been established, the arduino tries a post request 
   to the using the defiened parameters.
   
### Server Side:
   PHP is used at the server side for handling the request, first it checks for authorization.
   If the code is coming from an authorized user it processes the request and submit the data to a database 
   and sends an http response statuscode of "200".
   While if the request is not from an authorized user it rejects the request and returns User not authorized 
   to the client
   
### Pre-requisites:
  - Arduino IDE
  - WAMP/LAMP (Windows/Linux) respectively
  - TinnyGsmClient Library
  - ArduinoHttpClient Library
  
  
  
