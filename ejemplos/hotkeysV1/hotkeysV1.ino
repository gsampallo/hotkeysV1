#include "Keyboard.h"

#define PASSLENGTH 8

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);

  pinMode(4, INPUT_PULLUP);
  pinMode(5, OUTPUT);

  pinMode(7, INPUT_PULLUP);
  pinMode(6, OUTPUT);

  pinMode(8, INPUT_PULLUP);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

boolean grabar = false;

unsigned long lastDebounceTime = 0;
unsigned long timeDelay = 1000; //15000;

unsigned long ultimoCambio = 0;
unsigned long tiempoCambio = 5;

int leds[] = { 3, 5, 6, 9};
int i = 0;
int intensidad = 0;
boolean subeIntensidad = true;

void loop() {

  /*
     Boton 1
  */
  if (digitalRead(2) == LOW) {
    lastDebounceTime = millis();
    accionGrabar();
  }

  /*
     Boton 2
  */
  if (digitalRead(4) == LOW) {
    lastDebounceTime = millis();
    Keyboard.begin();
    Keyboard.press(KEY_LEFT_GUI);
    //Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('d');
    delay(100);
    Keyboard.releaseAll();
    // wait for new window to open:
    delay(1000);
  }

  /*
     Boton 3
  */
  if (digitalRead(7) == LOW) {
    lastDebounceTime = millis();
    accion('t');
  }

  /*
   * Boton 4
   */
  if (digitalRead(8) == LOW) {
    lastDebounceTime = millis();
    generarPassword();
  }   

  if ((millis() - lastDebounceTime) > timeDelay) {
    if ((millis() - ultimoCambio) > tiempoCambio) {
      ultimoCambio = millis();
    
      /*
      if(i > 3) {
        i= 0;
      }
      
      if (subeIntensidad) {
        if (intensidad < 254) {
          intensidad++;
        } else {
          intensidad = 0;
          //subeIntensidad = false;
          i++;
        }
      } else {
        if (intensidad > 0) {
          intensidad--;
        } else {
          //intensidad = 1;
          i++;
          subeIntensidad = true;
        }
      }
      */

      if(subeIntensidad) {
        if (intensidad < 254) {
          intensidad++;
        } else {
          if(i<3) {
            i++;
            intensidad = 0;
          } else {
            //subeIntensidad = false;
            i=0;
            intensidad = 0;
          }
        }
      }
      analogWrite(leds[i], intensidad);


    }

  }
}

char *alphabeth = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const long alphabethLength = 60;//sizeof(alphabeth);
char pass[PASSLENGTH+1];  //we add 1 extra for the NULL
volatile bool generatePass;

void generarPassword() {
  Keyboard.begin();
  for (int n = 0; n < PASSLENGTH; n++) {
    Keyboard.press(alphabeth[random(0, alphabethLength)]);
    Keyboard.releaseAll();
  }
  delay(50);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_HOME);
  Keyboard.releaseAll();
  delay(10);
  accion('c');
}

boolean grabando = false;

void accionGrabar() {
  if (grabando) {
    accion('d');
    grabando = false;
    digitalWrite(3, LOW);
  } else {
    accion('g');
    grabando = true;
    digitalWrite(3, HIGH);
  }
}

void accion(char accion) {
  Keyboard.begin();
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(accion);
  delay(100);
  Keyboard.releaseAll();
  // wait for new window to open:
  delay(1000);
  //Keyboard.close();
}

