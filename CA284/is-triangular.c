#include<stdio.h>

int main(int argc, char*argv[1]) /*brings in command line argument*/
{
     int instance, sum=0, num;

	 for(instance=0; instance < 1000; instance++) /*for each time instance is less than 1000, go to next character in sequence*/
	 {
	  num = atoi(argv[1]); /*converts character to interger*/
	  sum = sum+instance;

	  if(sum == num)
	  {
	   printf("%d is a triangular number.\n", num);
	   break;
	  }
	 }

	 if(sum != num)
	 {
	  printf("%d is not a triangular number.\n", num);
	 }
	 return(0);
}
