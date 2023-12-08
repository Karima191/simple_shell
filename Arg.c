#include "shell.h"

/**
* This program takes command line arguments,
* converts them to integers, and then
* multiplies them together to compute the result.
**/

int main(int argc, char *argv[])
{
int i;
for (i = 0; i < argc; i++)
{
printf("argv[%i] :\t%s", i, argv[i]);
}
int rst = 1;
for (i = 1; i < argc; i++)
{
int w = strtol(argv[i], NULL, 10);
rst = rst *w;
}
printf("the result is %i\n", rst);
return (0);
}
