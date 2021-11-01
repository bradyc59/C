#include<stdio.h>
#include<stdlib.h>
#define PI 3.1415

int main(int argc, char *argv[])
{
	float area = 0.0;
	int radius = 0;
	
	radius = atoi(argv[1]);
	
	radius = (radius * radius);
	
	area = (PI * radius);
	
	printf("%.2f\n", area);
	
	return 0;
}