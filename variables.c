#include "shell.h"

/**
*This is the main function
*where the execution of the program begins.
*/

int main(void)
{
int variable1 = 50;
int Return_val;
pid_t pid;
printf("The variabl's value is: %i\n", variable1);

Return_val = system("ls -l");
if (Return_val == 0)
{
printf("The command is executed successfully.\n");
}
else
{
printf("Error command is failed to execute.\n");
}
pid = getpid();
printf("The process ID is: %i\n", pid);

return (0);
}
