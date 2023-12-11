#include "shell.h"

/**
*Function to set an environment variable
*Print error message if the arguments are missing
*Print error message if setting the environment variable fails
*/
int set_env1(char *var, char *val)
{
if (var == NULL || val == NULL)
{
fprintf(stderr, "Sentax: setenv VARIABLE VALUE\n");
return (-1);
}
if (setenv(var, val, 1) != 0)
{
perror("set_env");
return (-1);
}
return (0);
}

/**
*Function to unset an environment variable
*Print error message if the argument is missing
*Print error message if unsetting the environment variable fails
*/

int set_env2(char *var)
{
if (var == NULL)
{
fprintf(stderr, "Sentax: unsetenv VARIABLE\n");
return (-1);
}
if (unsetenv(var) != 0)
{
perror("unsetenv");
return (-1);
}
return (0);
}

/**
*Main function
*Getting the command from the user
*Checking the command and executing the corresponding function
*Print error message if the entered command is invalid
*/
int main(void)
{
char cmd[110];
char *var, *val;

printf("Please enter the command: ");
fgets(cmd, sizeof(cmd), stdin);

if (strcmp(cmd, "setenv") == 0)
{
var = strtok(NULL, " \n");
val = strtok(NULL, " \n");
set_env1(var, val);
}
else if (strcmp(cmd, "unsetenv") == 0)
{
var = strtok(NULL, " \n");
set_env2(var);
}
else
{
fprintf(stderr, "Invalid command\n");
}
return (0);
}
