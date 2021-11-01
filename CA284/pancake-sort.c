#include<stdio.h>
#include<stdlib.h>

void flip(int array[], int x)
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
 

int findMax(int array[], int n)
{
    int mi, i;
    for (mi = 0, i = 0; i < n; ++i)
        if (array[i] > array[mi])
            mi = i;
    return mi;
}

void pancake_sort(int* array, int n){

    for (int curr_size = n; curr_size > 1; --curr_size) 
    {
        int mi = findMax(array, curr_size);

        if (mi != curr_size - 1) {
            flip(array, mi);
            flip(array, curr_size - 1);
        }
    }
}
