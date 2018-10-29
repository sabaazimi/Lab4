#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"


void b(){


 wiringPiSetup () ;
 pinMode (1, OUTPUT) ;
 for (;;)
 {
 digitalWrite (1, HIGH) ; delay (500) ;
 digitalWrite (1, LOW) ; delay (500) ;
 }


}




int main(int argc, char *argv[])
{

	
  /*int i;*/
  int LED=0;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT) ;
 
  pullUpDnControl(0, PUD_UP) ;


	b();



	for (;;){

		digitalWrite (1, HIGH) ; delay(250); digitalWrite (1, LOW) ;
 		 

 		if (digitalRead(0)== 1 && LED==0){
		/*digitalWrite (1, HIGH) ; */
			digitalWrite (2, HIGH) ; 
			delay(250);
			LED=1;
			/*digitalWrite (1, LOW) ; */
			ifttt("http://localhost:8080/trigger/event/with/key/123", "my1", "my 2", "my 33333");
			delay(250);
		}else {
/*digitalWrite (1, HIGH) ; */
			digitalWrite (2, LOW);
			LED=0;
			printf("%d", digitalRead(0));
			delay(250);
/*digitalWrite (1, LOW) ; delay(250);*/
		}

		
	}




  /*while(1) {
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1);
    printf("Waiting for event\n");
    while(digitalRead(0) == 0);
    printf("Alarm\n");
  }*/

	

	

  /*NOTREACHED*/
  return 0 ;
}
