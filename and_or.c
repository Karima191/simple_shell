#include "shell.h"

#define max_length 1010

/**
*Function to execute a command
*/

void exec_cmd(char *arg[])
{
pid_t pid = fork();
if (pid < 0)
{
fprintf(stderr, "Error the fork is failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execvp(arg[0], arg) == -1)
{
perror("There is an error in execution");
}
exit(EXIT_FAILURE);
}
else
{
int s;
waitpid(pid, &s, 0);
if (WIFEXITED(s) && WEXITSTATUS(s) != 0)
{
printf("This command is failed\n");
}
}
}

/**
*Function to execute parallel commands
*/
void par_exec(char *ln)
{
char *arg[max_length / 2];
char *tok = strtok(ln, " \n");
int x = 0;
while (tok != NULL)
{
arg[x] = tok;
tok = strtok(NULL, " \n");
x++;
}
arg[x] = NULL;
exec_cmd(arg);
}

/**
*Function to read user input
*/

void read_input(char *ln)
{
printf("Shell $$ ");
fflush(stdout);
fgets(ln, max_length, stdin);
}

/**
* Main function for the shell program.
* Reads user input, checks for the "exit" command
* to terminate the program,
* and executes the user-entered commands
* in parallel using par_exec function.
*/
int main(void)
{
char ln[max_length];
int shld_r1 = 1;

while (shld_r1)
{
read_input(ln);
if (strcmp(ln, "exit\n") == 0)
{
shld_r1 = 0;
break;
}
par_exec(ln);
}

return (0);
}
