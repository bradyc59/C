#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randomArray(int array[], int size) {
	
	srand(time(NULL));
	
	int x = 0;
	
	for (x; x < size; x++) {
		array[x] = rand() % size; // getting randomly generated numbers
	}
}

void swap(int *xp, int *yp)
{	
	// Swapping integers in array for sorting
	int tem = *xp;
	*xp = *yp;
	*yp = tem;
}

int partition(int array[], int low, int high) {
	int pivot = array[high];
	int x = (low - 1); // index of smallest element
	for (int y = low; y <= high - 1;y++) {
		if (array[y] < pivot) { // if current element smaller than pivot
			x++;
			swap(&array[x], &array[y]);
		}
	}
	swap(&array[x + 1], &array[high]);
	return (x + 1);
}

// https://www.edureka.co/blog/merge-sort-in-c/
void merge(int array[], int l, int m, int r) {
	int x, y, z;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1], R[n2]; // creating temporary arrays
	
	// copying data to the temp arrays
	for(x = 0; x < n1; x++) {
		L[x] = array[l + x];
	}
	for (y = 0; y < n2; y++) {
		R[y] = array[m + 1 + y];
	}
	x = 0;
	y = 0;
	z = l;
	while (x < n1 && y < n2) {
		if (L[x] <= R[y]) {
			array[z] = L[x];
			x++;
		}
		else{
			array[z] = R[y];
			y++;
		}
		z++;
	}
	
	while (x < n1) {
		array[z] = L[x];
		x++;
		z++;
	}

	while (y < n2) {
		array[z]  = R[y];
		y++;
		z++;
	}
}

void flip(int array[], int x) //reverses the array
{
    int temp, start = 0;
    while (start < x) {
        temp = array[start];
        array[start] = array[x];
        array[x] = temp;
        start++;
        x--;
    }
}
 

int findMax(int array[], int n) // return index of max element
{
    int mi, i;
    for (mi = 0, i = 0; i < n; ++i)
        if (array[i] > array[mi])
            mi = i;
    return mi;
}

// https://www.geeksforgeeks.org/selection-sort/
void selection_sort(int array[], int size){
        int i, j, min_index;

        for (i = 0; i < size-1; i++) {
                min_index = i;
                for (j = i + 1; j < size; j++)
                        // If this number is smallest than the current number in array, assign this new integer as the new smallest
                        if (array[j] < array[min_index])
                                min_index = j;

                // Caling swap function
                swap(&array[min_index], &array[i]);
        }
}

// https://www.geeksforgeeks.org/insertion-sort/
void insertion_sort(int array[], int size) {
	int i, key, j;
	for (i = 1; i < size; i++) {
		key = array[i];
		j -= 1;

		while (j >= 0 && array[j] > key) { //while element greater than key, move one position  ahead of current position
			array[j + 1] = array[j];
			j -= 1;
		}
		array[j + 1] = key;
	}
	
}

// https://www.geeksforgeeks.org/pancake-sorting/
void pancake_sort(int* array, int n){

    for (int curr_size = n; curr_size > 1; --curr_size) //reduce the current size by 1 each time from the beginning
    {
        int mi = findMax(array, curr_size);

        if (mi != curr_size - 1) { // move max to the end if not already there
            flip(array, mi);
            flip(array, curr_size - 1);
        }
    }
}
// https://www.geeksforgeeks.org/quick-sort/
void quick_sort(int array[], int low, int high) {
	    if (low < high) { 
        int p = partition(array, low, high); 

        quick_sort(array, low, p - 1); 
        quick_sort(array, p + 1, high); // sort before and after partition
		
    } 
}
void merge_sort(int array[], int left, int right) {
	    if (left < right) {

        int m = left + (right - left) / 2;
 
        merge_sort(array, left, m);
        merge_sort(array, m + 1, right);
 
        merge(array, left, m, right);
    }
}

void execute_sort(char *sortType, int array[], int iteration, int size, int sortNums) {
	clock_t begin, end;
	double totalTime;
	
	printf("%s\n", sortType);
	for(int x = 0; x < iteration; x++) {
		randomArray(array, size);
		switch(sortNums) { // for each case begin the clock, execute the sort and end the clock
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
		totalTime = totalTime + ((double) (end - begin)) / CLOCKS_PER_SEC; // get time from beginning to end
	}
	printf("Took %f seconds to execute\n", totalTime);

}
int main(int argc, char * argv[]) { // print out the sort type and the amount of time taken to execute
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