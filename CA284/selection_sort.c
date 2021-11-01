#include <stdio.h>
#include <stdlib.h>

// https://www.geeksforgeeks.org/selection-sort/
void swap(int *array, int i, int j)
{	
	// Swapping integers in array for selection sort
	int tem = array[i];
	array[i] = array[j];
	array[j] = tem;
}

void selection_sort(int array[], int size){
	int i, j, min_index;
	
	for (i = 0; i < size-1; i++) {
		min_index = i;
		for (j = i + 1; j < size; j++)
			// If this number is smallest than the current number in array, assign this new integer as the new smallest
			if (array[j] < array[min_index])
				min_index = j;
		
		// Caling swap function
		swap(array, min_index, i);
	}
}