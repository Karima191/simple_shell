"include "shell.h"

/**
* The shell program that takes user input, interprets commands,
* and executes them or performs specific actions.
*/

#define max_input_size 1050
#define max_path_size 1050
#define Y_OK  F_OK

extern char **environ;

/**
* The main function of the shell program.
* Accepts user input, interprets commands, and executes them.
*/
void execCmd(char *cmd);
void print_env(void);
void ProcessUserInput(char *input, char *path);

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

ProcessUserInput(input, path);
}
return (0);
}

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

fprintf(stderr, "This command is unfounded : % s\n ", cmd);
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, NULL, 0);
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
printf(" % s\n ", *env1);
env1++;
}
}

void ProcessUserInput(char *input, char *path)
{
char *tok = strtok(input, " ");
char cmdpath[max_path_size];
char *pathtok;
if (tok == NULL)
{
return;
}

if (strcmp(tok, "Exit") == 0)
{
printf("Exit the shell !...\n");
exit(exit_success);
}

if (strcmp(tok, "env") == 0)
{
print_env();
return;
}
pathtok = strtok(path, " : ");
while (pathtok != NULL)
{
snprintf(cmdpath, sizeof(cmdpath), " % s / % s ", pathtok, tok);
if (access(cmdpath, Y_OK) == 0)
{
execCmd(cmdpath);
return;
}
pathtok = strtok(NULL, " : ");
}
}

return (0);
}
