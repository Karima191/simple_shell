#include "shell.h"

/**
*Main function for the simple shell
*Reading the command from the user
*Removing the trailing newline character
*Tokenizing the input command using semicolon as the delimiter
*Executing the command using system call
*Moving to the next command token
*/

int main(void)
{
while (1)
{
char cmd[110];
printf("Please enter your command : ");
fgets(cmd, sizeof(cmd), stdin);
cmd[strcspn(cmd, "\n")] = 0;
char *tok = strtok(cmd, ";");
while (tok != NULL)
}
if (strcmp(tok, "exit") == 0)
{
printf("Exiting the shell...\n");
exit(0);
}
system(tok);
tok = strtok(NULL, ";");
}
}
return (0);
}
