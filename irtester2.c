#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char *argv[])
{
  /*int i;*/
  int LED=0;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pullUpDnControl(0, PUD_UP) ;

	for (;;){
 		if (digitalRead(0)== 0 && LED==0){
			digitalWrite (2, HIGH) ; 
			delay(500);
			LED=1;

		}else {
			digitalWrite (2, LOW);
			LED=0;
			delay(500);
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
