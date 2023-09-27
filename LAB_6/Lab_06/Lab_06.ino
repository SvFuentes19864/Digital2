#include <SPI.h>
#include <SD.h>

File myFile;

const int pinCS = 12; // Pin CS (Chip Select) para la tarjeta SD

void setup() {
  // Inicializar la comunicación serial a 115200 baudios
  Serial.begin(115200);

  SPI.setModule(0);

  // Inicializar la tarjeta SD
  if (!SD.begin(pinCS)) {
    Serial.println("Error al inicializar la tarjeta SD");
    return;
  }

  // Esperar a que la comunicación serial se establezca
  while (!Serial) {
    ;
  }

  imprimirMenu();
}

void loop() {
  if (Serial.available() > 0) {
    char opcion = Serial.read();

    switch (opcion) {
      case '1':
        Serial.println("Has seleccionado la Opción 1");
        mostrarArchivo("Honguito.txt");
        Serial.println("Ingrese 'm' para volver al menú principal");
        break;

      case '2':
        Serial.println("Has seleccionado la Opción 2");
        mostrarArchivo("Luigi.txt");
        Serial.println("Ingrese 'm' para volver al menú principal");
        break;

      case '3':
        Serial.println("Has seleccionado la Opción 3");
        mostrarArchivo("Yoshi.txt");
        Serial.println("Ingrese 'm' para volver al menú principal");
        break;

      case 'm':
      case 'M':
        // Si el usuario presiona 'm' o 'M', mostrar el menú nuevamente
        imprimirMenu();
        break;

      default:
        break;
    }
  }
}

void imprimirMenu() {
  Serial.println("Menu:");
  Serial.println("1. Honguito");
  Serial.println("2. Luigi");
  Serial.println("3. Yoshi");
}

void mostrarArchivo(const char *nombreArchivo) {
  myFile = SD.open(nombreArchivo);

  if (myFile) {
    Serial.println("Contenido del archivo:");

    // Leer y mostrar el contenido del archivo en la consola
    while (myFile.available()) {
      Serial.write(myFile.read());
    }

    // Cerrar el archivo
    myFile.close();
  } else {
    Serial.println("No se pudo abrir el archivo.");
  }
}
