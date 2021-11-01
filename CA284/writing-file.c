#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]){
	
	int x;
	x = atoi(argv[1]);
	
	FILE * fpointer = fopen("tester2.txt", "w");

	fprintf(fpointer, "%d\n", x);

	fclose(fpointer);
	
	return 0;
}