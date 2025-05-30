#include <LPC21xx.H>
#include "adc.h"
#include "delay.h"
#include "can.h"
int main () {
	f32 dist=0,eAR=0,DV;
	u8 i;
	CANF txF;
	Init_ADC();
	Init_CAN1();
	txF.ID=1;
	txF.BFV.RTR=0;
	txF.BFV.DLC=4;
	while(1) {
		eAR=Read_ADC(CH0);
		DV=eAR*(1024/5);
		if(DV==3) {
			txF.BFV.DLC=1;
			txF.Data[0]='E'; //Error Calculatiions.
			CAN1_Tx(txF);
			txF.BFV.DLC=4;
		}
		else {
			dist=(6787/(DV-3))-4;
			if((dist<81)&&(dist>5)) {
				for(i=0;i<4;i++) 
					txF.Data[i]=((u8 *)&dist)[i];
				CAN1_Tx(txF);
			}
		}
		delay_ms(100);
	}
}
