#include "shell.h"

/**
* The shell program that takes user input, interprets commands,
* and executes them or performs specific actions.
*/

extern char **environ;

#define max_input_size 1050
#define max_path_size 1050
#define wait
#define Y_OK  F_OK

/**
* Execute a command using fork and execlp.
* @param cmd The command to execute.
*/

void execCmd(char *cmd)
{
pid_t pid = fork();

if (pid < 0)
{
perror("The Fork is failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(cmd, cmd, (char *)NULL);

fprintf(stderr, "This command is unfounded: %s\n", cmd);
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}

/**
* Print the environment variables.
*/

void print_env(void)
{
char **env1 = environ;
while (*env1 != NULL)
{
printf("%s\n", *env1);
env1++;
}
}

/**
* The main function of the shell program.
* Accepts user input, interprets commands, and executes them.
*/

int main(void)
{
char input[max_input_size];
char *path = getenv("PATH");

while (1)
{
printf("$ ");

if (fgets(input, max_input_size, stdin) == NULL) {
break;
}

input[strcspn(input, "\n")] = '\0';

char *tok = strtok(input, " ");
if (tok == NULL)
{
continue;
}

if (strcmp(tok, "Exit") == 0)
{
printf("Exit the shell!...\n");
break;
}

if (strcmp(tok, "env") == 0)
{
print_env();
continue;
}

char cmdpath[max_path_size];
char *pathtok = strtok(path, " : ");
while (pathtok != NULL)
{
snprintf(cmdpath, sizeof(cmdpath), "%s/%s", pathtok, tok);
if (access(cmdpath, Y_OK) == 0)
{
execCmd(cmdpath);
break;
}
pathtok = strtok(NULL, ":");
}
}

return (0);
}
