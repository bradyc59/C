#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

// Helper funcs
int generateArray(int arr[], int size) {
    // Create new seed for rand
    srand(time(NULL));
    // populate with random integers
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            arr[i] = rand() % size + 1;
        } else {
            arr[i] = (rand() % size + 1) * -1;

        }
    }
}

void swap(int *xp, int *yp) {
    // Swap two elements
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int partition(int arr[], int low, int high) { 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // create temp arrays 
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    //Copy the remaining elements of R[], if there are any 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// Sorting funcs
// https://www.geeksforgeeks.org/selection-sort/
void selectionSort(int arr[], int n) { 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
}

// https://www.geeksforgeeks.org/bubble-sort/
void bubbleSort(int arr[], int n) { 
    int i, j; 
    bool swapped; 
    for (i = 0; i < n-1; i++) { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) { 
        if (arr[j] > arr[j+1]) { 
           swap(&arr[j], &arr[j+1]); 
           swapped = true; 
        } 
     } 
    
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
    } 
              
              
} 

// https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(int arr[], int n) { 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 


void executeSort(char *sortName, int arr[], int iterations, int size, int sortNum) {
    clock_t start, end;
    double totalClockTime;
    
    printf("%s \n", sortName);
    for (int i = 0; i < iterations; i++) {
        generateArray(arr, size);
        switch(sortNum) {
            case 0: 
                start = clock();
                selectionSort(arr, size);
                end = clock();
                break;
            case 1: 
                start = clock();
                bubbleSort(arr, size);
                end = clock();
                break;
            case 2: 
                start = clock();
                insertionSort(arr, size);
                end = clock();
                break;

        }
        
        totalClockTime = totalClockTime + ((double) (end - start)) / CLOCKS_PER_SEC;

    }
    printf("took %f seconds to execute \n", totalClockTime); 
    printf("\n");
}


int main(int argc, char **argv) {
    int SIZE = atoi(argv[1]);
    int ITERATIONS = atoi(argv[2]);
    
    char SS_STR[20] = "SELECTION SORT";
    char BS_STR[20] = "BUBBLE SORT";
    char IS_STR[20] = "INSERTION SORT";

    // Initalise all arrays we need of length argv 
    // & populate each with random integers
    int selectionSortArr[SIZE];
    int bubbleSortArr[SIZE];
    int insertionSortArr[SIZE];

    executeSort(SS_STR, selectionSortArr, ITERATIONS, SIZE, 0);
    executeSort(BS_STR, bubbleSortArr, ITERATIONS, SIZE, 1);
    executeSort(IS_STR, insertionSortArr, ITERATIONS, SIZE, 2);

}
