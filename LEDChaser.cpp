#include "LEDChaser.h"

LEDChaser::LEDChaser(void) {
	for (int i = 0; i <= 10; i++) {
		pinMode(LEDpin(i), OUTPUT);
		LEDaus(i);
	}
	pinMode(P1D, INPUT);
	pinMode(S1, INPUT);
	digitalWrite(S1, HIGH);
}
void LEDChaser::LEDan(uint8_t led) {
	digitalWrite(LEDpin(led), AN);
}
void LEDChaser::LEDaus(uint8_t led) {
	digitalWrite(LEDpin(led), AUS);
}
void LEDChaser::LED(uint8_t led, boolean onoff) {
	digitalWrite(LEDpin(led), onoff);
}
boolean LEDChaser::LED(uint8_t led) {
	return digitalRead(LEDpin(led));
}
boolean LEDChaser::taster() {
	return !digitalRead(S1);
}
void LEDChaser::entprellen() {
	while (taster()) {
		delay(10);
	}
}
uint16_t LEDChaser::poti() {
	return analogRead(P1A);
}
uint8_t LEDChaser::LEDpin(uint8_t led) {
	switch(led) {
	case 1: return LD1;
	case 2: return LD2;
	case 3: return LD3;
	case 4: return LD4;
	case 5: return LD5;
	case 6: return LD6;
	case 7: return LD7;
	case 8: return LD8;
	case 9: return LD9;
	case 10: return LD10;
	default: return LED_BUILTIN;
	}
}

LEDChaser Chaser = LEDChaser();