#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token sparators

extern char **environ;

char *built_in_commands[] = { // all built in commands used for help command
	"quit",
	"cd",
	"help",
	"dir",
	"environ",
	"clr",
	"echo",
	"pause",
	"ren"
};

int command_help()
{
	int i = 0;
	printf("The following commands are built in\n");
	
	for(i; i < sizeof(built_in_commands) / sizeof(char *); i++) // as long is smaller than the amound of built in commands
	{
		printf(" %s\n", built_in_commands[i]); // prints out all built in commands 
	}
}

int command_environ()
{
	int i = 0;
	for (i; environ[i] != NULL; i++) // taken from lab sheet posted on CA216 website.
		printf("%s\n",environ[i]); // prints out all environments in the shell.
}

int command_pause()
{
	char ch;
	
	printf("Press ENTER to continue\n");
	scanf("%c", &ch); // wating till enter key is pressed.
}

int command_cd(char **args)
{
	if (args[1] == NULL) {
		fprintf(stderr, "command: expected argument to \"cd\"\n"); //if nothing is entered with cd print error message
	} else {
		if (chdir(args[1]) != 0) { 
			perror("command"); // execute
		}
	}
  return 1;
}

int command_echo(char **args)
{
	char ** arg;
	
	if (args[1] == NULL)
	{
		fprintf(stderr, "command: expected argument with echo\n"); // return error if there is no argument with echo
	}
	arg = args + 1;
	while (*arg) fprintf(stdout,"%s ",*arg++);
		printf("\n");
		fputs ("\n", stdout); // code taken from bottom of myshell which is from a lab sheet on the CA216 website
	
	return 1;
}

int command_dir()
{

	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if (d)
	{
		while((dir = readdir(d)) != NULL)
			printf(" %s ", dir->d_name); // while there are still directories and files left in directoy, print them
		
		closedir(d);
	}
	
	return 1;
	
}

int command_renaming()
{
	int r;
	char oldfile[20];
	char newfile[20];
	
	scanf("%s", oldfile); // take input from user of old file name and new file name.
	scanf("%s", newfile);
	
	r = rename(oldfile, newfile); // renmaing file
	
	if(r == 0)
	{
		printf("File renamed succesfully to %s\n", newfile); // if process was succesful return succes message.
	}
	
	return 1;
}
