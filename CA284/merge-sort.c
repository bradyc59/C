#include<stdio.h>
#include<stdlib.h>

// https://www.edureka.co/blog/merge-sort-in-c/
void merge(int array[], int l, int m, int r) {
	int x, y, z;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1], R[n2];
	
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

void merge_sort(int array[], int left, int right) {
	    if (left < right) {

        int m = left + (right - left) / 2;
 
        merge_sort(array, left, m);
        merge_sort(array, m + 1, right);
 
        merge(array, left, m, right);
    }
}