#include "shell.h"

#define max_input_size 1010
#define stdin_fileno
#define wait

/**
*Function to read the input from the user
*/

char *first_getline(void)
{
if (buf_idx >= buf_size)
{
buf_size = read(stdin_fileno, buf, max_input_size);
if (buf_size <= 0)
{
return (NULL);
}
buf_idx = 0;
}

char *nline_ptr = strchr(buf + buf_idx, '\n');
if (nline_ptr != NULL)
{
*nline_ptr = '\0';

int line_length = nline_ptr - (buf + buf_idx);

char *line = malloc(line_length + 1);
strncpy(line, buf + buf_idx, line_length);
line[line_length] = '\0';

buf_idx += line_length + 1;

return (line);
}

char *line = strdup(buf + buf_idx);
buf_idx = buf_size;
return (line);
}

/**
* Function to execute the command provided by the user
*/

void execCmd(char *cmd)
{
pid_t pid = fork();

if (pid < 0)
{

perror("Error the fork is failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(cmd, cmd, (char *)NULL);

fprintf(stderr, "the command is not found: %s\n", cmd);
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}

/**
* Main function to run the shell
**/

int main(void)
{
while (1)
{
printf("$   ");

char *input = first_getline();

if (input == NULL)
{
printf("\nExiting the shell!...\n");
break;
}

if (strlen(input) == 0)
{
free(input);
continue;
}

execCmd(input);

free(input);
}

return (0);
}
