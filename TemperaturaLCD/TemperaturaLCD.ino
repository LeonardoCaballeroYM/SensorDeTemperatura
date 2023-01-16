// include el código de la librería.
#include <LiquidCrystal.h>

// Inicializa la librería con sus pines indicados.
// RS, RW, Enable, D4, D5, D6, D7.
LiquidCrystal lcd(8, NULL, 9, 4, 5, 6, 7);

int LuzFondo = 10; // Pin 10 para saber que es luz de fondo.
byte estadoBoton1,
estadoBoton2,
estadoBoton3,
estadoBoton4,
estadoBoton5;
byte estadoBotonAnt1,
estadoBotonAnt2,
estadoBotonAnt3,
estadoBotonAnt4,
estadoBotonAnt5;

void setup()
{

 // Formato de pantalla.
  lcd.begin(16, 2);
  lcd.print("  Arduino UNO   ");
  delay(2000);
  lcd.setCursor(0,0); // En el primer carácxter y primera fila.
  lcd.print("L:1 L:2 L:3 L:4 ");
  
  pinMode(13,OUTPUT); // Donde está el Led 13.
  pinMode(12,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(LuzFondo,OUTPUT);
  pinMode(A5,INPUT); // Entrada digital A5.
  pinMode(A4,INPUT);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(115200);
}

void loop() 
{

    estadoBoton1 = digitalRead(A5); // Leer entrada digital número A5.
    estadoBoton2 = digitalRead(A4);
    estadoBoton3 = digitalRead(A3);
    estadoBoton4 = digitalRead(A2);
    estadoBoton5 = digitalRead(A1);
    
    // Si el pulsador está pulsado, se enciende el Led 13 y
    // envía comando HIGH por el puerto serie.
    if (estadoBoton1 == HIGH && estadoBotonAnt1 == LOW)
    {
        digitalWrite(13,HIGH);
        lcd.setCursor(0,1);
        lcd.print("ON ");
        Serial.write("L1ON");
        
        delay(50);
    }
    
    // De lo contrario, Led 13 epagado y envía LOW al puerto serie.
    if (estadoBoton1 == LOW && estadoBotonAnt1 == HIGH) {
        digitalWrite(13,LOW);
        lcd.setCursor(0,1);
        lcd.print("OFF");
        Serial.write("L1OFF");
        delay(50);
    }
     estadoBotonAnt1 = estadoBoton1;

    if (estadoBoton2 == HIGH && estadoBotonAnt2 == LOW)
    {
        digitalWrite(12,HIGH);
        lcd.setCursor(4,1);
        lcd.print("ON ");
        Serial.write("L2ON");
        delay(50);
    }
    
    if (estadoBoton2 == LOW && estadoBotonAnt2 == HIGH) {
        digitalWrite(12,LOW);
        lcd.setCursor(4,1);
        lcd.print("OFF");
        Serial.write("L2FF");   
        delay(50);
    }
     estadoBotonAnt2 = estadoBoton2;

         if (estadoBoton3 == HIGH && estadoBotonAnt3 == LOW)
    {
        digitalWrite(3,HIGH);
        lcd.setCursor(8,1);
        lcd.print("ON ");
        Serial.write("L3ON");
        delay(50);
    }
    
    if (estadoBoton3 == LOW && estadoBotonAnt3 == HIGH) {
        digitalWrite(3,LOW);
        lcd.setCursor(8,1);
        lcd.print("OFF");
        Serial.write("L3OFF");   
        delay(50);
    }
     estadoBotonAnt3 = estadoBoton3;

         if (estadoBoton4 == HIGH && estadoBotonAnt4 == LOW)
    {
        digitalWrite(2,HIGH);
        lcd.setCursor(12,1);
        lcd.print("ON ");
        Serial.write("L4ON");
        delay(50);
    }
    
    if (estadoBoton4 == LOW && estadoBotonAnt4 == HIGH) {
        digitalWrite(2, LOW);
        lcd.setCursor(12,1);
        lcd.print("OFF");
        Serial.write("L4OFF");   
        delay(50);
    }
     estadoBotonAnt4 = estadoBoton4;

    if (estadoBoton5 == HIGH && estadoBotonAnt5 == LOW)
    {
        digitalWrite(LuzFondo,HIGH);
        Serial.write("Luz de fondo: Encendido.");
        delay(50);
    }
    
    if (estadoBoton5 == LOW && estadoBotonAnt5 == HIGH) {
        digitalWrite(LuzFondo, LOW);
        Serial.write("Luz de fondo: Apagado.");   
        delay(50);
    }
     estadoBotonAnt5 = estadoBoton5;
}
