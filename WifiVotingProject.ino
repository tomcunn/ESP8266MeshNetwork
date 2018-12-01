#include <ESP8266WiFi.h>
#include <WiFiClient.h> 

const char *ssid = "XXXXXXX";
const char *password = "XXXXXX";
const char* host = "192.168.0.173";
const int port = 10000;

WiFiClient client;

void setup() 
{
  pinMode(BUILTIN_LED,OUTPUT);
  pinMode(D4,OUTPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  delay(1000);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to network ");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED) 
  {
    digitalWrite(BUILTIN_LED, HIGH);
    delay(500);
    Serial.print(".");
    digitalWrite(BUILTIN_LED,LOW);
    delay(500);
  }
 
  digitalWrite(D0, HIGH);
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println();
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());

  //Connect to the server
  if (!client.connect(host, port)) 
  {
    Serial.println("WIFI connection failed");
  }
  else
  {
    Serial.println("port open");  
     
  }  
  client.setTimeout(100);
}

void loop() 
{

  //Feed the watchdog
  ESP.wdtFeed();
  digitalWrite(D4,HIGH);
  delay(1000);
  digitalWrite(D4,LOW);
  delay(1000);
}

