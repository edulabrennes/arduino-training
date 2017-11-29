#include <SimpleDHT.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Adafruit_PCD8544.h>

// Define the pins used to control the LCD module
#define LCD_SCLK    7
#define LCD_DIN     9
#define LCD_DC      10
#define LCD_CS      4
#define LCD_RST     12
// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11;

// Create a global instance of the display object
Adafruit_PCD8544 display = Adafruit_PCD8544 (
  LCD_SCLK, LCD_DIN, LCD_DC, LCD_CS, LCD_RST
);

void setup() {
  Serial.begin(115200); //Lancer le détecteur température chiffré en 115200 BAUD
  display.begin();   //lancer l'écran 
  display.setContrast(50);   // définir le contraste de l'écran
  display.clearDisplay();   //réinitialiser l'affichage
}

void loop() {
 
  Serial.println("=================================");
  Serial.println("Sample DHT11...");   // 
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
    
      display.clearDisplay();
  display.println();  //écrire ligne 1
  display.print((int)temperature); display.println(" *C, "); 
  display.print((int)humidity); display.println(" H");  
  //display.println("température:     Humidité : ");   //écrire ligne 2
  //display.println(" ");    //écrire ligne 3
 // display.display();      // écrire ligne 4
  delay(1000);        //arréter après 1 seconde
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
