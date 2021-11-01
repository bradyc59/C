#include<stdio.h>
#include<stdlib.h>
#define PI 3.1415

int main(int argc, char *argv[])
{
	int radius = 0;
	float first = 0.0;
	float second = 0.0;
	float area = 0.0;
	int height;
	
	radius = atoi(argv[1]);
	height = atoi(argv[2]);
	
	first = (2 * PI * radius * height);
	
	second = (2 * PI * radius * radius);
	
	area = first + second;
	
	printf("%.2f\n", area);

	return 0;
}
	