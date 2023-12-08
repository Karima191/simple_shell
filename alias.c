#include "shell.h"

extern char **environ;

void print_environ(void);

/**
*Function to print all the environment variables
*/
int main(void)
{
print_environ();
return (0);
}

/**
*Function to print all the environment variables stored in the 'environ' array.
*It iterates through the array and prints
*each variable until it encounters a NULL pointer
*/
void print_environ(void)
{
char **env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}
