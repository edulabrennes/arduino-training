  #include <AccelStepper.h>
  
  // ----------- capteur de présence : 
  
  /* 
   * Code d'exemple pour un capteur à ultrasons HC-SR04..
   */
  
  /* Constantes pour les broches */
  const byte TRIGGER_PIN = 2; // Broche TRIGGER
  const byte ECHO_PIN = 3;    // Broche ECHO
   
  /* Constantes pour le timeout */
  const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s
  
  /* Vitesse du son dans l'air en mm/us */
  const float SOUND_SPEED = 340.0 / 1000;
  
  // ----------- moteur pas à pas :
  
  #define HALFSTEP 8
  
  // motor pins
  #define motorPin1  4     // IN1 on the ULN2003 driver 1
  #define motorPin2  5     // IN2 on the ULN2003 driver 1
  #define motorPin3  6     // IN3 on the ULN2003 driver 1
  #define motorPin4  7     // IN4 on the ULN2003 driver 1
  
  #define motorPin5  8     // IN1 on the ULN2003 driver 2
  #define motorPin6  9     // IN2 on the ULN2003 driver 2
  #define motorPin7  10    // IN3 on the ULN2003 driver 2
  #define motorPin8  11    // IN4 on the ULN2003 driver 2
  
  // Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
  AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
  AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);
  
  // variables
  int turnSteps = 2100; // number of steps for a 90 degree turn
  int lineSteps = -6600; //number of steps to drive straight
  int stepperSpeed = 1000; //speed of the stepper (steps per second)
  int steps1 = 0; // keep track of the step count for motor 1
  int steps2 = 0; // keep track of the step count for motor 2
  
  boolean turn1 = false; //keep track if we are turning or going straight next
  boolean turn2 = false; //keep track if we are turning or going straight next
  
  
  // ----------- autre : 

  int passageDansLaBoucle = 0;
  boolean moteurTourne = false;
    
  
  void setup() {
  
    // ----------- capteur de présence : 
  
     /* Initialise le port série */
    Serial.begin(115200);
     
    /* Initialise les broches */
    pinMode(TRIGGER_PIN, OUTPUT);
    digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
    pinMode(ECHO_PIN, INPUT);
  
   // ----------- moteur : 
    
    delay(3000); //sime time to put the robot down after swithing it on
  
    stepper1.setMaxSpeed(2000.0);
    stepper1.move(1);  // I found this necessary
    stepper1.setSpeed(stepperSpeed);
  
    stepper2.setMaxSpeed(2000.0);
    stepper2.move(-1);  // I found this necessary
    stepper2.setSpeed(stepperSpeed);
  }


 void testerPresence()  {  
  // ----------- capteur de présence : 
  
     /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    
    /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
    long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
     
    /* 3. Calcul la distance à partir du temps mesuré */
    float distance_mm = measure / 2.0 * SOUND_SPEED;
     
    /* Affiche les résultats en mm, cm et m */
    Serial.print(F("Distance: "));
    Serial.print(distance_mm);
    Serial.print(F("mm ("));
    Serial.print(distance_mm / 10.0, 2);
    Serial.print(F("cm, "));
    Serial.print(distance_mm / 1000.0, 2);
    Serial.println(F("m)"));

    // Le moteur tourne quand on détecte une présence à moins 200mm

    if (distance_mm < 200) {
      moteurTourne = true;
    } else {
      moteurTourne = false;
    }
 }
  
  
 void loop() {

  // Tous les 10000 passages dans la boucle, on vérifie s'il y a quelque chose devant le capteur de présence
  
    passageDansLaBoucle = passageDansLaBoucle + 1;
  
    if (passageDansLaBoucle >= 10000) {
      testerPresence();
      passageDansLaBoucle = 0;
    }


  // Faire tourner le moteur, seulement si présence détectée

  if (moteurTourne) {
      // ----------- moteur : 
      
      if (steps1 == 0) {
        int target = 0;
        if (turn1 == true) {
          target = turnSteps;
        }
    
        else {
          target = lineSteps;
        }
    
        stepper1.move(target);
        stepper1.setSpeed(stepperSpeed);
        turn1 = !turn1;
      }
    
      if (steps2 == 0) {
        int target = 0;
        if (turn2 == true) {
          target = turnSteps;
        }
    
        else {
          target = -lineSteps;
        }
    
        stepper2.move(target);
        stepper2.setSpeed(stepperSpeed);
        turn2 = !turn2;
      }
    
      steps1 = stepper1.distanceToGo();
      steps2 = stepper2.distanceToGo();
    
      stepper1.runSpeedToPosition();
      stepper2.runSpeedToPosition();
    }
  }
   
