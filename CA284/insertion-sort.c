#include<stdio.h>
#include<stdlib.h>

// https://www.geeksforgeeks.org/insertion-sort/
void insertion_sort(int array[], int size) {
	int i, key, j;
	for (i = 1; i < size; i++) {
		key = array[i];
		j -= 1;

		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j -= 1;
		}
		array[j + 1] = key;
	}
	
}
