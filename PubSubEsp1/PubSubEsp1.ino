


#include <WiFi.h>
#include <MQTT.h>

const int LEDPin1= 27;
const int LEDPin2= 26;
const int LEDPin3= 13;
const int LEDPin4= 12;

const int PIRPin1= 15;
const int PIRPin2= 16;
const int PIRPin3= 17;
const int PIRPin4= 18;


const char ssid[] = "wifiAp";
const char pass[] = "embebidos";



WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "public", "public")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("/Alumbrado");
  // client.unsubscribe("/Alumbrado");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);

  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`.
  /*if (payload =="world"){
    digitalWrite(LEDPin1, 1);
    }*/
    if (payload == "Enc4"){
    digitalWrite(LEDPin4, 1);
    }
  if(payload == "Ap4"){
      digitalWrite(LEDPin4, 0);
      }
}

void setup() {

  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  pinMode(LEDPin4, OUTPUT);
 

  pinMode(PIRPin1, INPUT);
  pinMode(PIRPin2, INPUT);
  pinMode(PIRPin3, INPUT);
  pinMode(PIRPin4, INPUT);
  
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  client.begin("public.cloud.shiftr.io", net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
  int value1= digitalRead(PIRPin1);
  int value2= digitalRead(PIRPin2);
  int value3= digitalRead(PIRPin3);
  int value4= digitalRead(PIRPin4);
  
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }
    if (millis() - lastMillis > 1000) {
    lastMillis = millis();

    if (!value4){
      client.publish("/hello","Enc1");
      }
      if (!value4 == 0){
      client.publish("/hello","Ap1");
      }


    if (!value1==1 || !value1==0){
      digitalWrite(LEDPin1, !value1);
      delay(50);
      digitalWrite(LEDPin2, !value1);
      delay(50);
  }
   
   if (!value2==1 || !value2==0){ 
    
      digitalWrite(LEDPin2, !value2);
      delay(50);
      digitalWrite(LEDPin1, !value2);
      delay(50);
      digitalWrite(LEDPin3, !value2);
      delay(50);
    }
  
    
  if (!value3==1 || !value3==0){ 
   
    digitalWrite(LEDPin3, !value3);
    delay(50);
    digitalWrite(LEDPin2, !value3);
    delay(50);
    digitalWrite(LEDPin4, !value3);
    delay(50);
    }
    
    if (!value4==1 || !value4==0){
      digitalWrite(LEDPin4, !value4);
      delay(50); 
      digitalWrite(LEDPin3, !value4);
      delay(50);
    }
    
  }
}

  

  
