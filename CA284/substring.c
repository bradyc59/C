#include<stdio.h>
#include <ctype.h>

 
int main()
{
    char str[50], search[10];
    int count1 = 0, count2 = 0, i, j, flag;
 
    printf("Enter the first string: \n");
    fgets(str, sizeof str, stdin);
    printf("Enter the second string: \n");
    fgets(search, sizeof search, stdin);
    while (str[count1] != '\0')
        count1++;
    while (search[count2] != '\0')
        count2++;
    for (i = 0; i <= count1 - count2; i++)
    {
        for (j = i; j < i + count2; j++)
        {
            flag = 1;
            if (str[j] != search[j - i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 1)
        printf("The string '%s' is contained in the string '%s'.\n",search, str);
    else
        printf("The string '%s' is not contained in the string '%s'.\n", search, str);
    return 0;
}