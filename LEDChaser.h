#ifndef LEDCHASER_H
#define LEDCHASER_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define LD1		3
#define LD2		4
#define LD3		5
#define LD4		6
#define LD5		7
#define LD6		8
#define LD7		9
#define LD8		10
#define LD9		11
#define LD10	12
#define P1D		A0
#define P1A		0
#define P1		P1A
#define S1		2
#define AN		LOW
#define AUS		HIGH

class LEDChaser {
	private:
	
	public:
		LEDChaser();
		void
			LEDan(uint8_t led),
			LEDaus(uint8_t led),
			LED(uint8_t led, boolean onoff),
			entprellen();
		boolean
			taster(),
			LED(uint8_t);
		uint16_t 
			poti();
		uint8_t
			LEDpin(uint8_t led);
};
extern LEDChaser Chaser;

#endif //LEDCHASER_H