#include "servo.h"

void init_pwm() {
	PINSEL0 |= (1 << 1);    // P0.0 as PWM1
	PWMPR = PWMPR_LDVAL;             // Prescaler to 1us (PWMPR = (PCLK in Hz / 1,000,000) - 1)
	PWMMR0 = 20000;         // 20ms = 50Hz
	PWMMCR = (1 << 1);      // Reset on MR0
	PWMPCR = (1 << 9);      // Enable PWM1 output
	PWMTCR = (1 << 1);      // Reset counter
	PWMTCR = (1 << 0) | (1 << 3); // Enable PWM and counter
	PWMLER = (1 << 0);      // Load MR0
}
void set_servo(u8 cnt) {
	PWMMR1 = (PULSE_MIN + (cnt * PULSE_STEP));
  PWMLER = (1 << 1);  // Load MR1
}
