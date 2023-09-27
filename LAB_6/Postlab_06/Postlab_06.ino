#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // put your setup code here, to run once:
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  SPI.setModule(0);
  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(12, OUTPUT);

  if (!SD.begin(12)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  imprimirMenu();
}

void loop() {

  while (!Serial.available()); // Wait for user input
  int choice = Serial.read() - '0'; // Read serial

  switch (choice) {
    case 1:{        
      while (Serial.available()) {
      Serial.read();
      }
      myFile = SD.open("/");
      directorios(myFile, 0);
      printRead();
      Serial.println("Ingrese 'm' para volver al menú principal");
    }
      break;
    case 2:
      myFile = SD.open("/");
      directorios(myFile, 0);
      chooseWrite();
      Serial.println("Ingrese 'm' para volver al menú principal");
      break;
    
      break;
    default:

    case 'm':
    case 'M':
        // Si el usuario presiona 'm' o 'M', mostrar el menú nuevamente
        imprimirMenu();
        break;
    
      Serial.println("Error: Choose from 1 to 3");
  }

  while (Serial.available()) {
    Serial.read();
  }
}

void imprimirMenu() {
  Serial.println("Menu:");
  Serial.println("1. Leer");
  Serial.println("2. Escribir");
}

void readFile(char* textName){  
  // re-open the file for reading:
  myFile = SD.open(formatFileName(textName));
  if (myFile) {
    Serial.println(textName);

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error opening file");
  }
}

void directorios(File dir, int numTabs) {
   dir.rewindDirectory();
   while(true) {
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       directorios(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}

char* formatFileName(char* fileName) {
    // Convert to lowercase
    trim(fileName);
    for(int i = 0; fileName[i] != '\0'; i++) {
        fileName[i] = tolower(fileName[i]);
    }

    // Capitalize first letter
    fileName[0] = toupper(fileName[0]);

    return fileName;
}

char* trim(char* str) {
    while (isspace(*str)) str++; // Remove leading spaces
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--; // Remove trailing spaces
    *(end + 1) = '\0'; // Null-terminate the trimmed string
    return str;
}

void printRead(){
    Serial.println("Lectura");
    Serial.println("Escribe el nombre del archivo que quieres leer");
    while (!Serial.available()); // Wait for user input
    String choiceRead = Serial.readString();
    char* choiceReadChar = strdup(choiceRead.c_str());
  
    // Close the file before calling readFile
    myFile.close();
  
    // Call readFile after the file is closed
    readFile(choiceReadChar);
    // Clean up allocated memory
    free(choiceReadChar);
    // Close the file before calling readFile
    myFile.close();
}

void chooseWrite(){
    while (Serial.available()) {
      Serial.read();
    }
    Serial.println("Escritura");
    Serial.println("Escribe el nombre del archivo en el que quieres escribir o crea uno nuevo");
    while (!Serial.available()); // Wait for user input
    String choiceTextName = Serial.readString();
    char* choiceTextNameChar = strdup(choiceTextName.c_str());

    while (Serial.available()) {
      Serial.read();
    }
    
    Serial.println("Escribe el texto a continuación");
    while (!Serial.available()); // Wait for user input
    String choiceText = Serial.readString();
    char* choiceTextChar = strdup(choiceText.c_str());


    // Close the file before calling writeFile
    myFile.close();
    writeFile(choiceTextNameChar, choiceTextChar);

    // Clean up allocated memory
    free(choiceTextNameChar);
    free(choiceTextChar);
  
}

void writeFile(char* fileName, char* text){
    // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open(formatFileName(fileName), FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    myFile.println(trim(text));
    // close the file:
    myFile.close();
    Serial.println("Printed.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error Opening File");
  }

}
