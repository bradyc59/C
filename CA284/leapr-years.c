#include <stdio.h>

int leap(int startYear, int endYear)
{
	int i;
	for(i=startYear; i <= endYear; i++){ /* for each time after i starts at start year, increase it until it is less than or equal to end year*/
	
		if((i%400==0 && i%100==0 && i%4==0))/* if i divided by 4 has no left over and i divided by 100 has a left over and i divided by 400 has no leftover*/
		{
			printf("%d\n", i); /* print all numbers that are associated between the start and end year that pass through the if statement*/
		}
			
	}
}

int main(int argc, char*argv[]) /*brings in command line arguments*/
{
	int startYear, endYear;

	startYear = atoi(argv[1]); 
	endYear = atoi(argv[2]); /*converts start year and end year into intergers*/

	leap(startYear, endYear);

    return(0);
}