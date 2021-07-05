#include "mbed.h"
#include <string>

Serial pc(USBTX, USBRX);
Serial uart(PA_0, PA_1);//TX4,RX4

int idx=0; 
string inputdata; 



int main(){
	uart.baud(9600); 

	while(1){
		
		if(uart.readable()){
			inputdata= uart.getc();  
			pc.printf("inputdat = %s\n\r", inputdata);
			
		else{
			pc.printf("Uart .read not available");
			
		
		}
	}

}



