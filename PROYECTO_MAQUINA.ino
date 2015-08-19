/*
Codigo realizado por Salvador Ruiz Sedeño el 27-9-2014 

Mas info en: http://www.frostcode.es/

Codigo para aprender a utilizar una pantarra lcd mediate i2c.
Puedes ver el Tutorial en vídeo en Youtube:http://youtu.be/4mTRnRwDnF8

http://tronixstuff.com/2011/06/22/tutorial-arduino-timing-methods-with-millis/
*/

////////////////////////////////////////////////////////////////////////////////////////////////// LIBRERIAS
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
////////////////////////////////////////////////////////////////////////////////////////////////// VARIABLES
byte escobaChar[8] = { B00100, B00100, B00100, B00100, B00100, B11111, B10101, B10101 }; 
int Escobachar = 0;
byte chuloChar[8] = { B00000, B00000, B00001, B00010, B10100, B01000, B00000, B00000 };
int Chulochar = 1;
char myChar = ' ';


int stepsa = 53;
int direcciona = 52;

int stepsb = 51;
int direccionb = 50;

int dira;
int pasos;
int velocidad;
int dirb;

float h,m,s;
long int total; 

double razon;

int posa;
int posb;
////////////////////////////////////////////////////////////////////////////////////////////////// TECLADO
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
////////////////////////////////////////////////////////////////////////////////////////////////// SETUP
void setup()
{
  Serial.begin(9600);
  pinMode(stepsa, OUTPUT); 
  pinMode(direcciona, OUTPUT);
  pinMode(stepsb, OUTPUT); 
  pinMode(direccionb, OUTPUT);  
  //pinMode(reset, OUTPUT);
  //Iniciamos el fondo retroiluminado
  lcd.backlight();
  //Iniciamos la pantalla
  lcd.init();
  lcd.createChar(0, escobaChar);
  lcd.createChar(1, chuloChar);
  intro();   
  delay(1000);
  experimento();
  
}



////////////////////////////////////////////////////////////////////////////////////////////////// LOOP
void loop()
{
  
  char keypressed = myKeypad.getKey();
  
   if (keypressed != NO_KEY)
  {
    
    if(keypressed == keymap[0][0]){
      expunoscreen();
      pasos = 3200;
      dira = 0;
      velocidad = 1000;
      dirb = 0;
      razon=4;
      total = (pasos)*(velocidad/1000);     
    }

    
   if(keypressed == keymap[3][0]){
      posa=0;
      posb=0;
      lcd.setCursor(0,2);
      lcd.print("Pos:      Pos:      ");
      lcd.setCursor(0,3);
      lcd.print("                   ");
      Pasos(dira, pasos, velocidad, dirb, razon);
      
    }
    
    if(keypressed == keymap[3][2]){
      experimento();
    }  
    
    
    
    
    
  } 

} 

