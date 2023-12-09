#include "shell.h"

extern char **envi;

#define max_input_size 1010
#define max_path_size 1010
#define wait

Certainly, I'll provide detailed explanations within
the /**/ for better understanding:

c
Copy code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **envi;

#define max_input_size 1010
#define max_path_size 1010
#define wait

/**
* Function to execute the given command
*
* This function takes a string 'cmd' as input and
*creates a child process using 'fork()'.
* If the 'fork()' fails, it displays an error message and exits.
* If the 'fork()' is successful,
*the child process executes the command using 'execlp()'.
* If the command is not found, it prints an error message and exits.
* The parent process waits for the child process to finish using 'wait()'.
*/

void execCmd(char *cmd)
{
pid_t pid = fork();
if (pid < 0)
{
perror("Error the fork is failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(cmd, cmd, (char *)NULL);

fprintf(stderr, "This Command not found: %s\n", cmd);
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
/**
* Function to print environment variables
*
* This function prints all the environment variables using a while loop.
*/

void printenvi()
{
char **envi = environ;
while (*envi != NULL) {
printf("%s\n", *envi);
envi++;
}
}
/**
* Main function
*
* This function initializes variables, reads user input,
*and processes the input accordingly.
* It displays a prompt, reads the input,
*and removes any newline characters from it.
* It then tokenizes the input and executes commands based on the user's input.
* The program continuously executes
* until the user types "exit" to terminate the shell.
*/
int main(void)
{
char input[max_input_size];
char *path = getenv("PATH");

while (1)
{
printf("$ ");
if (fgets(input, max_input_size, stdin) == NULL)
{
break;
}
input[strcspn(input, "\n")] = '\0';

char *token = strtok(input, " ");
if (token == NULL)
{
continue;
}
if (strcmp(token, "exit") == 0)
{
printf("Exiting the shell!...\n");
break;
}
if (strcmp(token, "envi") == 0)
{
printenvi();
continue;
}
char cmdPath[max_path_size];
char *pathToken = strtok(path, ":");
while (pathToken != NULL)
{
snprintf(cmdPath, sizeof(cmdPath), "%s/%s", pathToken, token);
if (access(cmdPath, W_OK) == 0)
{
execCmd(cmdPath);
break;
}
pathToken = strtok(NULL, ":");
}
return (0);
}