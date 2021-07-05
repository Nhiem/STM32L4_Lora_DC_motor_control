#include "mbed.h"
#include "motordriver.h"

Motor A(PA_3, PB_4, PB_1, 1);
Motor B(PA_15, PA_7, PA_2, 1); 

void fwd();
void back();
void turnright();
void turnleft();
void stop();
int main(){
    while(1)
    {
        fwd(); 
        wait(1); 
        stop(); 
        wait(0.1); 

        back(); 
        wait(1);
        stop(); 
        wait(0.1); 

        turnright();
        wait(1); 
        stop(); 
        wait(0.1); 

       turnleft();
        wait(1);
        stop(); 
        wait(0.1); 

       // stop(); 
        //wait(1);

    

    }
}
        void fwd(void)
        {
        A.speed(1);
        B.speed(1);
        }

        void back(void)
        {
        A.speed(-1);
        B.speed(-1);
        }

        void stop(void)
        {
        A.stop(0);
        B.stop(0);
        A.coast(); 
        B.coast(); 

        }

        void turnleft(void)
        {
            A.speed(0.5); 
            B.speed(0); 
        }

        void turnright(void)
        {
            A.speed(0);
            B.speed(0.5);
        }
        
