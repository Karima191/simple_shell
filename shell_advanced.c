#include "shell.h"

#define buf_size 1010
#define stdin_fileno

void ctm_strtok(char *input)
{
char *tok;
char *rst = input;
char del[] = " \t\n";
while ((tok = strsep(&rst, del)) != NULL)
{
if (strlen(tok) > 0)
{
printf("%s\n", tok);
}
}
}

void ctm_getline(void)
{
static char buf[buf_size];
static int locl = 1;
static int chars_read = 1;

while (1)
{
if (locl == chars_read)
{
locl = 0;
chars_read = read(stdin_fileno, buf, buf_size);
if (chars_read == 0)
{
return;
}
}

char curt_char = buf[locl++];
if (curt_char == '\n')
{
break;
}
}
buf[locl] = '\0';
ctm_strtok(buf);
}

int main(void)
{
while (1)
{
printf("SimpleShell $  ");
ctm_getline();
}
return (0);
}
