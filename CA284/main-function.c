#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]) {
	int size;
	int iteration;
	
	size = atoi(argv[1]);
	iteration = atoi(argv[2]);
	
	char Insert_sort[20] = "INSTERTION SORT";
	char Selec_sort[20] = "SELECTION SORT";
	char Pan_sort[20] = "PANCAKE SORT";
	char Q_sort[20] = "QUICK SORT";
	char M_sort[20] = "MERGE SORT";

	
	int selection_sort_array[size];
	int insertion_sort_array[size];
	int pancake_sort_array[size];
	int quick_sort_array[size];
	int merge_sort_array[size];

	execute_sort(Selec_sort, selection_sort_array, iteration, size, 0);
	execute_sort(Insert_sort, insertion_sort_array, iteration, size, 1);
	execute_sort(Pan_sort, pancake_sort_array, iteration, size, 2);
	execute_sort(Q_sort, quick_sort_array, iteration, size, 3);
	execute_sort(M_sort, merge_sort_array, iteration, size, 4);
}