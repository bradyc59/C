#include<stdio.h>
#include<stdlib.h>

int randomArray(int array[], int size) {
	
	srand(time(NULL));
	
	int x = 0;
	
	for (x; x < size; x++) {
		array[x] = rand() % size;
	}
}
