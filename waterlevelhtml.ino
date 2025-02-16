#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
WiFiClient wificlient;
ESP8266WiFiMulti wifiMulti;

#define Float 5
#define relay 4
HTTPClient http;    //Declare object of class HTTPClient

String  Link1, Link2, c, payload1, payload2, getData, getData2;
int httpCode1, httpCode2,a=11;
int p1;


void setup() {
  pinMode(Float,INPUT_PULLUP);
  pinMode(relay,OUTPUT);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  //wifiMulti.addAP("Kiran89192", "8892@Kiran");
  //wifiMulti.addAP("kmrkrmd", "kmrkkmrk");
  //wifiMulti.addAP("oneplus", "12345678");
  //wifiMulti.addAP("Redmi 7", "shamammu");
  //wifiMulti.addAP("Redmi 9A", "12345678");
  wifiMulti.addAP("Teju","12345678");
  
  
  
  Serial.print("Connecting");  // Wait for connection
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address: "); 

  Serial.println(WiFi.localIP());  
  delay(200); 
}


void loop()
{
 delay(100);
 int var=digitalRead(Float);
 if(var==HIGH)
 {
  Serial.println("Tank is full"); 
 }
 else
 {
  Serial.println("Normal");
 }
  
  getData= String(var);//http://192.168.184.158:5000
  Serial.println(getData);
  Link2 ="http://192.168.184.158:5000/add/"+getData; //http://192.168.184.158:5000
  http.begin(wificlient,Link2);
  httpCode1 = http.GET();
  payload1 = http.getString();
  Serial.println(httpCode1);
  Serial.println(payload1);
  if(payload1 == "1")
  {
    digitalWrite(relay,LOW);
  }
  if(payload1 == "0")
  {
    digitalWrite(relay,HIGH);
  }
  delay(2000);
    
  }

  
  
  
