#include <WiFi.h>
#include <WebServer.h>

/* Put your SSID & Password */
const char* ssid = "ESP32";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(198,168,1,1);
IPAddress gateway(198,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

uint8_t LED1pin = 2;
bool LED1status = LOW;

uint8_t LED2pin = 5;
bool LED2status = LOW;

//Variables parqueos

bool P1oc = HIGH;
bool P2oc = HIGH;
int P3oc = 0;
int P4oc = 0;
int P5oc = 0;
int P6oc = 0;
int P7oc = 0;
int P8oc = 0;

int contadorParqueo = 8;

// Definir los pines para los segmentos del display de 7 segmentos
const int segmentos[] = {2, 4, 5, 18, 19, 21, 22}; // Ajusta los pines según tu configuración

void setup() {

  // Configurar los pines de los segmentos como salida
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }
  
  Serial.begin(115200);
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.on("/led2on", handle_led2on);
  server.on("/led2off", handle_led2off);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  if(LED1status)
  {digitalWrite(LED1pin, HIGH);}
  else
  {digitalWrite(LED1pin, LOW);}
  
  if(LED2status)
  {digitalWrite(LED2pin, HIGH);}
  else
  {digitalWrite(LED2pin, LOW);}

  if(P1oc == HIGH){

    contadorParqueo = contadorParqueo - 1;
    
    }

   mostrarNumero(contadorParqueo);
}

void mostrarNumero(int numero) {
  // Definir patrones de segmentos para cada número
  const int patrones[9][8] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 0, 0, 0, 1, 1, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}  // 8
  };

  // Activar los segmentos correspondientes al número actual
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], patrones[numero][i]);
  }
}

void handle_OnConnect() {
  LED1status = LOW;
  LED2status = LOW;
  Serial.println("GPIO4 Status: OFF | GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,LED2status)); 
}

void handle_led1on() {
  LED1status = HIGH;
  Serial.println("GPIO4 Status: ON");
  server.send(200, "text/html", SendHTML(true,LED2status)); 
}

void handle_led1off() {
  LED1status = LOW;
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(false,LED2status)); 
}

void handle_led2on() {
  LED2status = HIGH;
  Serial.println("GPIO5 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status,true)); 
}

void handle_led2off() {
  LED2status = LOW;
  Serial.println("GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t led1stat,uint8_t led2stat){
String ptr = "<!DOCTYPE html>\n";
ptr += "<html>\n";
ptr += "<head>\n";
ptr += "  <title>Control de Parqueos en Estacionamiento</title>\n";
ptr += "  <style>\n";
ptr += "    body {\n";
ptr += "      background-color: black; /* Fondo negro */\n";
ptr += "      color: white; /* Letras blancas */\n";
ptr += "      font-family: \"Lobster Two\"; \n";
ptr += "      font-size: 30px;\n";
ptr += "      text-align: center;\n";
ptr += "      position: relative;\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .line {\n";
ptr += "      position: absolute;\n";
ptr += "      background-color: white;\n";
ptr += "      height: 7px; /* Grosor de la línea */\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .horizontal-line {\n";
ptr += "      width: 80%; /* Longitud de la línea horizontal */\n";
ptr += "      top: 600%; /* Posición vertical en el centro */\n";
ptr += "      left: 10%; /* Ajuste para centrar horizontalmente */\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .vertical-line1 {\n";
ptr += "      width: 8px; /* Grosor de la línea vertical */\n";
ptr += "      height: 800%; /* Longitud de la línea vertical */\n";
ptr += "      left: 50%; /* Posición horizontal en el centro */\n";
ptr += "      top: 200%; /* Ajuste para centrar verticalmente */\n";
ptr += "      transform: translateX(-50%); /* Ajuste para centrar correctamente */\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .vertical-line-left {\n";
ptr += "      width: 8px; /* Grosor de la línea vertical */\n";
ptr += "      height: 800%; /* Longitud de la línea vertical */\n";
ptr += "      left: 30%; /* Posición horizontal a la izquierda */\n";
ptr += "      top: 200%; /* Ajuste para centrar verticalmente */\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .vertical-line-right {\n";
ptr += "      width: 8px; /* Grosor de la línea vertical */\n";
ptr += "      height: 800%; /* Longitud de la línea vertical */\n";
ptr += "      left: 70%; /* Posición horizontal a la derecha */\n";
ptr += "      top: 200%; /* Ajuste para centrar verticalmente */\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .circle1 {\n";
ptr += "      position: absolute;\n";
ptr += "      width: 50px;\n";
ptr += "      height: 50px;\n";

if(P1oc == HIGH)
{ptr += "      background-color: red;\n";}
else
{ptr += "      background-color: green;\n";}

ptr += "      border-radius: 50%;\n";
ptr += "      top: 400%; /* Posición vertical en el centro */\n";
ptr += "      left: 20%; /* Posición horizontal en el centro */\n";
ptr += "      transform: translate(-50%, -50%);\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .circle2 {\n";
ptr += "      position: absolute;\n";
ptr += "      width: 50px;\n";
ptr += "      height: 50px;\n";
if(P2oc == HIGH)
{ptr += "      background-color: red;\n";}
else
{ptr += "      background-color: green;\n";}
ptr += "      border-radius: 50%;\n";
ptr += "      top: 400%; /* Posición vertical en el centro */\n";
ptr += "      left: 40%; /* Posición horizontal en el centro */\n";
ptr += "      transform: translate(-50%, -50%);\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .circle3 {\n";
ptr += "      position: absolute;\n";
ptr += "      width: 50px;\n";
ptr += "      height: 50px;\n";
if(P3oc == HIGH)
{ptr += "      background-color: red;\n";}
else
{ptr += "      background-color: green;\n";}
ptr += "      border-radius: 50%;\n";
ptr += "      top: 400%; /* Posición vertical en el centro */\n";
ptr += "      left: 60%; /* Posición horizontal en el centro */\n";
ptr += "      transform: translate(-50%, -50%);\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .circle4 {\n";
ptr += "      position: absolute;\n";
ptr += "      width: 50px;\n";
ptr += "      height: 50px;\n";
if(P4oc == HIGH)
{ptr += "      background-color: red;\n";}
else
{ptr += "      background-color: green;\n";}
ptr += "      border-radius: 50%;\n";
ptr += "      top: 400%; /* Posición vertical en el centro */\n";
ptr += "      left: 80%; /* Posición horizontal en el centro */\n";
ptr += "      transform: translate(-50%, -50%);\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .circle5 {\n";
ptr += "      position: absolute;\n";
ptr += "      width: 50px;\n";
ptr += "      height: 50px;\n";
if(P5oc == HIGH)
{ptr += "      background-color: red;\n";}
else
{ptr += "      background-color: green;\n";}
ptr += "      border-radius: 50%;\n";
ptr += "      top: 800%; /* Posición vertical en el centro */\n";
ptr += "      left: 20%; /* Posición horizontal en el centro */\n";
ptr += "      transform: translate(-50%, -50%);\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .circle6 {\n";
ptr += "      position: absolute;\n";
ptr += "      width: 50px;\n";
ptr += "      height: 50px;\n";
if(P6oc == HIGH)
{ptr += "      background-color: red;\n";}
else
{ptr += "      background-color: green;\n";}
ptr += "      border-radius: 50%;\n";
ptr += "      top: 800%; /* Posición vertical en el centro */\n";
ptr += "      left: 40%; /* Posición horizontal en el centro */\n";
ptr += "      transform: translate(-50%, -50%);\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .circle7 {\n";
ptr += "      position: absolute;\n";
ptr += "      width: 50px;\n";
ptr += "      height: 50px;\n";
if(P7oc == HIGH)
{ptr += "      background-color: red;\n";}
else
{ptr += "      background-color: green;\n";}
ptr += "      border-radius: 50%;\n";
ptr += "      top: 800%; /* Posición vertical en el centro */\n";
ptr += "      left: 60%; /* Posición horizontal en el centro */\n";
ptr += "      transform: translate(-50%, -50%);\n";
ptr += "    }\n";
ptr += "\n";
ptr += "    .circle8 {\n";
ptr += "      position: absolute;\n";
ptr += "      width: 50px;\n";
ptr += "      height: 50px;\n";
if(P8oc == HIGH)
{ptr += "      background-color: red;\n";}
else
{ptr += "      background-color: green;\n";}
ptr += "      border-radius: 50%;\n";
ptr += "      top: 800%; /* Posición vertical en el centro */\n";
ptr += "      left: 80%; /* Posición horizontal en el centro */\n";
ptr += "      transform: translate(-50%, -50%);\n";
ptr += "    }\n";
ptr += "\n";
ptr += "  </style>\n";
ptr += "</head>\n";
ptr += "<body>\n";
ptr += "  <h1>CONTROL DE PARQUEOS &#128665;</h1>\n";
ptr += "\n";
ptr += "  <div class=\"line horizontal-line\"></div>\n";
ptr += "  <div class=\"line vertical-line1\"></div>\n";
ptr += "  <div class=\"line vertical-line-left\"></div>\n";
ptr += "  <div class=\"line vertical-line-right\"></div>\n";
ptr += "  <div class=\"circle1\"></div>\n";
ptr += "  <div class=\"circle2\"></div>\n";
ptr += "  <div class=\"circle3\"></div>\n";
ptr += "  <div class=\"circle4\"></div>\n";
ptr += "  <div class=\"circle5\"></div>\n";
ptr += "  <div class=\"circle6\"></div>\n";
ptr += "  <div class=\"circle7\"></div>\n";
ptr += "  <div class=\"circle8\"></div>\n";
ptr += "\n";
ptr += "</body>\n";
ptr += "</html>";

  return ptr;
}
