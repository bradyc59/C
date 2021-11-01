#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void execute_sort(char *sortType, int array[], int iteration, int size, int sortNums) {
	clock_t begin, end;
	double totalTime;
	
	printf("%s\n", sortType);
	for(int x = 0; x < iteration; x++) {
		randomArray(array, size);
		switch(sortNums) {
			case 0:
				begin = clock();
				selection_sort(array, size);
				end = clock();
				break;
			case 1:
				begin = clock();
				insertion_sort(array, size);
				end = clock();
				break;
			case 2:
				begin = clock();
				pancake_sort(array, size);
				end = clock();
				break;
			case 3:
				begin = clock();
				quick_sort(array, 0, size);
				end = clock();
				break;
			case 4:
				begin = clock();
				merge_sort(array, 0, size);
				end = clock();
				break;
		}
		totalTime = totalTime + ((double) (end - begin)) / CLOCKS_PER_SEC;
	}
	printf("Took %f seconds to execute\n", totalTime);

}