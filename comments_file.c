#include "shell.h"

/**
*This program reads a file line by line, ignoring lines starting with '#'
*/
int main(void)
{
char ln[110];
FILE *file2 = fopen(" your_file2 - name.txt is : ", "r");

if (file2 == NULL)
{
printf("Error the file not openning.\n");
return (1);
}

while (fgets(ln, sizeof(ln), file2))
{
if (ln[0] == '#')
{
continue;
}
printf("%s", ln);
}

fclose(file2);
return (0);
}
