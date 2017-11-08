//====Shields avec Joystick et 4 +2 boutons poussoirs
// tiptopboards 22 08 2013
// C.Rolland
//====================================================
//Source http://www.elecfreaks.com/1999.html
//
// Based on original example by Ryan Owens
// ===================================================

// pin  Arduino associées aux entrées
//brochage boutons A=2 B=3 C=4 D=5 E=6 F=7 Joy=8
const byte pinA = 2; 
const byte pinB = 3;
const byte pinC = 4;
const byte pinD = 5;
const byte pinE = 6;
const byte pinF = 7;
const byte pinJoystick = 8;

const byte Pin_Analog_X = 0;  //Joystick sur pin 0 et 1 analogiques
const byte Pin_Analog_Y = 1;


void setup() {
  Serial.begin(9600);
   // Les boutons sont des INPUT
   // Active les résistances internes de l'Arduino en pull-up
   // HIGH bouton non appuyé, LOW appuyé
     
  pinMode(pinA, INPUT);  
  digitalWrite(pinA, HIGH);
  pinMode(pinB, INPUT);  
  digitalWrite(pinB, HIGH);
  pinMode(pinC, INPUT);  
  digitalWrite(pinC, HIGH);
  pinMode(pinD, INPUT);  
  digitalWrite(pinD, HIGH);
  pinMode(pinE, INPUT);  
  digitalWrite(pinE, HIGH);
  pinMode(pinF, INPUT);  
  digitalWrite(pinF, HIGH);
  pinMode(pinJoystick, INPUT);  
  digitalWrite(pinJoystick, HIGH);  
}


void loop() {
 // Renvoie vers la console l'état du joystick et des boutons
  Serial.print(digitalRead(pinA));
 Serial.print(digitalRead(pinB));
 Serial.print(digitalRead(pinC));
 Serial.print(digitalRead(pinD));
 Serial.print(" ");
 Serial.print(digitalRead(pinE));
 Serial.print(digitalRead(pinF));
 Serial.print(" ");
 Serial.print(digitalRead(pinJoystick));
  
  Serial.print("xy ");  //Position du potentiomètre
  Serial.print(analogRead(Pin_Analog_X));
  Serial.print(" ");
  Serial.print(analogRead(Pin_Analog_Y));
   
  Serial.println();
}
