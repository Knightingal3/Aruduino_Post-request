/**************************************************************
* Authour: Anike Arnize Victor
* Date_Created: 18th September 2020
* Objective: A Simple HttpClient Post requset using Arduino and 
*	     Sim800 as ISP
****************************************************************/

// Select your modem ---------------------------------------------

	#define TINY_GSM_MODEM_SIM800

// Enabling AT Commands to display on serial monitor--------------
	#define DUMP_AT_COMMANDS

// Using Software Serial ------------------------------------------

	#include <SoftwareSerial.h>
	SoftwareSerial SerialAT(2, 3); // RX, TX


// Define how you're planning to connect to the internet ----------
	
	#define TINY_GSM_USE_GPRS true


// Your GPRS APN Configuration "user" and "pass" is optional -------

	const char apn[]  = "web.gprs.mtnnigeria.net";
	const char user[] = "web";
	const char pass[] = "web";


// Server details ---------------------------------------------------

	const char server[] = "serverIP";
	const char resource[] = "api_root_url/";
	const int  port = 8080;

// Importing httpClient libraries --------------------------------------

	#include <TinyGsmClient.h>
	#include <ArduinoHttpClient.h>

// Enabling the Debugger using serial monitor ---------------------------

	#ifdef DUMP_AT_COMMANDS
	#include <StreamDebugger.h>
	StreamDebugger debugger(SerialAT, SerialMon);
	TinyGsm        modem(debugger);
	#else
	TinyGsm modem(SerialAT);
	#endif
	
// Connecting to the Server -----------------------------------------------

	TinyGsmClientSecure gprs_con(modem);
	HttpClient client = HttpClient(gprs_con, server, port);


 void setup(){

  // Set Serial Monitor baud rate ------------------------------------
  		
	SerialMon.begin(115200);
  	delay(10);

  // Set GSM module baud rate -----------------------------------------
  	
	SerialAT.begin(115200);
  	delay(3000);

  
  SerialMon.println("Initializing modem...");
  modem.restart();
 
 // Displays modemInfo on the console -----------------------------------	

  	String modemInfo = modem.getModemInfo();
  	SerialMon.print(F("Modem: "));
  	SerialMon.println(modemInfo);


	}

 void loop() {


  	#if TINY_GSM_USE_GPRS

 // Attempting GPRS Connection -----------------------------------------

    SerialMon.print(F("Connecting to "));
    SerialMon.print(apn);

    if (!modem.gprsConnect(apn, gprsUser, gprsPass)) {
     	
	 SerialMon.println(" fail");
     	 delay(10000);
      	 return;
    		}

    SerialMon.println(" success");

    if (modem.isGprsConnected()) {
      
	SerialMon.println("GPRS connected");
    		
		}
	#endif

 // Attempting post request --------------------------------------------

	Serial.println("making POST request");
  	String contentType = "application/x-www-form-urlencoded";
  	String postData = "name=Arinze&age=26";
	client.post(resource, contentType, postData);

 // read the status code and body of the response -------------------------

  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

  Serial.println("Wait five seconds");
  delay(5000);
  		
		}

  


