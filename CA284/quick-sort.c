#include<stdio.h>
#include<stdlib.h>

int partition(int array[], int low, int high) {
	int pivot = array[high];
	int x = (low - 1);
	for (int y = low; y <= high - 1;y++) {
		if (array[y] < pivot) {
			x++;
			swap(&array[x], &array[y]);
		}
	}
	swap(&array[x + 1], &array[high]);
	return (x + 1);
}

void quick_sort(int array[], int low, int high) {
	    if (low < high) { 
        int p = partition(array, low, high); 

        quick_sort(array, low, p - 1); 
        quick_sort(array, p + 1, high); 
    } 
}