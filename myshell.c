
// Code taken from lab sheets posted on the CA216 website + some additions from myself.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "utility.c"

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token sparators

int main (int argc, char ** argv)
{
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char ** arg;                               // working pointer thru args
	char * prompt = " >>> " ;				   // shell prompt
    char cwd[1024];

/* keep reading input until "quit" command or eof of redirected input */


	system("clear");
	
	printf("*******************\n\n\n");
	printf("WELCOME TO CONOR BRADYS SHELL\n\n");
	printf("HAVE FUN!\n\n\n");
	printf("*******************\n\n\n");
	
	sleep(2);


    while (!feof(stdin)) {

		getcwd(cwd, sizeof(cwd));
        /* get command line from input */
		printf("%s", cwd);
        fputs (prompt, stdout);                // write prompt
        if (fgets (buf, MAX_BUFFER, stdin )) { // read a line
            /* tokenize the input into args array */
            
            arg = args;
            *arg++ = strtok(buf,SEPARATORS);   // tokenize input
            while ((*arg++ = strtok(NULL,SEPARATORS)));
            // last entry will be NULL if (args[0]) {                     // if there's anything there

            /* check for internal/external command */
            if (!strcmp(args[0],"clr")) { // "clear" command
                system("clear");
                continue;
            }
			
			if (!strcmp(args[0],"help"))
			{
				command_help();
			}
			
			if (!strcmp(args[0],"environ"))
			{
				command_environ();
			}
			
			if (!strcmp(args[0],"pause"))
			{
				command_pause();
			}
			
			if (!strcmp(args[0],"cd"))
			{
				command_cd(args);
			}
			
			if (!strcmp(args[0],"echo"))
			{
				command_echo(args);
			}
			
			if (!strcmp(args[0],"dir"))
			{
				command_dir();
			}
			
			if (!strcmp(args[0],"ren"))
			{
				command_renaming();
			}
            
            if (!strcmp(args[0],"quit"))   // "quit" command
                break;                     // break out of 'while' loop

            /* else pass command onto OS (or in this instance, print them out) */

            arg = args;
            while (*arg) fprintf(stdout,"%s ",*arg++);
                fputs ("\n", stdout);
            }
        }
	return 0; 
}
