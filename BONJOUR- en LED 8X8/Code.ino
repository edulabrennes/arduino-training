// Exemple de code Module Max7219 reseau de 8x8 LEDS
//
// Revision 19 08 2013

int Led = 13 ;// define LED Interface
int buttonpin = 4; // define the key switch sensor interface
int val ;// define numeric variables val


 unsigned char j; 
//Cablage du module (gnd et +V) utilise 3 pins
int Max7219_pinCLK = 10;  
int Max7219_pinCS = 9;
int Max7219_pinDIN = 8;

//Définition des pixels a eclairer 
//BONJOUR = 7 caractères

unsigned char disp1[38][8]={
{0x3C,0x22,0x22,0x3E,0x22,0x22,0x3C,0x0},//B
{0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//O
{0x0,0x42,0x62,0x52,0x4A,0x46,0x42,0x0},//N
{0x3C,0x8,0x8,0x8,0x8,0x8,0x48,0x30},//J
{0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//O
{0x42,0x42,0x42,0x42,0x42,0x42,0x22,0x1C},//U
{0x3C,0x22,0x22,0x22,0x3C,0x24,0x22,0x21},//R
};

//Autre exemple, caracteres speciaux (a definir soi meme)
//Voir explications sur http://tiptopboards.com/arduino_tutoriel/posting.php?mode=edit&f=2&p=6
//{0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55},  //damier1
// {0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA},  //damier2
 
//Ecriture d'un caractere 8x8
void Write_Max7219_byte(unsigned char DATA) 
{   
            unsigned char i;
       digitalWrite(Max7219_pinCS,LOW);      
       for(i=8;i>=1;i--)
          {        
             digitalWrite(Max7219_pinCLK,LOW);
             digitalWrite(Max7219_pinDIN,DATA&0x80);// Extracting a bit data
             DATA = DATA<<1;
             digitalWrite(Max7219_pinCLK,HIGH);
           }                                 
}
 
//Ecriture elementaire d une seule rangee 
void Write_Max7219(unsigned char address,unsigned char dat)
{
        digitalWrite(Max7219_pinCS,LOW);
        Write_Max7219_byte(address);           //address，code of LED
        Write_Max7219_byte(dat);               //data，figure on LED 
        digitalWrite(Max7219_pinCS,HIGH);
}

//Initialisation du module Max 7219 
void Init_MAX7219(void)
{
 Write_Max7219(0x09, 0x00);       //decoding ：BCD
 Write_Max7219(0x0a, 0x03);       //brightness 
 Write_Max7219(0x0b, 0x07);       //scanlimit；8 LEDs
 Write_Max7219(0x0c, 0x01);       //power-down mode：0，normal mode：1
 Write_Max7219(0x0f, 0x00);       //test display：1；EOT，display：0
}
 
 
//Le programme d affichage
void setup()
{
 //Pins a utiliser
  pinMode(Max7219_pinCLK,OUTPUT);
  pinMode(Max7219_pinCS,OUTPUT);
  pinMode(Max7219_pinDIN,OUTPUT);
  delay(50);  //Initialiser
  Init_MAX7219();

  pinMode (Led, OUTPUT); // define LED as output interface
  pinMode (buttonpin, INPUT); // define the key switch sensor output interface
}
 
 
void loop()
{ 
    val = digitalRead (buttonpin); // digital interface will be assigned a value of 3 to read val
    if (val == HIGH)  // When the key switch when the sensor detects a signal, LED flashes
    {
      digitalWrite (Led, LOW);
    }
    else
    for(j=0;j<9;j++)
    {  //Faire défiler les caracteres a afficher
    for(int i=1;i<9;i++)  //Afficher un caractere à la fois
    Write_Max7219(i,disp1[j][i-1]);
    delay(500);  //Attente pour laisser le temps de lire
    {
      digitalWrite (Led, HIGH);
    } 
  }       
}
