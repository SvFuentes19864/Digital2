void setup() {
  // Inicializar la comunicación serial a 115200 baudios
  Serial.begin(115200);
  
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
        Serial.println("Ingrese 'm' para volver al menú principal");
        break;
        
      case '2':
        Serial.println("Has seleccionado la Opción 2");
        Serial.println("Ingrese 'm' para volver al menú principal");
        break;
        
      case '3':
        Serial.println("Has seleccionado la Opción 3");
        Serial.println("Ingrese 'm' para volver al menú principal");
        break;

      case 'm':
      case 'M':
        // Si el usuario presiona 'm' o 'M', mostrar el menú nuevamente
        imprimirMenu();
        break;
        
      default:
        break;  // Agrega un break aquí para corregir el error de compilación
    }
  }
}

void imprimirMenu() {
  Serial.println("Menu:");
  Serial.println("1. Opción 1");
  Serial.println("2. Opción 2");
  Serial.println("3. Opción 3");
}
