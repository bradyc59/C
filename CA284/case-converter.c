#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 100 // Maximum string size



 // Toggle case of each character in given string
 
int toggleCase(char * str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i] - 32;
        }
        else if(str[i]>='A' && str[i]<='Z')
        {
            str[i] = str[i] + 32;
        }

        i++;
    }
}

int main()
{
	int i = 0;
    char str[MAX_SIZE];
	printf("Enter a string of upper and lower case letters\n");
	fgets(str, sizeof str, stdin); // Gets what you have entered into the terminal
	if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z'){ // if str is in the alphabet
		toggleCase(str);
		printf("%s", str);
	}
	
	else{ // if string is not in alphabet
		printf("Invalid character entered.\n");
	}

    return 0;
}