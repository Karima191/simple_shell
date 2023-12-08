#include "shell.h"

/**
*This is the main function
*where the execution of the program begins.
*/

int main(void)
{
int variable1 = 50;
printf("The variabl's value is: %i\n", variable1);

int return_val = system("ls -l");
if (return_val == 0)
{
printf("The command is executed successfully.\n");
}
else
{
printf("Error command is failed to execute.\n");
}
pid_t pid = getpid();
printf("The process ID is: %i\n", pid);

return (0);
}
