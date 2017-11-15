
// Test utilisation servomoteur SG90 //

#include <Servo.h> 
  
Servo monservo;  // crée l’objet pour contrôler le servomoteur 
  
void setup() 
{ 
  monservo.attach(9);  // utilise la broche 9 pour le contrôle du servomoteur 
  monservo.write(0); // positionne le servomoteur à 0° 
} 
  
  
void loop() 
{  
}
