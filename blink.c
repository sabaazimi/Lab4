#include <wiringPi.h>
int main (int argc, char *argv[])
{
 wiringPiSetup () ;
 pinMode (2, OUTPUT) ;
 for (;;)
 {
 digitalWrite (2, HIGH) ; delay (1000) ;
 digitalWrite (2, LOW) ; delay (500) ;
 }
 return 0 ;
}

