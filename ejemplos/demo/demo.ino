#include "Keyboard.h"

#define BUTTON1 2
#define LED1 3

#define BUTTON2 4
#define LED2 5

#define BUTTON3 7
#define LED3 6

#define BUTTON4 8
#define LED4 9

void setup() {
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);

  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(LED2, OUTPUT);

  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(LED3, OUTPUT);

  pinMode(BUTTON4, INPUT_PULLUP);
  pinMode(LED4, OUTPUT);
}


void loop() {

  /*
     Boton 1
     Al leer LOW detecta que el boton esta presionado
  */
  if (digitalRead(BUTTON1) == LOW) {
    Keyboard.begin();
    Keyboard.print("Boton 1");
    Keyboard.releaseAll();

    //enciende los leds por un instante
    digitalWrite(LED1,HIGH);
    delay(50);
    digitalWrite(LED1,LOW);
  }

  /*
     Boton 2
  */
  if (digitalRead(BUTTON2) == LOW) {
    Keyboard.begin();
    Keyboard.print("Boton 2");
    Keyboard.releaseAll();

    //enciende los leds por un instante
    digitalWrite(LED2,HIGH);
    delay(50);
    digitalWrite(LED2,LOW);
  }

  /*
     Boton 3
  */
  if (digitalRead(BUTTON3) == LOW) {
    Keyboard.begin();
    Keyboard.print("Boton 3");
    Keyboard.releaseAll();

    //enciende los leds por un instante
    digitalWrite(LED3,HIGH);
    delay(50);
    digitalWrite(LED3,LOW);
  }

  /*
     Boton 4
  */
  if (digitalRead(BUTTON4) == LOW) {
    Keyboard.begin();
    Keyboard.print("Boton 4");
    Keyboard.releaseAll();

    //enciende los leds por un instante
    digitalWrite(LED4,HIGH);
    delay(50);
    digitalWrite(LED4,LOW);
  }

}
