#include<stdio.h>

int main(int argc, char*argv[])
{
    char letter = argv[1:];
	if (letter <= 'z')
		printf("%s", letter);
	
	return(0);
}
