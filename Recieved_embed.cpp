
#include"mbed.h"
#include <string>
#include "motordriver.h"
#include "US100.h"
Serial pc(USBTX, USBRX);


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

int arrayd1[100]; 
int arrayd2[100]; 
int arrayd11[100]; 
int arrayd12[100]; 
int arrayd21[100]; 
int arrayd22[100]; 



double LisaAngle ; 
double slopeYiYu; 
float averaged1; 
float averaged2; 
int n; 
int sum; 
int sum1; 
int i;

// Lora Define 
Serial uart(PA_0, PA_1); //TX4, RX4
//int idx= 0;
char getinput; 

// Recievd and Print Data in terminal Function 

 int main(){
    uart.baud(9600); 
 

    while(1){

// DC motor control with the Input 

        if(uart.readable()){
            getinput= uart.getc(); 
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
            else if (getinput== ' '){
            	stop(); 
            	wait(0.2); 
            }
            else if(getinput== 'y'){

                    stop(); 
                    wait(0.1); 

                


               while(i<100){


                 arrayd1[i]=(sensor.distance()+ 6); 
                 arrayd2[i]=(sensor1.distance1()+6);
            
                    }

                    n= 100; 
                     sum=0; 
                    sum1=0; 

                   for (int i=0; i<n; i++){

                        sum += arrayd1[i];
                        sum1 += arrayd2[i]; 
                   }

                     averaged1 =sum/100; 
                     averaged2 = sum1/100; 

                    slopeYiYu[j]= (abs(averaged1-averaged2)/390); 
                    LisaAngle[j]= atan(slopeYiYu); 

                    uart.printf("Angle output %d\r\n", LisaAngle); 
                    uart.printf("Distance 1: %d\r\n", averaged1); 
                    uart.printf("Distance 2: %d\r\n", averaged2); 
                    pc.print("anlge %c\r\n", LisaAngle); 

                    }


                else if(getinput== 't'){

                    stop(); 
                    wait(0.1); 

                

                    while(i<100){


                 arrayd11[i]=(sensor.distance()+ 6); 
                 arrayd12[i]=(sensor1.distance1()+6);
            
                    }

                    n= 100; 
                     sum=0; 
                    sum1=0; 

                   for (int i=0; i<n; i++){

                        sum += arrayd11[i];
                        sum1 += arrayd12[i]; 
                   }

                     averaged1 =sum/100; 
                     averaged2 = sum1/100; 

                    slopeYiYu[j]= (abs(averaged1-averaged2)/390); 
                    LisaAngle[j]= atan(slopeYiYu); 

                    uart.printf("Angle output %d\r\n", LisaAngle); 
                    uart.printf("Distance 1: %d\r\n", averaged1); 
                    uart.printf("Distance 2: %d\r\n", averaged2); 
                    pc.print("anlge %c\r\n", LisaAngle); 

                    }

               
         else if(getinput== 'u'){

                    stop(); 
                    wait(0.1); 

                }



               
        
            else{
                stop(); 
                wait(0.1); 
            }

            wait(0.2); 
        }

// Ultrasonic output 



       
    //char intStr1 = (ultra_d2); 


     // std::string s1 = std::to_string(intStr); 
      //  string s2 = to_string(intStr1); 
        
        //s2 = to_string(ultra_d2);

      
//Lora Transmit data 
     // uart.putc(ultra_d1) ; // here should print output of ourdata 
      //pc.printf("distance1: %d\r\n", ultra_d1); 
      //  wait(0.2);

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
    A.speed(0); 
    B.speed(1); 
}
void right(void){
    A.speed(1); 
    B.speed(0); 
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
    A.speed(0); 
    B.speed(0.5); 
}
void right1(void){
    A.speed(0.5); 
    B.speed(0); 
}


