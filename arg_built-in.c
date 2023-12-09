#include "shell.h"

#define max_input_size 1010

/**
*This program demonstrates a simple shell implementation.
*It includes support for the built-in 'exit' command,
*allowing an optional status code input.
*/

int main(void)
{
char input[max_input_size];
char *tok;
int s = 0;

while (1)
{
printf("Shell $  ");

fgets(input, max_input_size, stdin);

char *tok = strtok(input, " \n");

if (tok == NULL)
{
	continue;
}
if (strcmp(tok, "exit") == 0)
{
tok = strtok(NULL, " \n");
if (tok != NULL)
{
	s = atoi(tok);
}
exit(s);
}
else
{
printf("the command is not recognized: %s\n", tok);
}
}

return (0);
}
