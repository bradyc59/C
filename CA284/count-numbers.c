#include <stdio.h>
#include <stdlib.h>

int oddNums(int num){

    int i = 0;
    int count = 0;
    while(i < num){
        if(num % 2 != 0){
            count++;
            i++;
        } else {
            i++;
        }
    }
    printf("Number of odd numbers: %d", count);

}

int evenNums(int num){
    
    int i = 0;
    int count = 0;
    while(i < num){
        if(num % 2 == 0){
            count++;
            i++;
        } else {
            i++;
        }
    }
    printf("Number of even numbers: %d\n", count);
}

int primeNums(int num, int array[])
{
	int count = 0;
	int i = 0;
	for(i; i < num; i++)
	{
		int a = array[i];
		if(a==2)
			count++;
		for(int j = 2; j < a; j++)
		{
			if(a % j == 0)
			{
				break;
			}
			else
			{
				count++;
				break;
			}
		}
	}
	printf("Number of prime numbers: %d\n", count);
			
}
 
int main(int argc, char**argv[30])
{
	int num;
	if(num < 0)
	{
		printf("error: Only positive intergers are permitted\n");
	}
	
	else if(isalpha(num)){
		printf("error: only numbers are permitted");
	}
	else if(argc == 1)
	{
		printf("insufficient command line arguments\n")
	}
	else{
		oddNums(num);
		evenNums(num);
		primeNums(num);
	}
    return(0);
}
}