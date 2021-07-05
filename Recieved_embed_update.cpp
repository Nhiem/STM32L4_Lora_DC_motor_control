#include "mbed.h"
#include <string>
#include "motordriver.h"
#include "US100.h"

Serial pc(USBTX, USBRX);
Serial uart(PA_0, PA_1);//TX4,RX4

int idx=0; 
char getinput; 
char  inputdata; 
void newData()
{
//buffer variables
char ch;
//if data is ready in the buffer
while (uart.readable()) {
//read 1 character
//pc.printf("datacomming");
ch = uart.getc();
//if character is ‘s’ than it is the start of a sentence

inputdata += ch;
//if the character is # than the end of the sentence is reached and some stuff has to be done
if (ch == '#') {
//remove start and stop characters
//inputdata.erase(0,1);
//inputdata.erase(inputdata.length()-1,1);
//do something witth string b, like:
//if (b=="some command"){
pc.printf("input data =%c\n\r",ch);
}
}
}



// DC motor 
Motor A(PA_3, PB_4, PB_1, 1); // pwm, fwd, rev, 
Motor B(PA_15, PA_7, PA_2, 1); 

void fwd(); 
void back(); 
void right(); 
void left(); 
void stop(); 

void fwd1(); 
void back1(); 
void right1(); 
void left1(); 


//Ulrasonic sensor 
US100 sensor(PC_3, PC_4); 
US101 sensor1(PC_2, PC_1); 



int main(){
    uart.baud(9600); 
   // uart.attach(&newData);
    while(1){
        
        if(uart.readable()){
           char getinput= uart.getc(); 
          //  iputdataspeed= uart.getc(); 
            pc.printf("inputdat = %c\r\n", getinput);
            //return(inputdata);
            //pc.printf("inputdataspeed: %s\n\r", inputdatspeed); 

            if(getinput== 'w'){
                fwd(); 
                wait(0.1); 

            }
            else if (getinput== 's' ){
                back(); 
                wait(0.1); 
            }
            else if (getinput== 'a' ){
                left(); 
                wait(0.1); 
            }

            else if (getinput== 'd' ){
                right(); 
                wait(0.1); 
            }
             else if(getinput== 'i'){
                fwd1(); 
                wait(0.1); 

            }
            else if (getinput== 'k' ){
                back1(); 
                wait(0.1); 
            }
            else if (getinput== 'j' ){
                left1(); 
                wait(0.1); 
            }

            else if (getinput== 'l' ){
                right1(); 
                wait(0.1); 
            }
            else if (getinput== 'b'){
                stop(); 
                wait(0.2); 
            }
            else{
                stop(); 
                wait(0.1); 
            }
            wait(0.5); 
        
        }
        else{
            pc.printf("Uart .read not available\r\n");
            wait(0.4);
            }
        
         wait(0.2); 
        int ultra_d1= sensor.distance(); 
        int ultra_d2= sensor1.distance1();
        pc.printf("S1 %d\n\r", ultra_d1); 
        pc.printf("S2 %d\n\r", ultra_d2); 
        


    }

}



// DC motor speed control (we can turn it to .h and cpp)
void fwd(void){ 
    A.speed(1); 
    B.speed(1); 
}
void back(void){
    A.speed(-1);
    B.speed(-1); 
}
void left(void){
    A.speed(1); 
    B.speed(0); 
}
void right(void){
    A.speed(0); 
    B.speed(1); 
}
void stop(void){
    A.stop(0); 
    B.stop(0); 
    A.coast(); 
    B.coast(); 
}

// DC motor move with Haft speed 
void fwd1(void){ 
    A.speed(0.5); 
    B.speed(0.5); 
}
void back1(void){
    A.speed(-0.5);
    B.speed(-0.5); 
}
void left1(void){
    A.speed(0.5); 
    B.speed(0); 
}
void right1(void){
    A.speed(0); 
    B.speed(0.5); 
}


