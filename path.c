#include "shell.h"

#define max_input_size 1000
#define max_path_size 1000
#define wait

/**
* Function to execute a command
* This function takes a command as input
*and executes it using fork and execlp.
* It handles the cases where the fork fails or the command is not found.
*/

void execCmd(char *cmd)
{
pid_t pid = fork();

if (pid < 0)
{
perror("Fork is failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(cmd, cmd, (char *)NULL);

fprintf(stderr, "The command is not found:\n%s\n", cmd);
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, NULL, 0);
}
}

/**
* Main function
* This function reads user input, tokenizes it,
*checks for the command in the system's PATH,
*and executes the command if it exists.
*/

void ProcessUserInput(const char *input, const char *path)
{
char *token = strtok(input, " ");
if (token == NULL)
{
return;
}
char *pathcopy = strdup(path);
char *pathToken = strtok(pathcopy, ":");

char cmdPath[max_path_size];
while (pathToken != NULL)
{
snprintf(cmdPath, sizeof(cmdPath), "%s/%s", pathToken, token);
if (access(cmdPath, X_OK) == 0)
{
execCmd(cmdPath);
break;
}
pathToken = strtok(NULL, ":");
}
free(pathcopy);
}

int main(void)
{
char input[max_input_size];
char *path = getenv("PATH");

while (1)
{
printf("$\t");

if (fgets(input, max_input_size, stdin) == NULL)
{
break;
}

input[strcspn(input, "\n")] = '\0';

ProcessUserInput(input, path);
}
free(path);

return (0);
}
