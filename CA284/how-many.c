#include <stdio.h>

int main (int argc,char *argv[])
{
    if(argc==3)
    {
        int i, frequency = 0;
        for(i = 0; argv[1][i]!= '\0'; ++i)
        {
            if(argv[1][i] == argv[2][0])
                ++frequency;
        }
        printf("%c occurs %d times\n", argv[2][0], frequency);

    }
    else
        printf("Invalid no of inputs\n");
    return 0;
}