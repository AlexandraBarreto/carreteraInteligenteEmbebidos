# include <WebServer.h>

const char* ssid = "wifiAP";
const char* password = "embebidos" ;

IPAddress ip (192,168,4,22);
IPAddress gateway (192,168,4,9);
IPAddress subnet (255,255,255,0);

WebServer server(80);

void setup(){
  Serial.begin(115200);
  
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(ip, gateway, subnet);
  IPAddress ip = WiFi.softAPIP();
  Serial.println(ip);

  Serial.print ("Red esp32:");
  Serial.println (ssid);

  server.on("/", handleConnectionRoot);
  server.begin();
  Serial.println("Servidor HTTP iniciado");
  delay(150);
}

void loop() {
  server.handleClient();
}
String answer = "< !DOCTYPE html>\
<html>\
<body>\
<h1>Hola desde ESP32 \
</body>\
</html>";

void handleConnectionRoot(){
  server.send(200, "text/html",answer);
}
