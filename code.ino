#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
IPAddress    apIP(192,168,43,151);
#define r1 14
#define r2 12
#define r3 13
#define r4 16
void setup() 
{
  
  Serial.begin(115200);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP("OPPO", "angadkumar");
  Serial.println();
  Serial.println("NodeMCU Started!");
  Serial.println(WiFi.softAPIP());
  server.begin();
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
}

void loop() 
{
  
  client = server.available();  
  if (client == 1)
  {  
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /led1on HTTP/1.1")
    {
      digitalWrite(r1, HIGH);
    }
    if(request == "GET /led1off HTTP/1.1")
    {
      digitalWrite(r1, LOW);
    }
    if(request == "GET /led2on HTTP/1.1")
    {
      digitalWrite(r2, HIGH);
    }
    if(request == "GET /led2off HTTP/1.1")
    {
      digitalWrite(r2, LOW);
    }
    if(request == "GET /led3on HTTP/1.1")
    {
      digitalWrite(r3, HIGH);
    }
    if(request == "GET /led3off HTTP/1.1")
    {
      digitalWrite(r3, LOW);
    }
    if(request == "GET /led4on HTTP/1.1")
    {
      digitalWrite(r4, HIGH);
    }
    if(request == "GET /led4off HTTP/1.1")
    {
      digitalWrite(r4, LOW);
    }
  }
}
