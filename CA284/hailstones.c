#include<stdio.h>

int main(int argc, char*argv[]) /* brings in command line arguments */
{
  int num;
  
  num = atoi(argv[1]); /* converts the number character into an interger */

  while(num > 1){ /* while the number is bigger than 1 and when it reaches 1, stop.*/
    if(num%2 == 0)
      num = num / 2; /* if number is even divide it by 2*/
    else
      num = (3 * num)+ 1; /* if number is odd multiply it by 3 */
    printf("%d\n", num); /* print out the whole process until it reaches one*/
  }
  return(0);
}