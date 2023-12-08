#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_input_size 1010

/**
*This program demonstrates a simple shell implementation.
*It includes support for the built-in 'exit' command,
*allowing an optional status code input.
*/

int main(void)
{
char input[max_input_size];
int s = 0;

while (1)
{
printf("Shell $  ");
fgets(input, max_input_size, stdin);

char *tok = strtok(input, " \n");

if (strcmp(tok, "exit") == 0)
{
tok = strtok(NULL, " \n");

if (tok == NULL)
{
exit(s);
}
else
{
s = atoi(tok);
exit(s);
}
}
printf("the command is not recognized: %s\n", tok);
}

return (0);
}
