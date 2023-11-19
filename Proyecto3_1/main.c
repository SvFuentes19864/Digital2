//----------------------------------------------------------------------------------
//Variables
//----------------------------------------------------------------------------------

int P1, P2, P3, P4; // Declara las variables aquí

const int P1_pin = PE_3; // Entradas analógicas de los sensores
const int P2_pin = PE_2;
const int P3_pin = PE_1;
const int P4_pin = PD_3;

int P1_R = PE_0; // Leds indicadores
int P1_G = PB_3;

int P2_R = PF_0;
int P2_G = PC_4;

int P3_R = PB_6;
int P3_G = PC_7;

int P4_R = PA_4;
int P4_G = PD_6;

void setup() {
  // put your setup code here, to run once:
  pinMode(P1_R, OUTPUT);  // Configuramos los leds como salidas
  pinMode(P1_G, OUTPUT);

  pinMode(P2_R, OUTPUT);
  pinMode(P2_G, OUTPUT);

  pinMode(P3_R, OUTPUT);
  pinMode(P3_G, OUTPUT);

  pinMode(P4_R, OUTPUT);
  pinMode(P4_G, OUTPUT);
    Serial.begin(115200); // Inicia la comunicación serial a 9600 bps

}

void loop() {
  P1 = analogRead(PE_3); // Leemos el valor del primer sensor como entrada analógica

  Serial.print("Valor PA7: ");
  Serial.println(P1); // Imprime el valor actual de PA7 en el monitor serial

  // put your main code here, to run repeatedly:
  //----------------------------------------------------------------------------------
  //Sensor 1
  //----------------------------------------------------------------------------------
  int P1 = analogRead(P1_pin); // Leemos el valor del primer sensor como entrada analógica

  if (P1 < 4095) {              // Cambia el umbral según tus necesidades
    digitalWrite(P1_R, HIGH); // Mientras que HIGH indica que el parqueo está libre
    digitalWrite(P1_G, LOW);
  } else {
    digitalWrite(P1_R, LOW);
    digitalWrite(P1_G, HIGH);
  }

  //----------------------------------------------------------------------------------
  //Sensor 2
  //----------------------------------------------------------------------------------
  int P2 = analogRead(P2_pin);

  if (P2 < 4095) {
    digitalWrite(P2_R, HIGH);
    digitalWrite(P2_G, LOW);
  } else {
    digitalWrite(P2_R, LOW);
    digitalWrite(P2_G, HIGH);
  }

  //----------------------------------------------------------------------------------
  //Sensor 3
  //----------------------------------------------------------------------------------
  int P3 = analogRead(P3_pin);

  if (P3 < 4095) {
    digitalWrite(P3_R, HIGH);
    digitalWrite(P3_G, LOW);
  } else {
    digitalWrite(P3_R, LOW);
    digitalWrite(P3_G, HIGH);
  }

  //----------------------------------------------------------------------------------
  //Sensor 4
  //----------------------------------------------------------------------------------
  int P4 = analogRead(P4_pin);

  if (P4 < 4095) {
    digitalWrite(P4_R, HIGH);
    digitalWrite(P4_G, LOW);
  } else {
    digitalWrite(P4_R, LOW);
    digitalWrite(P4_G, HIGH);
  }
}
