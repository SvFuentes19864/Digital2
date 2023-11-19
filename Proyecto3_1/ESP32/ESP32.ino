#include <Arduino.h>

// Definir los pines para los segmentos del display de 7 segmentos
const int segmentos[] = {2, 4, 5, 18, 19, 21, 22}; // Ajusta los pines según tu configuración

void setup() {
  // Configurar los pines de los segmentos como salida
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }

  // Inicializar la comunicación serial
  Serial.begin(115200);
}

void loop() {
  for (int numero = 0; numero <= 8; numero++) {
    mostrarNumero(numero);
    delay(1000);
  }
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
