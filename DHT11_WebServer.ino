#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 4
DHT dht(DHTPIN, DHT11);

const char* ssid = "ESP32_Termometro";
const char* password = "12345678password";

WebServer server(80);

void handleRoot() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  String html = "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<meta http-equiv='refresh' content='3'>";
  html += "<style>body{font-family:sans-serif; text-align:center; background:#121212; color:#fff; padding-top:50px;}";
  html += ".card{background:#1e1e1e; display:inline-block; padding:20px; border-radius:10px; min-width:250px;}";
  html += "h1{color:#00e676;}</style></head><body>";
  html += "<div class='card'>";
  html += "<h2>ESP32 - Clima</h2>";

  if (isnan(h) || isnan(t)) {
    html += "<p style='color:red;'>Error al leer el sensor DHT11</p>";
  } else {
    html += "<h1>" + String(t, 1) + " &deg;C</h1>";
    html += "<h3>Humedad: " + String(h, 1) + " %</h3>";
  }

  html += "</div></body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Configura la red local
  WiFi.softAP(ssid, password);
  Serial.println("Punto de acceso iniciado.");
  Serial.print("IP del servidor: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
