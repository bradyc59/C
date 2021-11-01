#include <stdio.h>

int main()
{
    int score, conversion, penalty, dropgoal, add, multiply;
    printf("Tries: ");
    scanf("%d", &score);
    printf("Conversions: ");
    scanf("%d", &conversion);
    printf("Penalties: ");
    scanf("%d", &penalty);
    printf("Drop Goals: ");
    scanf("%d", &dropgoal);

    multiply = (score * 5) + (conversion * 2) + (penalty * 3) + (dropgoal * 3);

    printf("The Score is: %d", multiply);

   return 0;
}