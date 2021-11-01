#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    int  num, binary_value, decimal_value = 0, base = 1, rem;
    num = atoi(argv[1]);
    binary_value = num;
    while (num > 0)
    {
        rem = num % 10;
        decimal_value = decimal_value + rem * base;
        num = num / 10 ;
        base = base * 2;
    }
	if(binary_value != 1 && binary_value != 0){
		printf("Only digits 1 and 0 are permitted.\n");
	}
    else{
		printf("%d\n", decimal_value);
	}
}