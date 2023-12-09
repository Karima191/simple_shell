#include "shell.h"

<<<<<<< HEAD
#define max_input_size 1000
#define max_path_size 1000
=======
#define max_input_size 1010
#define max_path_size 1010
>>>>>>> 3595ffee3aa25c499e2760c8613e4d59e51ed446
#define wait

/**
* Function to execute a command
* This function takes a command as input
*and executes it using fork and execlp.
* It handles the cases where the fork fails or the command is not found.
<<<<<<< HEAD
*/

=======
**/
>>>>>>> 3595ffee3aa25c499e2760c8613e4d59e51ed446
void execCmd(char *cmd)
{
pid_t pid = fork();
if (pid < 0)
{
<<<<<<< HEAD
perror("Fork is failed");
=======
perror("Error fork is failed");
>>>>>>> 3595ffee3aa25c499e2760c8613e4d59e51ed446
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(cmd, cmd, (char *)NULL);
<<<<<<< HEAD
fprintf(stderr, "The command is not found:\n%s\n", cmd);
=======
fprintf(stderr, "This command is not found:\n%s\n", cmd);
>>>>>>> 3595ffee3aa25c499e2760c8613e4d59e51ed446
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
<<<<<<< HEAD
}
=======
>>>>>>> 3595ffee3aa25c499e2760c8613e4d59e51ed446
/**
* Main function
* This function reads user input, tokenizes it,
* checks for the command in the system's PATH,
*and executes the command if it exists.
* The function also checks if the user inputs
* the 'exit' command, in which case it terminates the shell.
**/
int main(void)
{
char input[max_input_size];
char *path = getenv("PATH");
int exitFlag = 0;
while (!exitFlag)
{
printf("$\t");
if (fgets(input, max_input_size, stdin) == NULL)
{
break;
}

input[strcspn(input, "\n")] = '\0';
if (strcmp(input, "exit") == 0)
{
exitFlag = 1;
printf("Exiting the shell!...\n");
}
else
{
char *token = strtok(input, " ");
if (token == NULL)
{
continue;
}
char cmdPath[max_path_size];
char *pathToken = strtok(path, ":");

while (pathToken != NULL)
{
snprintf(cmdPath, sizeof(cmdPath), "%s / %s", pathToken, token);
if (access(cmdPath, W_OK) == 0)
{
execCmd(cmdPath);
break;
}
pathToken = strtok(NULL, ":");
}
}
return (0);
}
