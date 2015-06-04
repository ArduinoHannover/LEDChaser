#include <LEDChaser.h>
#define MAX_MODI 6

char modus = 0;
int frame = 0;

void setup() {
  //Nichts zu tun hier.
}

void loop() {
  if (Chaser.taster()) {
    modus = (modus + 1) % MAX_MODI;
    Chaser.entprellen();
  }
  if (modus == 0) {
    //Fuellender und leerender Kreis
    frame = (frame + 1) % 40;
    if (frame < 20) {
      for (int i = 0; i < frame % 10; i++) {
        Chaser.LED(mittig(i), frame < 10);
      }
      for (int i = frame % 10; i < 10; i++) {
        Chaser.LED(mittig(i), frame >= 10);
      }
    } else {
      for (int i = 0; i < frame % 10; i++) {
        Chaser.LED(mittig(9 - i), frame < 30);
      }
      for (int i = frame % 10; i < 10; i++) {
        Chaser.LED(mittig(9 - i), frame >= 30);
      }
    }
    analogDelay(100);
  } else if (modus == 1) {
    //LEDs abwechselnd an (jede Zweite)
    frame = (frame + 1) % 2;
    for (int i = 0; i < 10; i++) {
      Chaser.LED(i + 1, (i + frame) % 2 == 0);
    }
    analogDelay(100);
  } else if (modus == 2) {
    //zwei LEDs im Uhrzeigersinn
    frame = (frame + 1) % 5;
    for (int i = 0; i < 10; i++) {
      Chaser.LED(i + 1, (i + frame) % 5 != 0);
    }
    analogDelay(100);
  } else if (modus == 3) {
    //zwei LEDs rotierend entgegen des Uhrzeigersinns
    frame = (frame + 4) % 5;
    for (int i = 0; i < 10; i++) {
      Chaser.LED(i + 1, (i + frame) % 5 != 0);
    }
    analogDelay(100);
  } else if (modus == 4) {
    //eine LED entgegen des Uhrzeigersinns
    frame = (frame + 9) % 10;
    for (int i = 0; i < 10; i++) {
      Chaser.LED(i + 1, (i + frame) % 10 != 0);
    }
    analogDelay(100);
  } else if (modus == 5) {
    //US-Polizei
    frame = (frame + 1) % 10;
    boolean an = (frame % 5) % 2;
    for (int i = 0; i < 10; i++) {
      Chaser.LED(mittig(i), ! (an && (i < 5 == frame < 5)));
    }
    analogDelay(50);
  }
}

int mittig(int led) {
  //gegen Uhrzeigersinn, rechts neben USB beginnend
  return (led + 8) % 10 + 1;
}

void analogDelay(unsigned int faktor) {
  //Je nach Position des Potis mehr oder wenger verzoegern
  delay(faktor * 10 / map(Chaser.poti(), 0, 1024, 30, 1));
}
