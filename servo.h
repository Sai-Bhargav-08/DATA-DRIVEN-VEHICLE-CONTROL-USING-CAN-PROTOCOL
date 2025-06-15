#include <LPC21xx.h>
#include "types.h"
#include "can_defines.h"

#define PULSE_MIN   500
#define PULSE_MAX   2500
#define STEPS       8
#define PULSE_STEP  ((PULSE_MAX-PULSE_MIN)/STEPS)
#define PRESCAL     1000000 // to 1us tick rate
#define PWMPR_LDVAL ((PCLK/PRESCAL)-1)

void init_pwm(void);
void set_servo(u8);
