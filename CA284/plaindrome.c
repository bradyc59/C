#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char *words;
    bool isPalindrome;
    int i = 0;
    int j = 0;
    
    printf("please enter a word or sentence\n");
    
    /* Read into 'words' */
    scanf("%[^\n]%*c", words);
    
    /*  Parse the string and take all the white spaces
        out by treating
        'words' exactly like the array of characters it is.  */
    while (words[i] != '\0') {
        if (words[i] == ' ') {
            int k = i;
            while (words[k] != '\0') {
                words[k] = words[k+1];
                k++;
            }
        }
        else
            i++;
    }
    
    /*  the rest is a standard palindrome check in C */
    while (words[j] != '\0') {
        j++;
    }
    
    j--;
    i = 0;
    
    while (words[i+1] != '\0') {
        if (words[i] != words[j]) {
            isPalindrome = false;
            printf("no, that is not a palindrome\n");
            break;
        }
        i++;
        j--;
    }
    
    if (words[i+1] == '\0') {
        isPalindrome = true;
        printf("yes, that is a palindrome\n");
    }
        
    return 0;
}