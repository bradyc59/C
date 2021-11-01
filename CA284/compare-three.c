#include<stdio.h>

int BigNum(int num1, int num2, int num3)
{
	int num;

	if(num1 > num2 && num1 > num3) /* if first number is bigger than number 2 and number 3, return first number is the biggest number */
		num = num1;
	else if(num2 > num1 && num2 > num3)
		num = num2;
	else if(num3 > num2 && num3 > num1)
		num = num3;
	
	printf("%d is the largest number.\n", num);

}
int SameNum(int num1, int num2, int num3)
{
	if(num1 == num2 || num2 == num3 || num1 == num3) /* if any of the numbers are the same, return the error */
	{
		return printf("error: two numbers entered are the same\n");
	}
	return(0);
}

int main(int argc, char*argv[]) /* Brings in command line arguments */
{
	int num, num1, num2, num3;
	
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]); /* coverts all characters to intergers */
	num3 = atoi(argv[3]);
	
	if(SameNum(num1, num2, num3) == 0) /* if SameNum funstion is True, return error statement */
	{
	BigNum(num1, num2, num3);
	}
	return(0);
}