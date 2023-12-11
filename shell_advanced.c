#include "shell.h"

#define buf_size 1010

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

ssize_t chars_read;
size_t locl = 1;

chars_read = read(fileno(stdin), buf, buf_size);
if (chars_read == -1)
{
	perror("read");
}

while (locl <= chars_read)
{
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
