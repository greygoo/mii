#include <RH_RF69.h>
#include <RHReliableDatagram.h>
#include "UC121902-TNARX-A.h"
//#include <RH_RF22.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "rfchat.h"
#include "index.html.h"

// Define max size per sent packet
#define DEBUG true 

// set default address to 0;
int ID = 0;

// AP credentials
const char *ssid = "mii-devel";
const char *password = "changeme";

// Array to hold messages,
uint8_t inBytes[RH_RF69_MAX_MESSAGE_LEN];
//uint8_t status[5];
int i = 0;
uint8_t dest;
bool showrssi = 1;
bool dotest = 0;

//Instance for display
UC121902_TNARX_A::Display display(D3, D1, D0);

// Instance of radio driver
//RH_RF22 driver;
RH_RF69 driver(D8, D2);
// Class to manage messages
RHReliableDatagram manager(driver, ID);

// start webserver
ESP8266WebServer server(80);

void handle_index_html() {
  server.send_P(200, "text/html", index_html);
}

void handle_not_found() {
  server.send(404, "text/plain", "File Not Found");
}

void setup() {
  display.begin();
  Serial.begin(9600);
  //while (!Serial)
  //  ;
  Serial.println("Serial port initialized");
  display.print("Serial port initialized");
  if ( !manager.init() ) {
    Serial.println("RH69 init failed");
    display.print("RH69 init failed");
  } else {
    Serial.println("RH96 init ok");
    display.print("RH96 init ok");
  }
  driver.setTxPower(20, true);
  if (!driver.setFrequency(868.0))
    Serial.println("setFrequency failed");
  //if (!driver.setModemConfig(RH_RF69::FSK_Rb2_4Fd4_8))
  //  Serial.println("setModemConfig failed");

  // Setup AP
  WiFi.softAP(ssid, password);
  IPAddress apIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(apIP);

  // configure webserver and start it
  server.on("/", handle_index_html);
  server.onNotFound(handle_not_found);
  server.begin();
  Serial.println("HTTP server started");

}

// Buffer for received messages
uint8_t buf[RH_RF69_MAX_MESSAGE_LEN];

void loop() {
  // check for data on serial port
  if ( Serial.available() > 0 ) {
    inBytes[i] = Serial.read();
    if ( DEBUG ) Serial.println((char*)inBytes);
    if ( DEBUG ) Serial.println(inBytes[i]);

    if ( inBytes[i] == 10 || i == RH_RF69_MAX_MESSAGE_LEN ) {
      // Copy serial buffer array to output as casting it to char breaks the sendtoWait call
      inBytes[i + 1] = '\0';
      uint8_t output[RH_RF69_MAX_MESSAGE_LEN];
      memcpy(output, inBytes, i + 1);
      output[i + 1] = '\0';

      // Enter command mode if leading character in serial buffer array is "/"
      if ( inBytes[0] == 47 ) {
        command(inBytes[1]);
      }
      else {
        // send mode
        if (showrssi) {
          showRssi();
        }
        Serial.print(ID);
        Serial.print("->");
        Serial.print(dest);
        Serial.print(": ");
        Serial.print((char*)output);

        rfsend();
      }
      i = 0;
    }
    else {
      i++;
    }
  }
  // check if testmode is set and start sending packets every 5 seconds
  if ( dotest == 1 ) {
    inBytes[0] = 48;
    rfsend();
    delay(500);
  }
  else { 
    rfreceive();
    showRssi();
  }
}

void testmode() {
  if ( inBytes[2] == 49 ) {
    Serial.println("Entering testmode");
    dotest = 1;
  } 
  else {
    Serial.println("Leaving testmode");
    dotest = 0;
  }
}

void rfsend() {
  //if ( DEBUG ) Serial.println("Send mode");
  if ( manager.sendtoWait(inBytes, sizeof(inBytes), dest) && DEBUG ) {
    Serial.println("DEBUG: Message sent successfully");
  }
  else {
    Serial.println("SendtoWait failed");
  }
}


void rfreceive() {
  //if ( DEBUG ) Serial.println("Receive mode");
  if ( manager.available() ) {
    if ( DEBUG ) Serial.println("DEBUG: Got something in the rf buffer");

    uint8_t len = sizeof(buf);
    uint8_t from;

    if ( manager.recvfromAck(buf, &len, &from) ) {
      if ( showrssi ) {
        showRssi();
      }
      Serial.print(from);
      Serial.print(" ");
      Serial.println((char*)buf);
      //display.print((char*)buf);
    }
    else {
      Serial.println("fetching from RF device buffer failed");
      display.print("no signal");
    }
  }
}


/*void rfstatus() {
  if ( !( status[0] = driver.statusRead()) ) {
    Serial.println("can't read status");
  }
  if ( !(status[1] = driver.adcRead()) ) {
    Serial.println("can't read ADC");
  }
  if ( !(status[2] = driver.temperatureRead()) ) {
    Serial.println("can't read temperature");
  }
  if ( !(status[3] = driver.wutRead()) ) {
    Serial.println("can't read wut");
  }
  if ( !(status[4] = driver.ezmacStatusRead()) ) {
    Serial.println("can't read ezmacStatus");
  }
  }
*/

/*void printstatus() {
  Serial.print("Staus: ");
  Serial.println(status[0]);
  Serial.print("ADC: ");
  Serial.println(status[1]);
  Serial.print("Temperature: ");
  Serial.println(status[2]);
  Serial.print("WUT: ");
  Serial.println(status[3]);
  Serial.print("ezmacStatus: ");
  Serial.println(status[4]);
  }*/


void showRssi() {
  //if ( DEBUG ) Serial.println("RSSI mode");
  uint8_t rssi = driver.lastRssi();
  //if ( DEBUG ) Serial.print("(RSSI: ");
  //if ( DEBUG ) Serial.print(rssi);
  //if ( DEBUG ) Serial.print(") ");
  display.print(rssi);
}


void setdestination() {
  uint16_t tmp = retrieveAddress(inBytes);
  if ( DEBUG ) Serial.println(tmp);
  if ( tmp >= 0 && tmp <= 255 ) {
    dest = tmp;
  }
  if ( DEBUG ) {
    Serial.print("Setting destination address to: ");
    Serial.println(dest);
  }
}


void setID() {
  uint8_t tmp = retrieveAddress(inBytes);
  if ( DEBUG ) Serial.println(tmp);
  if ( tmp >= 0 && tmp <= 255 ) {
    ID = tmp;
  }
  if ( DEBUG ) {
    Serial.print("Setting ID to: ");
    Serial.println(ID);
  }
}


void rssiswitch() {
  if ( isInteger(inBytes[2]) ) {
    uint8_t option = inBytes[2] - 48;
    if ( DEBUG ) Serial.println(option);
    switch ( option ) {
      case 0:
        Serial.println("Not showing RSSI values");
        showrssi = false;
        break;
      case 1:
        Serial.println("Showing RSSI values");
        showrssi = true;
        break;
      default:
        Serial.print("Not a valid command option: ");
        Serial.println(option);
        break;
    }
    if ( DEBUG ) Serial.println(showrssi);
  }
}


uint16_t retrieveAddress(uint8_t asciiArray[]) {
  uint16_t address;

  if ( isInteger( asciiArray[2]) && isInteger(asciiArray[3]) && isInteger(asciiArray[4]) ) {
    address = (( asciiArray[2] - 48 ) * 100) + (( asciiArray[3] - 48 ) * 10) + asciiArray[4] - 48;
    if ( DEBUG ) Serial.println(address);
    return address;
  }
  if ( isInteger( asciiArray[2]) && isInteger(asciiArray[3]) && !(isInteger(asciiArray[4])) ) {
    address = (( asciiArray[2] - 48 ) * 10) + asciiArray[3] - 48;
    if ( DEBUG ) Serial.println(address);
    return address;
  }
  if ( isInteger( asciiArray[2]) && !(isInteger(asciiArray[3])) && !(isInteger(asciiArray[4])) ) {
    address = asciiArray[2] - 48;
    if ( DEBUG ) Serial.println(address);
    return address;
  }
  Serial.println("Not a valid address");
  return 256;
}


bool isInteger(uint8_t var) {
  if ( DEBUG ) Serial.println(var);

  if ( var >= 48 && var < 58 ) {
    return true;
  }
  return false;
}


void command(uint8_t command) {
  // command mode
  if ( DEBUG ) Serial.println("entering command mode");

  switch ( command ) {
    case 48:
      setdestination();
      break;
    case 49:
      setID();
      break;
    //  case 50:
    //    rfstatus();
    //    printstatus();
    //    break;
    case 51:
      rssiswitch();
      break;
    case 52:
      testmode();
      break;
    default:
      Serial.println("Not a valid command");
      break;
  }
}

