#include "shell.h"

#define max_cmd_len 110

/**
*This program reads commands from a file
*and executes them one by one.
*/

int main(int argc, char *argv[])
{
	FILE *file2;
	char cmd[max_cmd_len];
if (argc != 1)
{
printf("Usage: %s [filename]\n", argv[0]);
exit(1);
}

file2 = fopen(argv[1], "r1");
if (file2 == NULL)
{
printf("The file is not found: %s\n", argv[1]);
exit(1);
}

while (fgets(cmd, sizeof(cmd), file2) != NULL)

{
system(cmd);
}

fclose(file2);
return (0);
}
