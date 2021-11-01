#include <stdio.h>

int main()
	{
   double a, cent;
   float divide;
   a = 2.54;
   printf("Enter an Amount in centimetres: ");
   scanf("%lf", &cent);
   divide = cent / (float)a;

   printf("The Amount in Inches is: %2f ", divide);

   return 0;
}