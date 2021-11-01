#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char ** argv) {
  int num, i;

  int firstLargest = INT_MIN;  // Set first and second at the minimum
  int secondLargest = INT_MIN; // value possible for an int.
	if(argc < 2){
		printf("Insufficient arguments provided\n");
		exit(0);
  }
  for (i = 1; i < argc; i++) { 

    num = atoi(argv[i]); // converting string to interger


    if (num > firstLargest) { // moving the first interger
      secondLargest = firstLargest;
      firstLargest = num;
    } 
	else if(num < 0){
		printf("Error: only positive integers are permitted.\n");
		exit(0);
	}
	else if (num > secondLargest){ // Only keeping the second largest interger
      secondLargest = num;
  }
  }
  printf("%d\n", secondLargest); // Only printing the second largest integer
  return 0;
}