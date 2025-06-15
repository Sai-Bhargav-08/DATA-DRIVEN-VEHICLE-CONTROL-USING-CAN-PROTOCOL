#include <LPC21xx.h>
#include "can.h"
#include "servo.h"
#define LEDS   1             //P0.1 AL LEDS
// ALL LEDS ON INDICATES WINDOW IS CLOSED

int main() {
	CANF RxF;
	Init_CAN1();
	init_pwm();
	set_servo(0); // Start at 0°
	IOSET0=0xFF<<LEDS;
	IODIR0=0xFF<<LEDS;	
	while (1) {
		CAN1_Rx(&RxF);
		if(RxF.ID==2) {
			switch(RxF.Data[0]) {
				case 0:IOCLR0=0xFF<<LEDS;
							IOSET0=0xFF<<LEDS;
							break;
				case 1:IOCLR0=0xFF<<LEDS;
							IOSET0=0xFE<<LEDS;
							break;
				case 2:IOCLR0=0xFF<<LEDS;
							IOSET0=0xFC<<LEDS;
							break;
				case 3:IOCLR0=0xFF<<LEDS;
							IOSET0=0xF8<<LEDS;
							break;
				case 4:IOCLR0=0xFF<<LEDS;
							IOSET0=0xF0<<LEDS;
							break;
				case 5:IOCLR0=0xFF<<LEDS;
							IOSET0=0xE0<<LEDS;
							break;
				case 6:IOCLR0=0xFF<<LEDS;
							IOSET0=0xC0<<LEDS;
							break;
				case 7:IOCLR0=0xFF<<LEDS;
							IOSET0=0x80<<LEDS;
							break;
				case 8:IOCLR0=0xFF<<LEDS;
							IOSET0=0x00<<LEDS;
							break;
			}
			set_servo(RxF.Data[0]);
		}
	}
}
		
